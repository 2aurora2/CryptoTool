#include "cryptotool.h"
#include "ui_cryptotool.h"
#include <QDebug>

CryptoTool::CryptoTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CryptoTool)
{
    ui->setupUi(this);
    ui->MOVESIZE->setVisible(false);
    ui->TIPS->setVisible(false);

    // 初始化培根编码表
    this->baconEncode.insert('a',"aaaaa");
    this->baconEncode.insert('b',"aaaab");
    this->baconEncode.insert('c',"aaaba");
    this->baconEncode.insert('d',"aaabb");
    this->baconEncode.insert('e',"aabaa");
    this->baconEncode.insert('f',"aabab");
    this->baconEncode.insert('g',"aabba");
    this->baconEncode.insert('h',"aabbb");
    this->baconEncode.insert('i',"abaaa");
    this->baconEncode.insert('j',"abaab");
    this->baconEncode.insert('k',"ababa");
    this->baconEncode.insert('l',"ababb");
    this->baconEncode.insert('m',"abbaa");
    this->baconEncode.insert('n',"abbab");
    this->baconEncode.insert('o',"abbba");
    this->baconEncode.insert('p',"abbbb");
    this->baconEncode.insert('q',"baaaa");
    this->baconEncode.insert('r',"baaab");
    this->baconEncode.insert('s',"baaba");
    this->baconEncode.insert('t',"baabb");
    this->baconEncode.insert('u',"babaa");
    this->baconEncode.insert('v',"babab");
    this->baconEncode.insert('w',"babba");
    this->baconEncode.insert('x',"babbb");
    this->baconEncode.insert('y',"bbaaa");
    this->baconEncode.insert('z',"bbaab");
}

CryptoTool::~CryptoTool()
{
    delete ui;
}

void CryptoTool::on_BASEENCODE_clicked()
{
    this->algorithm="base64_encode";
    ui->MOVESIZE->setVisible(false);
    ui->TIPS->setVisible(false);
}

void CryptoTool::on_BASEDECODE_clicked()
{
    this->algorithm="base64_decode";
    ui->MOVESIZE->setVisible(false);
    ui->TIPS->setVisible(false);
}

void CryptoTool::on_MD5ENCODE_clicked()
{
    this->algorithm="md5_encode";
    ui->MOVESIZE->setVisible(false);
    ui->TIPS->setVisible(false);
}

void CryptoTool::on_KAISAENCODE_clicked()
{
    this->algorithm="kaisa_encode";
    ui->MOVESIZE->setVisible(true);
    ui->TIPS->setVisible(true);
}

void CryptoTool::on_KAISADECODE_clicked()
{
    this->algorithm="kaisa_decode";
    ui->MOVESIZE->setVisible(true);
    ui->TIPS->setVisible(true);
}

