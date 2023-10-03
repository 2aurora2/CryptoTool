#ifndef TIMERECORDITEM_H
#define TIMERECORDITEM_H

#include <QWidget>

namespace Ui {
class TimeRecordItem;
}

class TimeRecordItem : public QWidget
{
    Q_OBJECT

public:
    explicit TimeRecordItem(QString recordTime, QWidget *parent = nullptr);
    ~TimeRecordItem();

private:
    Ui::TimeRecordItem *ui;
};

#endif // TIMERECORDITEM_H
