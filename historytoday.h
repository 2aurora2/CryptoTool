#ifndef HISTORYTODAY_H
#define HISTORYTODAY_H

#include <QWidget>
#include <QDate>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace Ui {
class HistoryToday;
}

class HistoryToday : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryToday(QWidget *parent = nullptr);
    ~HistoryToday();

private:
    Ui::HistoryToday *ui;
    QDate today;
    int month,day;
    QNetworkAccessManager* manager=new QNetworkAccessManager();
};

#endif // HISTORYTODAY_H
