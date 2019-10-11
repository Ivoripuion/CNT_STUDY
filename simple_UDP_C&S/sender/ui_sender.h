/********************************************************************************
** Form generated from reading UI file 'sender.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDER_H
#define UI_SENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Sender
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *ip_addr;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *server_port;
    QTextBrowser *textBrowser;
    QLabel *label_4;

    void setupUi(QDialog *Sender)
    {
        if (Sender->objectName().isEmpty())
            Sender->setObjectName(QStringLiteral("Sender"));
        Sender->resize(472, 464);
        pushButton = new QPushButton(Sender);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 400, 81, 31));
        lineEdit = new QLineEdit(Sender);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 90, 181, 31));
        ip_addr = new QLineEdit(Sender);
        ip_addr->setObjectName(QStringLiteral("ip_addr"));
        ip_addr->setGeometry(QRect(70, 40, 181, 31));
        label = new QLabel(Sender);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 50, 72, 15));
        label_2 = new QLabel(Sender);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 100, 72, 15));
        label_3 = new QLabel(Sender);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 150, 72, 15));
        server_port = new QSpinBox(Sender);
        server_port->setObjectName(QStringLiteral("server_port"));
        server_port->setGeometry(QRect(70, 140, 181, 31));
        server_port->setMaximum(65535);
        textBrowser = new QTextBrowser(Sender);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(70, 190, 256, 192));
        label_4 = new QLabel(Sender);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 270, 72, 15));

        retranslateUi(Sender);

        QMetaObject::connectSlotsByName(Sender);
    } // setupUi

    void retranslateUi(QDialog *Sender)
    {
        Sender->setWindowTitle(QApplication::translate("Sender", "Sender", nullptr));
        pushButton->setText(QApplication::translate("Sender", "\345\217\221\351\200\201", nullptr));
        label->setText(QApplication::translate("Sender", "IP\345\234\260\345\235\200", nullptr));
        label_2->setText(QApplication::translate("Sender", "\350\257\267\346\261\202\345\221\275\344\273\244", nullptr));
        label_3->setText(QApplication::translate("Sender", "\350\257\267\346\261\202\347\253\257\345\217\243", nullptr));
        label_4->setText(QApplication::translate("Sender", "\350\277\224\345\233\236\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sender: public Ui_Sender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDER_H
