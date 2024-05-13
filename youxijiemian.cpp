#include "youxijiemian.h"
#include<QTime>//包含时钟时间 currenttime生成随机数
#include<QTimer>
#include<QLabel>
#include<QPainter>
#include<QDebug>
#include<QString>

//youxijiemian::youxijiemian(QWidget *parent)
  //  : QMainWindow{parent}
//{}


youxijiemian::youxijiemian(int choosedrenwu)
{
    xuanzerenwu=choosedrenwu;
    //设置固定大小
    setFixedSize(1200,750);
    //设置标题
    setWindowTitle("gaming");

   //设置进度条
    gametime=30;
    gametimeID=0;

    //设置老师走路id
    laoshizouluid=5;
    //设置判断暂停id
    panduanzantingid=25;

    progressbar=new QProgressBar;
    //progressbar->move(this->width()*(-0.1),this->height()*(-0.1));
    this->progressbar->move(400,20);
    progressbar->setParent(this);
    this->progressbar->setMinimum(0);//最小值
    this->progressbar->setMaximum(30);//最大值
    this->progressbar->setValue(gametime);//当前值
    this->progressbar->setFixedSize(500,100);//设置固定大小
    this->progressbar->setVisible(true);
    this->progressbar->setTextVisible(true);
    //this->progressbar->setInvertedAppearance(1);//设置进度条进度增长方向

    //启动定时器
    gametimeID=startTimer(1000);//以1000毫秒为单位/1秒

    //加载老师
    laoshi =new QLabel;
    laoshi->setParent(this);
    laoshizhuangtai=1;//老师面向右边
    QPixmap pixlaoshi;
    pixlaoshi.load("://tutupianpian/teacher-face to right.png");
    //qlabel设置大小
    laoshi->setGeometry(0,250,300,500);
    //老师宽300
    pixlaoshi = pixlaoshi.scaled(laoshi->geometry().size());//图片自适应label大小
    //设置不规则图片样式
    laoshi->setStyleSheet("QPushButton{border:0px;}");
    //将图片设置到qlabel中
    laoshi->setPixmap(pixlaoshi);

    //不同关卡加载学生
    //characterrrrr = new character(this);
    if(choosedrenwu==1)
    {
        //罗小白
        left=0;
        right=300;
        character * xiaobai = new character("://tupian2/girl1-study.png","://tupian2/girl1-cheating-better.png");
        xiaobai->setParent(this);
        xiaobai->move(0,400);
        characterrrrr=xiaobai;

        //别人
        //加载山新
        QLabel * shanxin =new QLabel;
        shanxin->setParent(this);
        QPixmap pixshanxin;
        pixshanxin.load("://tupian2/girl2-study.png");
        //qlabel设置大小
        shanxin->setGeometry(300,400,pixshanxin.width()*0.7,pixshanxin.height()*0.7);
        pixshanxin = pixshanxin.scaled(shanxin->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        shanxin->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        shanxin->setPixmap(pixshanxin);

        //加载zhengchacha
        QLabel * zhengchacha =new QLabel;
        zhengchacha->setParent(this);
        QPixmap pixzhengchacha;
        pixzhengchacha.load("://tupian2/boy1-study.png");
        //qlabel设置大小
        zhengchacha->setGeometry(600,400,pixzhengchacha.width()*0.7,pixzhengchacha.height()*0.7);
        pixzhengchacha = pixzhengchacha.scaled(zhengchacha->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        zhengchacha->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        zhengchacha->setPixmap(pixzhengchacha);

        //加载mtjj
        QLabel * mtjj =new QLabel;
        mtjj->setParent(this);
        QPixmap pixmtjj;
        pixmtjj.load("://tupian2/boy2-study.png");
        //qlabel设置大小
        mtjj->setGeometry(900,400,pixmtjj.width()*0.7,pixmtjj.height()*0.7);
        pixmtjj = pixmtjj.scaled(mtjj->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        mtjj->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        mtjj->setPixmap(pixmtjj);





    }
    if(choosedrenwu==2)
    {
        //加载山新
        left=300;
        right=600;
        character * shanxin = new character("://tupian2/girl2-study.png","://tupian2/girl2-cheating.png");
        shanxin->setParent(this);
        shanxin->move(300,400);
        characterrrrr=shanxin;
        //加载小白
        QLabel * xiaobai =new QLabel;
        xiaobai->setParent(this);
        QPixmap pixxiaobai;
        pixxiaobai.load("://tupian2/girl1-study.png");
        //qlabel设置大小
        xiaobai->setGeometry(0,400,pixxiaobai.width()*0.7,pixxiaobai.height()*0.7);
        pixxiaobai = pixxiaobai.scaled(xiaobai->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        xiaobai->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        xiaobai->setPixmap(pixxiaobai);

        //加载zhengchacha
        QLabel * zhengchacha =new QLabel;
        zhengchacha->setParent(this);
        QPixmap pixzhengchacha;
        pixzhengchacha.load("://tupian2/boy1-study.png");
        //qlabel设置大小
        zhengchacha->setGeometry(600,400,pixzhengchacha.width()*0.7,pixzhengchacha.height()*0.7);
        pixzhengchacha = pixzhengchacha.scaled(zhengchacha->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        zhengchacha->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        zhengchacha->setPixmap(pixzhengchacha);

        //加载mtjj
        QLabel * mtjj =new QLabel;
        mtjj->setParent(this);
        QPixmap pixmtjj;
        pixmtjj.load("://tupian2/boy2-study.png");
        //qlabel设置大小
        mtjj->setGeometry(900,400,pixmtjj.width()*0.7,pixmtjj.height()*0.7);
        pixmtjj = pixmtjj.scaled(mtjj->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        mtjj->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        mtjj->setPixmap(pixmtjj);





    }
    if(choosedrenwu==3)
    {
        //加载郑插插
        left=600;
        right=900;
        character * nansheng1 = new character("://tupian2/boy1-study.png","://tupian2/boy3-cheating.png");
        nansheng1->setParent(this);
        nansheng1->move(600,400);
        characterrrrr=nansheng1;
        //加载小白
        QLabel * xiaobai =new QLabel;
        xiaobai->setParent(this);
        QPixmap pixxiaobai;
        pixxiaobai.load("://tupian2/girl1-study.png");
        //qlabel设置大小
        xiaobai->setGeometry(0,400,pixxiaobai.width()*0.7,pixxiaobai.height()*0.7);
        pixxiaobai = pixxiaobai.scaled(xiaobai->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        xiaobai->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        xiaobai->setPixmap(pixxiaobai);

        //加载山新
        QLabel * shanxin =new QLabel;
        shanxin->setParent(this);
        QPixmap pixshanxin;
        pixshanxin.load("://tupian2/girl2-study.png");
        //qlabel设置大小
        shanxin->setGeometry(300,400,pixshanxin.width()*0.7,pixshanxin.height()*0.7);
        pixshanxin = pixshanxin.scaled(shanxin->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        shanxin->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        shanxin->setPixmap(pixshanxin);

        //加载mtjj
        QLabel * mtjj =new QLabel;
        mtjj->setParent(this);
        QPixmap pixmtjj;
        pixmtjj.load("://tupian2/boy2-study.png");
        //qlabel设置大小
        mtjj->setGeometry(900,400,pixmtjj.width()*0.7,pixmtjj.height()*0.7);
        pixmtjj = pixmtjj.scaled(mtjj->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        mtjj->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        mtjj->setPixmap(pixmtjj);






    }
    if(choosedrenwu==4)
    {
        //加载mtjj
        left=900;
        right=1200;
        character * nansheng2 = new character("://tupian2/boy2-study.png","://tupian2/boy4-cheating.png");
        nansheng2->setParent(this);
        nansheng2->move(900,400);
        characterrrrr=nansheng2;
        //加载小白
        QLabel * xiaobai =new QLabel;
        xiaobai->setParent(this);
        QPixmap pixxiaobai;
        pixxiaobai.load("://tupian2/girl1-study.png");
        //qlabel设置大小
        xiaobai->setGeometry(0,400,pixxiaobai.width()*0.7,pixxiaobai.height()*0.7);
        pixxiaobai = pixxiaobai.scaled(xiaobai->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        xiaobai->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        xiaobai->setPixmap(pixxiaobai);

        //加载山新
        QLabel * shanxin =new QLabel;
        shanxin->setParent(this);
        QPixmap pixshanxin;
        pixshanxin.load("://tupian2/girl2-study.png");
        //qlabel设置大小
        shanxin->setGeometry(300,400,pixshanxin.width()*0.7,pixshanxin.height()*0.7);
        pixshanxin = pixshanxin.scaled(shanxin->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        shanxin->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        shanxin->setPixmap(pixshanxin);

        //加载zhengchacha
        QLabel * zhengchacha =new QLabel;
        zhengchacha->setParent(this);
        QPixmap pixzhengchacha;
        pixzhengchacha.load("://tupian2/boy1-study.png");
        //qlabel设置大小
        zhengchacha->setGeometry(600,400,pixzhengchacha.width()*0.7,pixzhengchacha.height()*0.7);
        pixzhengchacha = pixzhengchacha.scaled(zhengchacha->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        zhengchacha->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        zhengchacha->setPixmap(pixzhengchacha);
    }
    left=characterrrrr->mapToParent(QPoint(0,0)).x();
    right=characterrrrr->mapToParent(QPoint(0,0)).x()+characterrrrr->kuandu;
    //qDebug()<<characterrrrr->is_cheating;


    //m_animation = new QPropertyAnimation(laoshi,"pos");
    m_animation->setTargetObject(this->laoshi);    //设置使用动画的控件
    m_animation->setEasingCurve(QEasingCurve::Linear); //设置动画效果
     m_animation->setPropertyName("pos");


     //先启动一次
     laoshizouluid=startTimer(2300);
        //获取老师横坐标xxxlaoshi
        QPoint laoshipoint = laoshi->mapToParent(QPoint(0,0));
        xxxlaoshi = int(laoshipoint.x());
        qDebug()<<xxxlaoshi<<"老师横坐标";

        //获取随机数
        int mubiaoweizhia=getRandom();
        qDebug()<<mubiaoweizhia<<"目标位置";
        //移动老师
        youxijiemian::moveimage(laoshi,xxxlaoshi,mubiaoweizhia);

    //判断是否可以看到作弊
        dingshiqiyanshi=36;
        //开启定时器延时
        dingshiqiyanshi=startTimer(300);
        //panduanzantingid=startTimer(10);


    //实例化失败成功窗口
        winthegame = new win;
        loosethegame = new loose;

    //qlabel显示点击次数
        xianshidianjicishu = new QLabel (this);
        xianshidianjicishu->setGeometry(-20,-20,300,70);
        //xianshidianjicishu->setText("目标次数：60\n目前次数：0");
        //xianshidianjicishu->setText("30");
        QFont font("Arial", 15);
        font.setBold(true);
        xianshidianjicishu->setFont(font);
        xianshidianjicishu->move(90,50);
        xianshidianjicishu->show();





}

void youxijiemian::timerEvent(QTimerEvent*e)
{

    if(e->timerId() == gametimeID)
    {
        gametime--;
        qDebug()<<gametime<<"s";
        //设置进度条
        this->progressbar->setValue(gametime);
        //qDebug()<<"点击次数"<<characterrrrr->dianjicishu;
        //时间到
        if(0 == gametime)
        {
            killTimer(gametimeID);
            killTimer(laoshizouluid);
            //qDebug()<<dianjicishu;
            //这里可以跳成功界面并显示作弊次数
            if(characterrrrr->dianjicishu>=65)
            {
                this->hide();
                winthegame->show();
            }
            else
            {
                this->hide();
                loosethegame->show();
            }
        }
    }

    if(e->timerId() == laoshizouluid)//让老师移动的
    {
        QPoint laoshipoint = laoshi->mapToParent(QPoint(0,0));
        xxxlaoshi = int(laoshipoint.x());
        qDebug()<<xxxlaoshi<<"老师横坐标";
        //获取随机数
        int mubiaoweizhia=getRandom();
        int numb=getRandom();
        mubiaoweizhia=(4*getRandom()+8*numb+23*mubiaoweizhia)%900;

        qDebug()<<mubiaoweizhia<<"目标位置";
        //移动老师
        youxijiemian::moveimage(laoshi,xxxlaoshi,mubiaoweizhia);

        if(0 == gametime)
        {
            m_animation->stop();
            killTimer(laoshizouluid);
            //qDebug()<<dianjicishu;
            //这里可以跳成功界面
            if(characterrrrr->dianjicishu>=65)
            {
                this->hide();
                winthegame->show();
            }
            else
            {
                this->hide();
                loosethegame->show();
            }


        }

    }

    if(e->timerId() == dingshiqiyanshi)
    {
        killTimer(dingshiqiyanshi);
        panduanzantingid=startTimer(8);

    }

    if(e->timerId() == panduanzantingid)//判断是否作弊
    {
        //更新点击次数
        //QString text ("目标次数：65\n目前次数:"<<characterrrrr->dianjicishu);
        //text.replace("aaaa",QChar(characterrrrr->dianjicishu));
        //xianshidianjicishu->setText("目标次数：60\n目前次数:",characterrrrr->dianjicishu);
        //QString string ="目标次数：60\n目前次数:";//+char(characterrrrr->dianjicishu);
        QString string =QString::number( characterrrrr->dianjicishu );
        xianshidianjicishu->setText("目标次数：65\n目前次数:  "+string);

        //是否可以看到作弊和是否在作弊同时为1；停止所有计时器，跳转到失败界面
        if(shifoukeyikandaozuobi(left,right)&&(characterrrrr->is_cheating))
        {
            killTimer(gametimeID);
            qDebug()<<"killtime gametimeid";
            killTimer(laoshizouluid);
            qDebug()<<"killtime laoshizouluid";
            m_animation->stop();
            qDebug()<<"m_animation->stop()";
            killTimer(panduanzantingid);
            qDebug()<<"panduanzanting laoshizouluid";
            qDebug()<<left<<"left"<<right<<"right";
            qDebug()<<"killtime gametimeid"<<laoshi->mapToParent(QPoint(0,0)).x();
            //转到失败界面
            this->hide();
            loosethegame->show();
        }

    }




}

int youxijiemian::getRandom()//生成此范围内的随机数
{
    int min=0;
    int max=900;
    srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    int num = rand()%(max-min);
    //qDebug()<<num+min;
    return (num+min);
}

void youxijiemian::youxijiemian::paintEvent(QPaintEvent *)
{
    QPainter painter (this);
    QPixmap pix;
    pix.load("://tutupianpian/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

//移动函数
void youxijiemian::moveimage(QLabel*laoshi,int xnow,int mubiaoweizhi)
{
    //要往右走
    if(mubiaoweizhi>xnow)
    {
        //加载向右走的图片
        laoshizhuangtai=1;
        QPixmap pixlaoshi;
        pixlaoshi.load("://tutupianpian/teacher-face to right.png");
        laoshi->setGeometry(xxxlaoshi,250,300,500);
        pixlaoshi = pixlaoshi.scaled(laoshi->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        laoshi->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        laoshi->setPixmap(pixlaoshi);

           m_animation->setDuration(2000);    //设置动画时间（单位：毫秒）
           m_animation->setStartValue(this->laoshi->pos());  //设置动画起始位置在label控件当前的pos
           m_animation->setEndValue(QPoint(mubiaoweizhi, 250)); //设置动画结束位置
           m_animation->start();   //启动动画


           if(xnow==mubiaoweizhi)//到达了
           {
               //killTimer(timerid1);
               m_animation->stop();
               return;
           }
    }
    //要往左走
    else if(mubiaoweizhi<xnow)
    {
        laoshizhuangtai=0;
        //shijianid2=getRandom2(0,900);
        //int timerid2=n-shijianid2;
        //加载向左走的图片
        QPixmap pixlaoshi;
        pixlaoshi.load("://tutupianpian/teacher-face to left.png");
        laoshi->setGeometry(xxxlaoshi,250,300,500);
        pixlaoshi = pixlaoshi.scaled(laoshi->geometry().size());//图片自适应label大小
        //设置不规则图片样式
        laoshi->setStyleSheet("QPushButton{border:0px;}");
        //将图片设置到qlabel中
        laoshi->setPixmap(pixlaoshi);

            //timerid2=startTimer(100);//0.1秒响应一次
            m_animation->setDuration(2000);    //设置动画时间（单位：毫秒）
            m_animation->setStartValue(this->laoshi->pos());  //设置动画起始位置在label控件当前的pos
            m_animation->setEndValue(QPoint(mubiaoweizhi, 250)); //设置动画结束位置
            m_animation->start();   //启动动画


            if(xnow==mubiaoweizhi)
            {
                //killTimer(timerid2);
                m_animation->stop();
                return;
            }
      }
    else if(mubiaoweizhi==xnow)
        return;


}

int youxijiemian::shifoukeyikandaozuobi(int left,int right)
{
    int hengzuobiao = laoshi->mapToParent(QPoint(0,0)).x();
    if(laoshizhuangtai==1)//向右走
    {
        if(hengzuobiao+200<=left+100)
            return 1;
        else
            return 0;
    }
    else //if(laoshizhuangtai==0)//向左走
    {
        if(hengzuobiao+100>=right-100)
            return 1;
        else
            return 0;

    }


}

