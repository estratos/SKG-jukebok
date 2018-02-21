/********************************************************************************
** Form generated from reading UI file 'frmtracksearch.ui'
**
** Created: Tue Jul 19 22:09:11 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTRACKSEARCH_H
#define UI_FRMTRACKSEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_FrmTrackSearch
{
public:
    QFrame *line;
    QLabel *lblHeader;
    QLabel *label;
    QLineEdit *txtTrackName;
    QListWidget *listNames;
    SKG_Button *btnUp;
    SKG_Button *btnDown;
    SKG_Button *btnAdd;
    SKG_Button *btnExit;
    SKG_Button *btnKeyboard;
    QLabel *lblStatus;

    void setupUi(QDialog *FrmTrackSearch)
    {
        if (FrmTrackSearch->objectName().isEmpty())
            FrmTrackSearch->setObjectName(QString::fromUtf8("FrmTrackSearch"));
        FrmTrackSearch->resize(620, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(122, 122, 122, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        FrmTrackSearch->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        FrmTrackSearch->setFont(font);
        line = new QFrame(FrmTrackSearch);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 32, 620, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lblHeader = new QLabel(FrmTrackSearch);
        lblHeader->setObjectName(QString::fromUtf8("lblHeader"));
        lblHeader->setGeometry(QRect(0, 0, 620, 31));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        QBrush brush4(QColor(133, 131, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        lblHeader->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Digital-7"));
        font1.setPointSize(22);
        lblHeader->setFont(font1);
        lblHeader->setAlignment(Qt::AlignCenter);
        label = new QLabel(FrmTrackSearch);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 311, 17));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        txtTrackName = new QLineEdit(FrmTrackSearch);
        txtTrackName->setObjectName(QString::fromUtf8("txtTrackName"));
        txtTrackName->setGeometry(QRect(10, 60, 321, 27));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        txtTrackName->setPalette(palette2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(12);
        txtTrackName->setFont(font3);
        txtTrackName->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        listNames = new QListWidget(FrmTrackSearch);
        listNames->setObjectName(QString::fromUtf8("listNames"));
        listNames->setGeometry(QRect(10, 100, 321, 381));
        listNames->setFrameShape(QFrame::Box);
        listNames->setWordWrap(true);
        btnUp = new SKG_Button(FrmTrackSearch);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));
        btnUp->setGeometry(QRect(340, 100, 121, 81));
        btnUp->setAutoFillBackground(true);
        btnDown = new SKG_Button(FrmTrackSearch);
        btnDown->setObjectName(QString::fromUtf8("btnDown"));
        btnDown->setGeometry(QRect(340, 200, 121, 81));
        btnDown->setAutoFillBackground(true);
        btnAdd = new SKG_Button(FrmTrackSearch);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(340, 390, 121, 91));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        btnAdd->setFont(font4);
        btnAdd->setAutoFillBackground(true);
        btnAdd->setWordWrap(true);
        btnExit = new SKG_Button(FrmTrackSearch);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(480, 490, 121, 71));
        btnExit->setAutoFillBackground(true);
        btnKeyboard = new SKG_Button(FrmTrackSearch);
        btnKeyboard->setObjectName(QString::fromUtf8("btnKeyboard"));
        btnKeyboard->setGeometry(QRect(10, 490, 121, 71));
        QFont font5;
        font5.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        btnKeyboard->setFont(font5);
        btnKeyboard->setAutoFillBackground(true);
        btnKeyboard->setWordWrap(true);
        lblStatus = new QLabel(FrmTrackSearch);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setGeometry(QRect(0, 580, 611, 16));
        QFont font6;
        font6.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font6.setPointSize(10);
        lblStatus->setFont(font6);

        retranslateUi(FrmTrackSearch);

        QMetaObject::connectSlotsByName(FrmTrackSearch);
    } // setupUi

    void retranslateUi(QDialog *FrmTrackSearch)
    {
        FrmTrackSearch->setWindowTitle(QApplication::translate("FrmTrackSearch", "Dialog", 0, QApplication::UnicodeUTF8));
        lblHeader->setText(QApplication::translate("FrmTrackSearch", "Search for Track", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FrmTrackSearch", "Type track name to search for", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("FrmTrackSearch", "Add Track to List", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("FrmTrackSearch", "Exit", 0, QApplication::UnicodeUTF8));
        btnKeyboard->setText(QApplication::translate("FrmTrackSearch", "Onscreen Keyboard", 0, QApplication::UnicodeUTF8));
        lblStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FrmTrackSearch: public Ui_FrmTrackSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTRACKSEARCH_H
