#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include<QTimer>
namespace Ui {
class MW1;
}

class MW1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void moveMonster();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    int canGoleft();
    int canGoright();
    int canGoup();
    int canGodown();

private:
    Ui::MW1 *ui;
    World _game;
    QTimer *timer;
};

#endif // MW1_H
