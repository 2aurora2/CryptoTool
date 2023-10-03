#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TOCRYPTO->setStyleSheet("background-color:white;color:black;");
    ui->TOCOUNTTIME->setStyleSheet("background-color:#DCDCDC;color:#A9A9A9;");
    this->setWindowTitle("Crypto Tool");
    this->setWindowIcon(QIcon(":/icon/crypto.ico"));
    this->setFixedSize(790,630);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TOCRYPTO_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->TOCRYPTO->setStyleSheet("background-color:white;color:black;");
    ui->TOCOUNTTIME->setStyleSheet("background-color:#DCDCDC;color:#A9A9A9;");
}

void MainWindow::on_TOCOUNTTIME_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->TOCOUNTTIME->setStyleSheet("background-color:white;color:black;");
    ui->TOCRYPTO->setStyleSheet("background-color:#DCDCDC;color:#A9A9A9;");
}
