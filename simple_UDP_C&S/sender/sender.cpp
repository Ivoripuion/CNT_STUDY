#include "sender.h"
#include "ui_sender.h"
#include <QtNetwork>

Sender::Sender(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sender)
{
    ui->setupUi(this);

    sender = new QUdpSocket(this);

    se_receiver = new QUdpSocket(this);
    se_receiver->bind(QHostAddress::LocalHost,45455);
    connect(se_receiver, &QUdpSocket::readyRead, this, &Sender::processPendingDatagram);
}

Sender::~Sender()
{
    delete ui;
}

void Sender::on_pushButton_clicked()
{
    QString sended_text = ui->lineEdit->text();
    QByteArray datagram = sended_text.toLatin1();
    QHostAddress ip_address=QHostAddress(ui->ip_addr->text());
    int server_port=int(ui->server_port->value());
    sender->writeDatagram(datagram.data(), datagram.size(),
                          ip_address, server_port);
}

void Sender::processPendingDatagram(){
    while(se_receiver->hasPendingDatagrams())
    {
        QByteArray rec_datagram;
        rec_datagram.resize(se_receiver->pendingDatagramSize());

        se_receiver->readDatagram(rec_datagram.data(), rec_datagram.size());
        ui->textBrowser->insertPlainText(rec_datagram);
    }
}
