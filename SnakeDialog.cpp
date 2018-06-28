#include "SnakeDialog.h"
#include "ui_SnakeDialog.h"

SnakeDialog::SnakeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SnakeDialog)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    qsrand(QTime::currentTime().msecsSinceStartOfDay());
    isStarted=false;
    //确定边界
    m_pos[0].setX(ui->frame->pos().x());
    m_pos[0].setY(ui->frame->pos().y());
    m_pos[1].setX(m_pos[0].x()+ui->frame->width());
    m_pos[1].setY(ui->frame->pos().y());
    m_pos[2].setX(m_pos[1].x());
    m_pos[2].setY(m_pos[1].y()+ui->frame->height());
    m_pos[3].setX(m_pos[0].x());
    m_pos[3].setY(m_pos[2].y());
    produce();
    //定时器到时发送信号timeout
    connect(timer,SIGNAL(timeout()),
               this,SLOT(body()));

    qDebug()<<"SnakeDialog";
//    qDebug()<<m_pos[0].x();qDebug()<<m_pos[0].y();
//    qDebug()<<m_pos[1].x();qDebug()<<m_pos[1].y();
//    qDebug()<<m_pos[2].x();qDebug()<<m_pos[2].y();
//    qDebug()<<m_pos[3].x();qDebug()<<m_pos[3].y();
//    qDebug()<<list.first().x();qDebug()<<list.first().y();
}
SnakeDialog::~SnakeDialog()
{
    delete ui;
}
void SnakeDialog::keyPressEvent(QKeyEvent *event){
       if(event->key() == Qt::Key_Up){//上
           if(direct[0]!=0){
                direct[0]=0,direct[1]=-10;
           }
       }else if(event->key() == Qt::Key_Down){//下
           if(direct[0]!=0){
                direct[0]=0,direct[1]=+10;
           }
       }else if(event->key() == Qt::Key_Left){//左
           if(direct[1]!=0){
                direct[0]=-10,direct[1]=0;
           }
       }else if(event->key() == Qt::Key_Right){//右
           if(direct[1]!=0){
                direct[0]=+10,direct[1]=0;
           }
       }else if(event->key()==Qt::Key_Shift){
           if(ui->speedlabel->text().toInt()!=10){
               ui->speedlabel->setNum
                       ((ui->speedlabel->text().toInt()+1));
               if(isStarted){
                   timer->stop();
                   timer->start(300/(ui->speedlabel->text().toInt()));
               }

           }
       }else if(event->key()==Qt::Key_Control){
           if(ui->speedlabel->text().toInt()!=1){
               ui->speedlabel->setNum
                       ((ui->speedlabel->text().toInt()-1));
               if(isStarted){
                   timer->stop();
                   timer->start(300/(ui->speedlabel->text().toInt()));
               }
           }
       }
       qDebug()<<"keyPressEvent";
}
//按键抬起时打印按键代码
void SnakeDialog::keyReleaseEvent(QKeyEvent *event){
    qDebug("按键代码:%d",event->key());
}
//判断是否碰到墙
bool SnakeDialog::touchthewall(void){
    qDebug()<<"touchthewall";
    if(list.first().x()<=m_pos[0].x()+10||
            list.first().x()>=m_pos[2].x()-10||
            list.first().y()<=m_pos[0].y()+10||
            list.first().y()>=m_pos[2].y()-10)
    {
        return true;
    }
    return false;
}
//判断是否碰到自身
bool SnakeDialog::touchself(void){
    qDebug()<<"touchself";
    for(int i=2;i<list.size();i++){
        const QPoint point=list[i];
        if(point.x()==list.first().x()&&
                point.y()==list.first().y()){
            return true;
        }
    }
    return false;
}
//判断是否吃到食物
bool SnakeDialog::eatfood(void){
    qDebug()<<"eatfood";
    if(list.first().x()==m_rec.x()&&
            list.first().y()==m_rec.y()){
        return true;
    }
    return false;
}
//生成食物的函数
void SnakeDialog::produce(void){
    qDebug()<<"produce";
    m_rec.setX((qrand()%54)*10+ui->frame->pos().x()+20);
    m_rec.setY((qrand()%34)*10+ui->frame->pos().y()+20);
    qDebug()<<m_rec.x();
    qDebug()<<m_rec.y();
}
//更新现有的蛇身体的一个综合函数
void SnakeDialog::body(void){
     qDebug()<<"body";
    if(touchthewall()==true){
        QMessageBox msg(QMessageBox::NoIcon,
                        QString("失误"),
                        QString("碰到墙了，好疼呀    \n\n"),
                        QMessageBox::Ok,this);
        msg.exec();
        on_exitButton_clicked();
    }else if(touchself()==true){
        QMessageBox msg(QMessageBox::NoIcon,
                        QString("失误"),
                        QString("碰到自己了，呜呜呜    \n\n"),QMessageBox::Ok,this);
        msg.exec();
        on_exitButton_clicked();
    }else if(eatfood()==true){
        list.prepend(m_rec);
        produce();//再生产一个食物
        score+=100;
        ui->scorelabel->setNum(score);
    }else{
        QPoint m_tmp(list.first().x()+direct[0],
                list.first().y()+direct[1]);
        list.prepend(m_tmp);
        list.removeLast();
    }
    update();
}
 //绘图事件函数
 void SnakeDialog::paintEvent(QPaintEvent *){
        //1)创建画家对象
        QPainter painter(this);
        QRect rcImage = ui->frame->frameRect();
        rcImage.translate(ui->frame->pos());
        QImage image(":/timg.jpg");
        painter.drawImage(rcImage,image);

//        painter.setBrush(QBrush(Qt::yellow,Qt::Dense7Pattern));
//        painter.drawPolygon(m_pos,4);

        painter.setPen(QPen(Qt::cyan,10,
                            Qt::DashLine,Qt::RoundCap,
                            Qt::MiterJoin));

        painter.drawPoint(m_rec);

        if(list.size()==1){
            painter.drawPoint(list.begin()->x(),
                              list.begin()->y());
        }
        else{
            painter.drawPolyline(list.begin(),list.size());
        }

 }
//开始游戏
void SnakeDialog::on_startButton_clicked()
{
    qDebug()<<"startButton";
    list.clear();//清空链表
    score=0;
    //设置蛇的起点
    QPoint point(290,190);
    list.append(point);
    direct[0]=10;direct[1]=0;
    isStarted=true;
    timer->start(300/(ui->speedlabel->text().toInt()));
    isPaused=false;
    ui->pauseButton->setEnabled(true);
    ui->startButton->setEnabled(false);
    ui->exitButton->setEnabled(true);
}
//暂停与恢复游戏
void SnakeDialog::on_pauseButton_clicked()
{
    if(isPaused==false){//若此时不是暂停状态，则
        isPaused=true;
        timer->stop();
        ui->pauseButton->setText("恢复游戏");
    }else{
        isPaused=false;
        ui->frame->setFocus();
        timer->start(300/(ui->speedlabel->text().toInt()));
    }
}
//停止游戏
void SnakeDialog::on_exitButton_clicked()
{
    ui->pauseButton->setEnabled(false);
    list.clear();
    timer->stop();
    ui->exitButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    ui->pauseButton->setEnabled(false);
    update();
    QMessageBox msg(QMessageBox::NoIcon,
                    QString("嘻嘻"),
                    QString("您的得分是"+ui->scorelabel->text()+"    \n\n"),QMessageBox::Ok,this);
    msg.exec();
}
