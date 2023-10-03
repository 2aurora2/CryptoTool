#include "timerecorditem.h"
#include "timertool.h"
#include "ui_timertool.h"

#include <QTime>
#include <QTimer>
#include <QDebug>

TimerTool::TimerTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimerTool)
{
    ui->setupUi(this);
    timer=new QTimer;
    timeRecord=new QTime(0,0,0);
    isOnTime=false;

    ui->TIMER->setDigitCount(12);
    ui->TIMER->setSegmentStyle(QLCDNumber::Flat);
    ui->TIMER->display(timeRecord->toString("hh:mm:ss:zzz"));

    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));

    ui->IDLABEL->setAlignment(Qt::AlignCenter);
    ui->TIMELABEL->setAlignment(Qt::AlignCenter);
}

TimerTool::~TimerTool()
{
    delete ui;
}

void TimerTool::updateTime(){
    *timeRecord = timeRecord->addMSecs(1);
    ui->TIMER->display(timeRecord->toString("hh:mm:ss:zzz"));
}


void TimerTool::on_STARTSTOPBTN_clicked()
{
    if(isOnTime){
        timer->stop();
        isOnTime=false;
    }
    else{
        timer->setInterval(1);
        timer->start();
        isOnTime=true;
    }
}

void TimerTool::on_RESETBTN_clicked()
{
    timer->stop();
    timeRecord=new QTime(0,0,0);
    isOnTime=false;

    ui->TIMER->setDigitCount(12);
    ui->TIMER->setSegmentStyle(QLCDNumber::Flat);
    ui->TIMER->display(timeRecord->toString("hh:mm:ss:zzz"));

    ui->RECORDLIST->clear();
}

void TimerTool::on_RECORDBTN_clicked()
{
    cnt++;
    QListWidgetItem* item =new QListWidgetItem(QString::number(cnt));
    item->setSizeHint(QSize(300,40));
    ui->RECORDLIST->addItem(item);
    qDebug()<<cnt<<endl;
    ui->RECORDLIST->setItemWidget(item,new TimeRecordItem(timeRecord->toString("hh:mm:ss:zzz"),this));
}
