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

private:
    Ui::TimerTool *ui;
};

#endif // TIMERTOOL_H
