#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"
#include<QLabel>
#include <QDialog>

class World
{

public:
    World(){}
    ~World(){}
    void initWorld(string mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
           tree 12 12
         */
    void show(QPainter * painter);
        //显示游戏世界所有对象
    void handlePlayerMove(int direction, int steps);
        //假定只有一个玩家
    void changeMonster();
    int getPlayerX(){return _player.getPosX();}
    int getPlayerY(){return _player.getPosY();}
    int getPlayerHeight(){return _player.getHeight();}
    int getPlayerWidth(){return _player.getWidth();}
    vector<RPGObj>::iterator getObjsBegin(){return this->_objs.begin();}
    vector<RPGObj>::iterator getObjsEnd(){return this->_objs.end();}
    void remove(vector<RPGObj>::iterator it){_objs.erase(it);}
    string getType (vector<RPGObj>::iterator it)const{return (*it).getObjType();}
    void killPlayer();
private:
    vector<RPGObj> _objs;
    Player _player;
    Player _monster;
    bool die;
    QLabel label;

};

#endif // WORLD_H
