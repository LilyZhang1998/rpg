#include "world.h"
#include "icon.h"

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(5);
    this->_player.setPosY(5);
    this->die=false;
    //stone 4 5
    this->_monster.initObj("monster");
    this->_monster.setPosX(10);
    this->_monster.setPosY(10);

    RPGObj obj1, obj2, obj3,obj4,obj5;
    obj1.initObj("stone");
    obj1.setPosX(4);
    obj1.setPosY(3);

    obj2.initObj("stone");
    obj2.setPosX(6);
    obj2.setPosY(5);

    obj3.initObj("fruit");
    obj3.setPosX(6);
    obj3.setPosY(8);

    obj4.initObj("tree");
    obj4.setPosX(12);
    obj4.setPosY(12);

    obj5.initObj("well");
    obj5.setPosX(18);
    obj5.setPosY(8);

    this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);
    this->_objs.push_back(obj4);
    this->_objs.push_back(obj5);

    label.setText("Game over!");


}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    this->_monster.show(painter);
    if(!die)
        this->_player.show(painter);
    else
       label.show();
}

void World::handlePlayerMove(int direction, int steps){
    this->_player.move(direction, steps);
}
void World::killPlayer(){
    this->die=true;
}

void World::changeMonster()
{
  if(_monster.getPosX()<20)
      _monster.move(4,1);
   else
    _monster.move(3,1);
}
