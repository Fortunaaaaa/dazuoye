#include "loose.h"

loose::loose(QWidget *parent)
    : QMainWindow{parent}
{
    //设置固定大小
    setFixedSize(1200,750);
    //设置标题
    setWindowTitle("defeat!!!you loose!!!!");


}


void loose::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://tupian2/lose222.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
