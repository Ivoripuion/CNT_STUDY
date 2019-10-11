#include "receiver.h"
#include "ui_receiver.h"
#include <QtNetwork>
#include <QTimer>


Receiver::Receiver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Receiver)
{
    ui->setupUi(this);

    receiver = new QUdpSocket(this);
    receiver->bind(QHostAddress::LocalHost,45454);
    connect(receiver, &QUdpSocket::readyRead, this, &Receiver::processPendingDatagram);

    recv_sender=new QUdpSocket(this);
}

Receiver::~Receiver()
{
    delete ui;
}

void Receiver::processPendingDatagram()
{
    while(receiver->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());

        receiver->readDatagram(datagram.data(), datagram.size());
        if(datagram=="time"){
            QDateTime time = QDateTime::currentDateTime();
            QString str = time.toString("yyyy-MM-dd hh:mm:ss");
            QString tmptime = time.toString("hh:mm:ss");
            QString log=str+" 收到请求[time],响应:["+tmptime+"]"+"\n";
            ui->textBrowser->insertPlainText(log);
            QString tmpSendDate=tmptime+"\n";
            QByteArray logdatagram = tmpSendDate.toLatin1();
            recv_sender->writeDatagram(logdatagram.data(), logdatagram.size(),
                                       QHostAddress::LocalHost, 45455);
        }
        else if(datagram=="date"){
            QDateTime time = QDateTime::currentDateTime();
            QString str = time.toString("yyyy-MM-dd hh:mm:ss");
            QString day = time.toString("yyyy-MM-dd");
            QString log=str+" 收到请求[date],响应:["+day+"]"+"\n";
            ui->textBrowser->insertPlainText(log);
            QString tmpSendDate=day+"\n";
            QByteArray logdatagram = tmpSendDate.toLatin1();
            recv_sender->writeDatagram(logdatagram.data(), logdatagram.size(),
                                       QHostAddress::LocalHost, 45455);
        }
        else{
            QDateTime time = QDateTime::currentDateTime();
            QString str = time.toString("yyyy-MM-dd hh:mm:ss");
            QString log=str+" 收到请求["+datagram+"],响应:[错误指令!]"+"\n";
            ui->textBrowser->insertPlainText(log);
            QByteArray logdatagram = QString("ERROR COMMAND!\n").toLatin1();
            recv_sender->writeDatagram(logdatagram.data(), logdatagram.size(),
                                       QHostAddress::LocalHost, 45455);
        }
    }
}