void CryptoTool::on_EXECBTN_clicked()
{
    this->inputStr=ui->INPUTEDIT->toPlainText();
//    qDebug()<<this->inputStr<<endl;
    if(this->inputStr==""){
        QMessageBox::information(this,"温馨提示","请输入待加密/解密的内容!");
        return;
    }
    if(this->algorithm==""){
        QMessageBox::information(this,"温馨提示","请先选择加密/解密算法!");
        return;
    }
    // base64加密
    if(this->algorithm=="base64_encode"){
        QByteArray temp=this->inputStr.toLocal8Bit().toBase64();
        ui->RESEDIT->setText(QString::fromLocal8Bit(temp));
        this->resultStr=ui->RESEDIT->toPlainText();
    }
    // base64解密
    else if (this->algorithm=="base64_decode") {
        QByteArray temp=QByteArray::fromBase64(this->inputStr.toLocal8Bit());
        ui->RESEDIT->setText(QString::fromLocal8Bit(temp));
        this->resultStr=ui->RESEDIT->toPlainText();
    }
    // ma5加密
    else if (this->algorithm=="md5_encode") {
        QByteArray temp = this->inputStr.toUtf8();
        ui->RESEDIT->setText(QCryptographicHash::hash(temp, QCryptographicHash::Md5).toHex());
        this->resultStr=ui->RESEDIT->toPlainText();
    }
    // 凯撒加密
    else if(this->algorithm=="kaisa_encode"){
        this->resultStr="";
        this->moveSize=ui->MOVESIZE->value();
        for(int i=0;i<this->inputStr.size();++i){
            if(this->inputStr[i]>='A'&&this->inputStr[i]<='Z')
                this->resultStr+=((this->inputStr[i].toLatin1()-'A'+this->moveSize)%26)+'A';
            else if (this->inputStr[i]>='a'&&this->inputStr[i]<='z')
                this->resultStr+=((this->inputStr[i].toLatin1()-'a'+this->moveSize)%26)+'a';
            else
                this->resultStr+=this->inputStr[i];
        }
        ui->RESEDIT->setText(this->resultStr);
    }
    // 凯撒解密
    else if (this->algorithm=="kaisa_decode") {
        this->resultStr="";
        this->moveSize=26-ui->MOVESIZE->value();
        for(int i=0;i<this->inputStr.size();++i){
            if(this->inputStr[i]>='A'&&this->inputStr[i]<='Z')
                this->resultStr+=((this->inputStr[i].toLatin1()-'A'+this->moveSize)%26)+'A';
            else if (this->inputStr[i]>='a'&&this->inputStr[i]<='z')
                this->resultStr+=((this->inputStr[i].toLatin1()-'a'+this->moveSize)%26)+'a';
            else
                this->resultStr+=this->inputStr[i];
        }
        ui->RESEDIT->setText(this->resultStr);
    }
    // 培根加密
    else if (this->algorithm=="bacon_encode") {
        this->resultStr="";
        for(int i=0;i<this->inputStr.size();++i){
            char temp=this->inputStr[i].toLatin1();
            if(isalpha(temp)){
                char per=tolower(temp);
                this->resultStr+=this->baconEncode[per];
            }
        }
        ui->RESEDIT->setText(this->resultStr);
    }
    // 培根解密
    else if (this->algorithm=="bacon_decode") {
        this->resultStr="";
        for(int i=0;i<this->inputStr.size();i+=5){
            QString temp=this->inputStr.mid(i,5);
            for(int j=0;j<5;++j)
                temp[j]=tolower(temp[j].toLatin1());
            auto iter=this->baconEncode.constBegin();
            while(iter!=this->baconEncode.constEnd()){
                if(iter.value()==temp){
                    this->resultStr+=iter.key();
                    break;
                }
                ++iter;
            }
        }
        ui->RESEDIT->setText(this->resultStr);
    }
    // url编码
    else if (this->algorithm=="url_encode") {
        this->resultStr=QUrl::toPercentEncoding(this->inputStr);
        ui->RESEDIT->setText(this->resultStr);
    }
    // url解码
    else if (this->algorithm=="url_decode") {
        this->resultStr=QUrl::fromPercentEncoding(this->inputStr.toUtf8());
        ui->RESEDIT->setText(this->resultStr);
    }
}

void CryptoTool::on_COPYBTN_clicked()
{
    QClipboard *clip = QApplication::clipboard();
    if(this->resultStr==""){
        QMessageBox::information(this,"failed","暂无执行结果!");
        return;
    }
    clip->setText(this->resultStr);
    QMessageBox::information(this,"success","复制成功!");
}

void CryptoTool::on_BACONENCODE_clicked()
{
    this->algorithm="bacon_encode";
    ui->MOVESIZE->setVisible(false);
    ui->TIPS->setVisible(false);
}

void CryptoTool::on_BACONDECODE_clicked()
{
    this->algorithm="bacon_decode";
    ui->MOVESIZE->setVisible(false);
    ui->TIPS->setVisible(false);
}

void CryptoTool::on_CLEARBTN_clicked()
{
    ui->INPUTEDIT->setText("");
    ui->RESEDIT->setText("");
}

void CryptoTool::on_URLENCODE_clicked()
{
    this->algorithm="url_encode";
    ui->MOVESIZE->setVisible(false);
    ui->TIPS->setVisible(false);
}

void CryptoTool::on_URLDECODE_clicked()
{
    this->algorithm="url_decode";
    ui->MOVESIZE->setVisible(false);
    ui->TIPS->setVisible(false);
}
