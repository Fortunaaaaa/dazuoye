#ifndef PICKYPURCHARACTER_H
#define PICKYPURCHARACTER_H

#include <QMainWindow>
#include "readyscene.h"

class pickypurcharacter : public QMainWindow
{
    Q_OBJECT
public:
    explicit pickypurcharacter(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);
    //void sendchoosesceneback();

    //准备场景的对象指针
    readyscene * ready=nullptr;


 signals:
    //写一个自定义的信号告诉主场景要返回了
     void choosesceneback();
};

#endif // PICKYPURCHARACTER_H
