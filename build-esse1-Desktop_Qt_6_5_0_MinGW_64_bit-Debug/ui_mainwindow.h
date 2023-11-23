/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditN;
    QLineEdit *lineEdit_a;
    QLineEdit *lineEdit_b;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 20, 681, 491));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 400, 241, 71));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 60, 91, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 89, 81, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 130, 71, 21));
        lineEditN = new QLineEdit(groupBox);
        lineEditN->setObjectName("lineEditN");
        lineEditN->setGeometry(QRect(110, 60, 113, 28));
        lineEdit_a = new QLineEdit(groupBox);
        lineEdit_a->setObjectName("lineEdit_a");
        lineEdit_a->setGeometry(QRect(110, 90, 113, 28));
        lineEdit_b = new QLineEdit(groupBox);
        lineEdit_b->setObjectName("lineEdit_b");
        lineEdit_b->setGeometry(QRect(110, 120, 113, 28));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\275\321\217 \320\264\320\273\321\217 \320\276\320\261\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\217 \321\226\320\275\321\202\320\265\320\263\321\200\320\260\320\273\321\203", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\207\320\270\321\201\320\273\320\270\321\202\320\270 \321\226\320\275\321\202\320\265\320\263\321\200\320\260\320\273", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 N", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 b", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
