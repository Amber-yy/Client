/********************************************************************************
** Form generated from reading UI file 'Client.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientClass
{
public:

    void setupUi(QWidget *ClientClass)
    {
        if (ClientClass->objectName().isEmpty())
            ClientClass->setObjectName(QStringLiteral("ClientClass"));
        ClientClass->resize(600, 400);

        retranslateUi(ClientClass);

        QMetaObject::connectSlotsByName(ClientClass);
    } // setupUi

    void retranslateUi(QWidget *ClientClass)
    {
        ClientClass->setWindowTitle(QApplication::translate("ClientClass", "Client", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientClass: public Ui_ClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
