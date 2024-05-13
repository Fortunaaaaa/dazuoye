#include "readyscene.h"
#include"mybutton.h"
#include<QPainter>
#include<QTimer>
#include<QDebug>

//readyscene::readyscene(QWidget *parent)
//    : QMainWindow{parent}
//{}


readyscene::readyscene(int renwu)
{
    //qDebug()<<renwu;
    this->renwuIndex=renwu;

    //设置固定大小
    setFixedSize(1200,750);
    //设置标题
    setWindowTitle("ready?????");
    //yes按钮
    mybutton * yesbtn = new mybutton("://tupian2/blueyes.jpg");
    yesbtn->setParent(this);
    yesbtn->move(this->width()*0.48,this->height()*0.63);

    //点击开始按钮切换到下一界面
    connect(yesbtn,&mybutton::clicked,this,[=](){

        yesbtn->zoom1();
        yesbtn->zoom2();
/*
        //启动动画
        kaishidonghua->show();
        readygo.start();
        //启动定时器
        dingshiqi=startTimer(2000);
 */
       //延时进入到选择人物场景
        QTimer::singleShot(500,this,[=](){
            //进入到游戏场景中,先隐藏自己
            this->hide();
            //qDebug()<<"成功hide";
            //实例化游戏界面的场景
            playjiemian = new youxijiemian(renwu);//这里有问题 why？？？
            //qDebug()<<"成功实例化";
            playjiemian->show();
            //qDebug()<<"成功show";
        });
    }
            );


}

void readyscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://tupian2/background3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}


