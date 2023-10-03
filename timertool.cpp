#include "timertool.h"
#include "ui_timertool.h"

TimerTool::TimerTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimerTool)
{
    ui->setupUi(this);
}

TimerTool::~TimerTool()
{
    delete ui;
}
