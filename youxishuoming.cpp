#include "youxishuoming.h"

youxishuoming::youxishuoming(QWidget *parent)
    : QMainWindow{parent}
{
    //设置固定大小
    setFixedSize(700,450);
    //设置标题
    setWindowTitle("游戏说明");


}


void youxishuoming::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://tupian2/shuoming.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

