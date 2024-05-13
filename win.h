#ifndef WIN_H
#define WIN_H

#include <QMainWindow>
#include<QPainter>
class win : public QMainWindow
{
    Q_OBJECT
public:
    explicit win(QWidget *parent = nullptr);

public:
    void paintEvent(QPaintEvent*);

signals:
};

#endif // WIN_H
