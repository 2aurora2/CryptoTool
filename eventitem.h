#ifndef EVENTITEM_H
#define EVENTITEM_H

#include <QWidget>

namespace Ui {
class EventItem;
}

class EventItem : public QWidget
{
    Q_OBJECT

public:
    explicit EventItem(QString year,QString event,QWidget *parent = nullptr);
    ~EventItem();

private:
    Ui::EventItem *ui;
};

#endif // EVENTITEM_H
