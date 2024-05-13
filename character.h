#ifndef CHARACTER_H
#define CHARACTER_H

#include <QPushButton>
#include<QMouseEvent>


class character : public QPushButton
{
    Q_OBJECT
public:
    //explicit character(QWidget *parent = nullptr);
    character(QString normalImg,QString pressImg);

    QString normalImgPath;
    QString pressImgPath;

    //点击次数
    int dianjicishu=0;
    //是否是作弊状态
    bool is_cheating=0;
    //宽度
    int kuandu;
    //弹跳特效 下/上跳
    void zoom1();
    void zoom2();

    //重写按下和释放事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:
};

#endif // CHARACTER_H
