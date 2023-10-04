#include "eventitem.h"
#include "ui_eventitem.h"

EventItem::EventItem(QString year,QString event,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EventItem)
{
    ui->setupUi(this);
    ui->YEAR->setText(year);
    ui->EVENT->setText(event);
//    this->setFixedSize(650, 30);
//    ui->YEAR->setFixedSize(80, 30);
    ui->EVENT->setFixedWidth(600);
    ui->YEAR->setAlignment(Qt::AlignCenter);
    ui->EVENT->setAlignment(Qt::AlignLeft);
}

EventItem::~EventItem()
{
    delete ui;
}
