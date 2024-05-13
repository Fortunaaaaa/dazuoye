#include "pickypurcharacter.h"
#include "character.h"
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include "mybutton.h"

pickypurcharacter::pickypurcharacter(QWidget *parent)
    : QMainWindow{parent}
{
    //设置固定大小
    setFixedSize(1200,750);
    //设置标题
    setWindowTitle("pick ypur character");
    //创建返回按钮
    /*mybutton * backbtn = new mybutton("://tupian2/back.jpg");
    backbtn->setParent(this);
    backbtn->move(this->width()*0.45,this->height()*0.55);

    //发送信号需要返回
    connect(backbtn,&mybutton::clicked,this,[=](){
        //qDebug()<<"点击了返回";
        backbtn->zoom1();
        backbtn->zoom2();
        //延时进入到选择人物场景
        //QTimer::singleShot(500,this,[=](){
        emit this->choosesceneback();
         });*/

//创建角色
    //罗小白
    character * xiaobai = new character("://tupian2/girl1-study.png","://tupian2/girl1-cheating-better.png");
    xiaobai->setParent(this);
    xiaobai->move(this->width()*0.005,this->height()*0.25);

    //山新
    character * shanxin = new character("://tupian2/girl2-study.png","://tupian2/girl2-cheating.png");
    shanxin->setParent(this);
    shanxin->move(this->width()*0.25,this->height()*0.25);

    //男生1
    character * nansheng1 = new character("://tupian2/boy1-study.png","://tupian2/boy3-cheating.png");
    nansheng1->setParent(this);
    nansheng1->move(this->width()*0.5,this->height()*0.25);

    //男生2
    character * nansheng2 = new character("://tupian2/boy2-study.png","://tupian2/boy4-cheating.png");
    nansheng2->setParent(this);
    nansheng2->move(this->width()*0.75,this->height()*0.25);


    //创建按钮
    mybutton * a=new mybutton("://tupian2/xiaobaianniu.png");
    a->setParent(this);
    a->move(this->width()*(-0.08),this->height()*0.68);

    mybutton * b=new mybutton("://tupian2/shanxinanniu.png");
    b->setParent(this);
    b->move(this->width()*0.18,this->height()*0.72);

    mybutton * c=new mybutton("://tupian2/zccanniu.png");
    c->setParent(this);
    c->move(this->width()*0.45,this->height()*0.71);

    mybutton * d=new mybutton("://tupian2/mtjjanniu.png");
    d->setParent(this);
    d->move(this->width()*0.69,this->height()*0.71);



    //这里点击之后没办法切换界面？why？？
    connect(a,&mybutton::clicked,this,[=](){
        //进入到ready场景
        a->zoom1();
        a->zoom2();
        ready = new readyscene(1);
        this->hide();
        ready->show();
    });

    connect(b,&mybutton::clicked,this,[=](){
        //进入到ready场景
        b->zoom1();
        b->zoom2();
        ready = new readyscene(2);
        this->hide();
        ready->show();
    });

    connect(c,&mybutton::clicked,this,[=](){
        //进入到ready场景
        c->zoom1();
        c->zoom2();
        ready = new readyscene(3);
        this->hide();
        ready->show();
    });

    connect(d,&mybutton::clicked,this,[=](){
        //进入到ready场景
        d->zoom1();
        d->zoom2();
        ready = new readyscene(4);
        this->hide();
        ready->show();
    });

    //没办法切换到下一个界面，重新定义自己的信号和槽函数？



 }


void pickypurcharacter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://tupian2/chooserenwu2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
