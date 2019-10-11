#ifndef SENDER_H
#define SENDER_H

#include <QDialog>
class QUdpSocket;

namespace Ui {
class Sender;
}

class Sender : public QDialog
{
    Q_OBJECT

public:
    explicit Sender(QWidget *parent = 0);
    ~Sender();

private slots:
    void on_pushButton_clicked();

    void on_textEdit_copyAvailable(bool b);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Sender *ui;
    QUdpSocket *sender;
    QUdpSocket *se_receiver;
    void processPendingDatagram();
};

#endif // SENDER_H
