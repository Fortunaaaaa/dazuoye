#ifndef YOUXISHUOMING_H
#define YOUXISHUOMING_H

#include <QMainWindow>
#include<QPainter>

class youxishuoming : public QMainWindow
{
    Q_OBJECT
public:
    explicit youxishuoming(QWidget *parent = nullptr);

    //重写paintevent事件 画背景图
public:
    void paintEvent(QPaintEvent*);

signals:
};

#endif // YOUXISHUOMING_H
