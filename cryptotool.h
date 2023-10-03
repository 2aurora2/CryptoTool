#ifndef CRYPTOTOOL_H
#define CRYPTOTOOL_H

#include <QWidget>
#include <QByteArray>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QClipboard>
#include <QHash>
#include <cctype>
#include <QUrl>

namespace Ui {
class CryptoTool;
}

class CryptoTool : public QWidget
{
    Q_OBJECT

public:
    explicit CryptoTool(QWidget *parent = nullptr);
    ~CryptoTool();

private slots:
    void on_BASEENCODE_clicked();

    void on_BASEDECODE_clicked();

    void on_EXECBTN_clicked();

    void on_MD5ENCODE_clicked();

    void on_COPYBTN_clicked();

    void on_KAISAENCODE_clicked();

    void on_KAISADECODE_clicked();

    void on_BACONENCODE_clicked();

    void on_BACONDECODE_clicked();

    void on_CLEARBTN_clicked();

    void on_URLENCODE_clicked();

    void on_URLDECODE_clicked();

private:
    Ui::CryptoTool *ui;
    QString inputStr="";
    QString algorithm="";
    QString resultStr="";
    int moveSize=0;
    QHash<char,QString> baconEncode;
};

#endif // CRYPTOTOOL_H
