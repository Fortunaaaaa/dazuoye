#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include"pickypurcharacter.h" //子窗口头文件
#include "youxishuoming.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);//系统的构造函数
    ~MainWindow();

     pickypurcharacter  *p;
     youxishuoming * y;

    //重写paintevent事件 画背景图
public:
    void paintEvent(QPaintEvent*);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
