#ifndef SNAKEDIALOG_H
#define SNAKEDIALOG_H

#include <QDialog>
#include <QTimer>
#include<QTime>
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include <QPoint>
#include <QVector>
#include <QTransform>
#include<QMessageBox>
#include<QRect>
namespace Ui {
class SnakeDialog;
}

class SnakeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SnakeDialog(QWidget *parent = 0);
    ~SnakeDialog();
public slots:
    //更新现有的蛇身体的一个综合函数
    void body(void);
private slots:
    void on_startButton_clicked();

    void on_pauseButton_clicked();

    void on_exitButton_clicked();

private:
    //按键按下时控制蛇头
    void keyPressEvent(QKeyEvent *event);
    //按键抬起时打印按键代码
    void keyReleaseEvent(QKeyEvent *event);
    //判断是否碰到墙
    bool touchthewall(void);
    //判断是否碰到自身
    bool touchself(void);
    //判断是否吃到食物
    bool eatfood(void);
    //生成食物的函数
    void produce(void);
private:
     //绘图事件函数
     void paintEvent(QPaintEvent *);
private:
    Ui::SnakeDialog *ui;
    QVector<QPoint> list;//存储蛇的身体
    QPoint m_rec;//存储食物的位置
    QPoint m_pos[4];//存储地图四个角
    QTimer *timer;//定时器
    int direct[2];//控制方向
    bool isPaused;//是否处于暂停状态
    bool isStarted;//是否已经开始状态
    int movespeed;//存储速度
    int score;//存储分数
};

#endif // SNAKEDIALOG_H
