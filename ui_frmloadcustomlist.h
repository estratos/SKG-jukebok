/********************************************************************************
** Form generated from reading UI file 'frmloadcustomlist.ui'
**
** Created: Tue Jul 19 22:09:10 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOADCUSTOMLIST_H
#define UI_FRMLOADCUSTOMLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmLoadCustomList
{
public:
    QFrame *frame;
    SKG_Button *btnLoad;
    SKG_Button *btnExit;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QTextEdit *txtAlbums;
    QComboBox *cmbLists;

    void setupUi(QDialog *frmLoadCustomList)
    {
        if (frmLoadCustomList->objectName().isEmpty())
            frmLoadCustomList->setObjectName(QString::fromUtf8("frmLoadCustomList"));
        frmLoadCustomList->resize(500, 400);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(133, 131, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frmLoadCustomList->setPalette(palette);
        frame = new QFrame(frmLoadCustomList);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 493, 391));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        btnLoad = new SKG_Button(frame);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setGeometry(QRect(360, 90, 121, 71));
        btnLoad->setAutoFillBackground(true);
        btnExit = new SKG_Button(frame);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(360, 310, 121, 71));
        btnExit->setAutoFillBackground(true);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 500, 31));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Digital-7"));
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(5, 40, 341, 17));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 32, 500, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        txtAlbums = new QTextEdit(frame);
        txtAlbums->setObjectName(QString::fromUtf8("txtAlbums"));
        txtAlbums->setGeometry(QRect(5, 90, 341, 301));
        txtAlbums->setFrameShape(QFrame::Box);
        txtAlbums->setFrameShadow(QFrame::Plain);
        txtAlbums->setReadOnly(true);
        cmbLists = new QComboBox(frame);
        cmbLists->setObjectName(QString::fromUtf8("cmbLists"));
        cmbLists->setGeometry(QRect(2, 60, 341, 27));

        retranslateUi(frmLoadCustomList);

        QMetaObject::connectSlotsByName(frmLoadCustomList);
    } // setupUi

    void retranslateUi(QDialog *frmLoadCustomList)
    {
        frmLoadCustomList->setWindowTitle(QApplication::translate("frmLoadCustomList", "Dialog", 0, QApplication::UnicodeUTF8));
        btnLoad->setText(QApplication::translate("frmLoadCustomList", "Load", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("frmLoadCustomList", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmLoadCustomList", "Load Custom List", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("frmLoadCustomList", "Choose a custom list to load", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmLoadCustomList: public Ui_frmLoadCustomList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOADCUSTOMLIST_H
