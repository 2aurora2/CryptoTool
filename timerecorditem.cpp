#include "timerecorditem.h"
#include "ui_timerecorditem.h"

TimeRecordItem::TimeRecordItem(QString recordTime, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeRecordItem)
{
    ui->setupUi(this);
    ui->TIMEITEM->setAlignment(Qt::AlignCenter);
    ui->TIMEITEM->setText(recordTime);
    ui->TIMEITEM->setFixedSize(200, 20);
}

TimeRecordItem::~TimeRecordItem()
{
    delete ui;
}
