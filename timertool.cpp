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

    ui->RESETBTN->setIcon(QIcon(":/icon/reset.ico"));
    ui->RESETBTN->setIconSize(QSize(80,80));

    ui->RECORDBTN->setIcon(QIcon(":/icon/record.ico"));
    ui->RECORDBTN->setIconSize(QSize(80,80));

    ui->STARTSTOPBTN->setIcon(QIcon(":/icon/start.ico"));
    ui->STARTSTOPBTN->setIconSize(QSize(80,80));
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
        ui->STARTSTOPBTN->setIcon(QIcon(":/icon/start.ico"));
        ui->STARTSTOPBTN->setIconSize(QSize(80,80));
    }
    else{
        timer->setInterval(1);
        timer->start();
        isOnTime=true;
        ui->STARTSTOPBTN->setIcon(QIcon(":/icon/stop.ico"));
        ui->STARTSTOPBTN->setIconSize(QSize(80,80));
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

    ui->STARTSTOPBTN->setIcon(QIcon(":/icon/start.ico"));
    ui->STARTSTOPBTN->setIconSize(QSize(80,80));

    ui->RECORDLIST->clear();
}

void TimerTool::on_RECORDBTN_clicked()
{
    cnt++;
    QListWidgetItem* item =new QListWidgetItem(QString::number(cnt));
    item->setSizeHint(QSize(300,40));
    ui->RECORDLIST->addItem(item);
    ui->RECORDLIST->setItemWidget(item,new TimeRecordItem(timeRecord->toString("hh:mm:ss:zzz"),this));
}
