#include "eventitem.h"
#include "historytoday.h"
#include "ui_historytoday.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

HistoryToday::HistoryToday(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryToday)
{
    ui->setupUi(this);
    today=QDate::currentDate();
    month=today.month();
    day=today.day();

    ui->TODAY->setDigitCount(10);
    ui->TODAY->setSegmentStyle(QLCDNumber::Flat);
    ui->TODAY->display(today.toString("yyyy-MM-dd"));

    QUrl url("https://www.mxnzp.com/api/history/today?type=1&app_id=rgypxmmgjwewgtno&app_secret=gGUf3zLfM4agvwlbPrDz3L9skI9kDqAv");
    QNetworkRequest req(url);
    QNetworkReply* reply=manager->get(req);

    while(!reply->isFinished()) {
            qApp->processEvents();
        }
    QByteArray data = reply->readAll();
    QJsonDocument doc=QJsonDocument::fromJson(data);
    QJsonObject obj=doc.object();

    QJsonArray dataArray = obj["data"].toArray();
    int cnt=0;
    foreach(const QJsonValue & value, dataArray) {
        cnt++;
        QJsonObject dataObject = value.toObject();
        QString title = dataObject["title"].toString();
        QString year = dataObject["year"].toString();
//        qDebug()<<year<<" "<<title<<endl;
        QListWidgetItem* item =new QListWidgetItem();
        item->setSizeHint(QSize(700,40));
        ui->EVENTLIST->addItem(item);
        ui->EVENTLIST->setItemWidget(item,new EventItem(year,title,this));
    }

    reply->deleteLater();
    delete manager;
}

HistoryToday::~HistoryToday()
{
    delete ui;
}
