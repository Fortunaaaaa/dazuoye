#ifndef LOOSE_H
#define LOOSE_H

#include <QMainWindow>
#include<QPainter>
class loose : public QMainWindow
{
    Q_OBJECT
public:
    explicit loose(QWidget *parent = nullptr);

public:
    void paintEvent(QPaintEvent*);

signals:
};

#endif // LOOSE_H
