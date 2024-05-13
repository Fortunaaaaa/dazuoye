#include "character.h"
#include<QDebug>
#include<QPropertyAnimation>
#include<QLabel>

//character::character(QWidget *parent)
//    : QWidget{parent}
//{}


character::character(QString normalImg,QString pressImg)
{
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;

    dianjicishu =0;
    //定义qpixmap对象
    QPixmap pix;
    bool ret=pix.load(normalImg);
    if (!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }


    //设置图片固定大小
   this->setFixedSize(pix.width()*0.7,pix.height()*0.7);
    this->kuandu=pix.width()*0.7;
    //this->setFixedSize(400,500);
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width()*0.7,pix.height()*0.7));
    //this->setIconSize(QSize(500,500));
}


void character::zoom1()
{
    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
    //qDebug()<<dianjicishu<<"次";
}
void character::zoom2()
{
    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void character::mousePressEvent(QMouseEvent *e)
{
    //记录点击次数
    is_cheating=1;
    dianjicishu++;
    QPixmap pix;
    bool ret=pix.load(pressImgPath);
    if (!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }

    //设置图片固定大小
    this->setFixedSize(pix.width()*0.7,pix.height()*0.7);
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width()*0.7,pix.height()*0.7));

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);

}

void character::mouseReleaseEvent(QMouseEvent *e)
{
    is_cheating=0;
    QPixmap pix;
    bool ret=pix.load(normalImgPath);
    if (!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }

    //设置图片固定大小
    this->setFixedSize(pix.width()*0.7,pix.height()*0.7);
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width()*0.7,pix.height()*0.7));

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}

//位于上面的尝试
/*void character::enterEvent(QMouseEvent *e)
{
    QPixmap pix;
    bool ret=pix.load(pressImgPath);
    if (!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }

    //设置图片固定大小
    label->setFixedSize(pix.width()*0.7,pix.height()*0.7);
    //设置不规则图片样式
    label->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    label->setPixmap(pix);
    //设置图标大小
    //this->setIconSize(QSize(pix.width()*0.7,pix.height()*0.7));
    //this->setIconSize(QSize(500,700));
    label->resize(QSize(pix.width()*0.7,pix.height()*0.7));

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}
void character::leaveEvent(QMouseEvent*e)
{
    QPixmap pix;
    bool ret=pix.load(pressImgPath);
    if (!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }

    //设置图片固定大小
    this->setFixedSize(pix.width()*0.7,pix.height()*0.7);
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width()*0.7,pix.height()*0.7));
    //this->setIconSize(QSize(500,700));

    //设置图片固定大小
    label->setFixedSize(pix.width()*0.7,pix.height()*0.7);
    //设置不规则图片样式
    label->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    label->setPixmap(pix);
    //设置图标大小
    //this->setIconSize(QSize(pix.width()*0.7,pix.height()*0.7));
    //this->setIconSize(QSize(500,700));
    label->resize(QSize(pix.width()*0.7,pix.height()*0.7));


    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}
*/
