#ifndef YOUXIJIEMIAN_H
#define YOUXIJIEMIAN_H


#include <QMainWindow>
#include<QPainter>
#include<QProgressBar>
#include<QMovie>
#include<QLabel>
#include<QImage>
#include <QWidget>
#include "character.h"
#include <QPropertyAnimation>
#include "win.h"
#include "loose.h"


class youxijiemian : public QMainWindow
{
    Q_OBJECT
public:
    //explicit youxijiemian(QWidget *parent = nullptr);
    youxijiemian (int choosedrenwu);//重写构造函数
    //输赢界面的创建
    win * winthegame=nullptr;
    loose * loosethegame =nullptr;
    //生成随机数
    int getRandom();
    //创建人物
    int xuanzerenwu;
    character *characterrrrr =nullptr;
    //作弊次数
    int zuobicishu;
    //显示点击次数的qlabel
    QLabel * xianshidianjicishu=nullptr;
    QLabel * wenzi=nullptr;
    //character的左右的横坐标
    int left;
    int right;
    //重写paintevent事件 画背景图
    void paintEvent(QPaintEvent*);
    int gametime;//游戏时间
    int gametimeID;//游戏时间定时器id
    int laoshizouluid;//老师走路计时器id
    int panduanzantingid;//时刻判断游戏是否暂停
    int dingshiqiyanshi;//延时启动
    int randint;//随机数
    QProgressBar * progressbar = nullptr;//进度条
    //设置动画
    QPropertyAnimation *m_animation=new QPropertyAnimation(this);
    //设置老师指针
    QLabel * laoshi = nullptr;
    //老师位置
    int xxxlaoshi;
    //老师状态 ringt-1,left-0
    int laoshizhuangtai=1;
    //移动函数
    void moveimage(QLabel*laoshi,int xnow,int mubiaoweizhi);
    //是否可以看到作弊
    int shifoukeyikandaozuobi(int left,int right);
protected:
    //定时器事件，为虚函数
    void timerEvent(QTimerEvent*e);
signals:
};


#endif // YOUXIJIEMIAN_H
