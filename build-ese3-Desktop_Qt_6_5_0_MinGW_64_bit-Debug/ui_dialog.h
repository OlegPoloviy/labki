/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(701, 491);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 661, 481));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 60, 141, 371));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\320\237\320\265\321\200\320\265\320\262\321\226\321\200\320\272\320\260 \321\200\320\276\320\267\320\262\321\217\320\267\320\272\321\203", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
