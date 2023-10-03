#ifndef TIMERTOOL_H
#define TIMERTOOL_H

#include <QWidget>

namespace Ui {
class TimerTool;
}

class TimerTool : public QWidget
{
    Q_OBJECT

public:
    explicit TimerTool(QWidget *parent = nullptr);
    ~TimerTool();

private slots:
    void updateTime();

    void on_STARTSTOPBTN_clicked();

    void on_RESETBTN_clicked();

    void on_RECORDBTN_clicked();

private:
    Ui::TimerTool *ui;
    QTimer* timer;
    QTime* timeRecord;
    bool isOnTime;
    int cnt=0;
};

#endif // TIMERTOOL_H
