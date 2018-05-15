#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"

#include <map>
#include <iostream>

using namespace std;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);

    //init game world
    _game.initWorld("");//TODO 应该是输入有效的地图文件

    timer=new QTimer;

    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveMonster()));
   // timer->setInterval(1000);


}

MW1::~MW1()
{
    delete ui;
}
void MW1::moveMonster(){
    _game.changeMonster();
   this->update();
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_game.show(pa);
    pa->end();
    delete pa;
}
/*void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    this->_player.show(painter);
}*/

int MW1::canGoleft(){
     vector<RPGObj>::iterator it;
     for(it=this->_game.getObjsBegin();it!=this->_game.getObjsEnd();it++){
            if(_game.getPlayerX()==(*it).getPosX()+(*it).getWidth()){
                if(((*it).getPosY()-_game.getPlayerY())>0){
                    if(((*it).getPosY()-_game.getPlayerY())<(*it).getHeight())
                    {
                       if((*it).canEat()){
                          _game.remove(it);
                          return 1;

                       }
                       else if(_game.getType(it)=="well"){
                           _game.killPlayer();
                         return 0;
                       }
                       return 0;
                    }
                }
            else if((_game.getPlayerY()-(*it).getPosY())<_game.getPlayerHeight())
                    {
                        if((*it).canEat()){
                            _game.remove(it);
                            return 1;

                        }
                        else if(_game.getType(it)=="well"){
                            _game.killPlayer();
                                return 0;
                        }
                        return 0;
                    }
            }
       }
       return 1;
}
int MW1::canGoright(){
    vector<RPGObj>::iterator it;
    for(it=this->_game.getObjsBegin();it!=this->_game.getObjsEnd();it++){
        if(_game.getPlayerX()+_game.getPlayerWidth()==(*it).getPosX()){
               if(((*it).getPosY()-_game.getPlayerY())>0){
                   if(((*it).getPosY()-_game.getPlayerY())<(*it).getHeight()){
                       if((*it).canEat()){
                           _game.remove(it);
                           return 1;

                           }
                       else if(_game.getType(it)=="well"){
                           _game.killPlayer();
                         }  return 0;

               return 0;
           }
               }

          else if((_game.getPlayerY()-(*it).getPosY())<_game.getPlayerHeight()){
               if((*it).canEat()){
                   _game.remove(it);
                   return 1;
               }
               else if(_game.getType(it)=="well"){
                   _game.killPlayer();
                   return 0;

                 }
               return 0;
               }
        }
     }

   return 1;
}
int MW1::canGoup(){
    vector<RPGObj>::iterator it;
    for(it=this->_game.getObjsBegin();it!=this->_game.getObjsEnd();it++){
        if(_game.getPlayerY()+(*it).getHeight()==(*it).getPosY()){
            if(((*it).getPosX()-_game.getPlayerX())>0){
                if(((*it).getPosX()-_game.getPlayerX())<_game.getPlayerWidth()){
                     if((*it).canEat()){
                         _game.remove(it);
                         return 1;
                     }
                     else if(_game.getType(it)=="well"){
                         _game.killPlayer();
                         return 0;

             }
                     return 0;
                    }
            }
            else if(_game.getPlayerX()-(*it).getPosX()<(*it).getWidth()){
                 if((*it).canEat()){
                     _game.remove(it);
                     return 1;
                 }
                 else if(_game.getType(it)=="well"){
                     _game.killPlayer();
                     return 0;

         }
                 return 0;
            }
        }
     }
    return 1;
}
int MW1::canGodown(){
    vector<RPGObj>::iterator it;
    for(it=this->_game.getObjsBegin();it!=this->_game.getObjsEnd();it++){
        if(_game.getPlayerY()==(*it).getPosY()+_game.getPlayerHeight()){
            if(((*it).getPosX()-_game.getPlayerX())>0){
                if(((*it).getPosX()-_game.getPlayerX())<_game.getPlayerWidth())
                {
                     if((*it).canEat()){
                         _game.remove(it);
                         return 1;
                     }
                     else if(_game.getType(it)=="well"){
                         _game.killPlayer();
                         return 0;

             }
                     return 0;
                }
            }
            else if(_game.getPlayerX()-(*it).getPosX()<(*it).getWidth()){
                 if((*it).canEat()){
                     _game.remove(it);
                     return 1;
                 }
                 else if(_game.getType(it)=="well"){
                     _game.killPlayer();
                     return 0;

         }
                 return 0;
            }
        }
    }
    return 1;
}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    vector<RPGObj>::iterator it;
    if(e->key() == Qt::Key_A)
    {
       if(canGoleft())
            this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        if(canGoright())
            this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        if(canGoup())
            this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
        if(canGodown())
            this->_game.handlePlayerMove(2,1);
    }
    this->repaint();
}
