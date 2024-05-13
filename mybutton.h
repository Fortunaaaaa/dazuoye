#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>


class mybutton : public QPushButton
{
    Q_OBJECT
public:
    //explicit mybutton(QWidget *parent = nullptr);
    mybutton(QString normalImg,QString pressImg="");

    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效 下/上跳
    void zoom1();
    void zoom2();

signals:
};

#endif // MYBUTTON_H
