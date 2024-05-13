#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"mybutton.h"
#include<QPainter>
#include<QDebug>
#include<QPropertyAnimation>
#include<QTimer>
#include<QtGlobal>

\

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置固定大小
    setFixedSize(1200,750);
    //设置标题
    setWindowTitle("罗小白的期末考试");

    //开始按钮
    mybutton * startbtn = new mybutton(":/tupian2/start.jpg");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.58,this->height()*0.75);

    //游戏说明按钮
    mybutton * shuomingtbtn = new mybutton("://tupian2/youxishuom.jpg");
    shuomingtbtn->setParent(this);
    shuomingtbtn->move(this->width()*(-0.18),this->height()*0.77);


    //实例化选择人物的场景和游戏说明的场景
    p = new pickypurcharacter;
    y = new youxishuoming;

    //监听选择人物的返回按钮的信号
   // connect(p,&pickypurcharacter::choosesceneback(),this,[=](){
     //   p->hide();
     //   this->show();//重新显示主场景
    //});


    //点击开始按钮切换到下一界面
    connect(startbtn,&mybutton::clicked,[=](){

                //qDebug()<<"点击了开始";

                startbtn->zoom1();
                startbtn->zoom2();

                //延时进入到选择人物场景
                QTimer::singleShot(500,this,[=](){
                    //进入到选择人物的场景中,先隐藏自己
                    this->hide();
                    p->show();
                });
                }
            );

    //点开游戏说明界面
    //点击开始按钮切换到下一界面
    connect(shuomingtbtn,&mybutton::clicked,[=](){

        //qDebug()<<"点击了开始";

        shuomingtbtn->zoom1();
        shuomingtbtn->zoom2();

        //延时进入到选择人物场景
        QTimer::singleShot(500,this,[=](){
            //this->hide();
            y->show();
        });
    }
            );


}



void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://tutupianpian/background111.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}



MainWindow::~MainWindow()
{
    delete ui;
}
