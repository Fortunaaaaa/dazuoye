#ifndef READYSCENE_H
#define READYSCENE_H


#include <QMainWindow>
#include "youxijiemian.h"
#include<QPainter>
//#include<QMovie>
//#include<QLabel>

class readyscene : public QMainWindow
{
    Q_OBJECT
public:
   // explicit readyscene(QWidget *parent = nullptr);
    //重写构造函数，带一个参数表示选择的人物是谁

    readyscene(int renwu);
    int renwuIndex;//内部成员属性，记录所选择的人物

    //重写paintevent事件 画背景图
    void paintEvent(QPaintEvent*);

    //动画
   // QMovie readygo;
    //QLabel * kaishidonghua;

    //int dingshiqi;

    youxijiemian * playjiemian = nullptr;

//protected:
    //定时器事件，为虚函数
   // void timerEvent(QTimerEvent*e);

signals:
};

#endif // READYSCENE_H
