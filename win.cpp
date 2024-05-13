#include "win.h"

win::win(QWidget *parent)
    : QMainWindow{parent}
{
    //设置固定大小
    setFixedSize(1200,750);
    //设置标题
    setWindowTitle("congratulartions::::win!!!!");


}


void win::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://tupian2/win.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
