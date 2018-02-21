/********************************************************************************
** Form generated from reading UI file 'frmviewkeymappings.ui'
**
** Created: Tue Jul 19 22:09:11 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMVIEWKEYMAPPINGS_H
#define UI_FRMVIEWKEYMAPPINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_FrmViewKeyMappings
{
public:
    QFrame *frame;
    QFrame *line;
    SKG_Button *btnOK;
    QTextEdit *txtKeyMappings;
    QLabel *lblHeader;

    void setupUi(QDialog *FrmViewKeyMappings)
    {
        if (FrmViewKeyMappings->objectName().isEmpty())
            FrmViewKeyMappings->setObjectName(QString::fromUtf8("FrmViewKeyMappings"));
        FrmViewKeyMappings->resize(400, 300);
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
        FrmViewKeyMappings->setPalette(palette);
        frame = new QFrame(FrmViewKeyMappings);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 396, 296));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 32, 400, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btnOK = new SKG_Button(frame);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(290, 230, 101, 56));
        btnOK->setAutoFillBackground(true);
        txtKeyMappings = new QTextEdit(frame);
        txtKeyMappings->setObjectName(QString::fromUtf8("txtKeyMappings"));
        txtKeyMappings->setGeometry(QRect(10, 40, 381, 181));
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        font.setPointSize(12);
        txtKeyMappings->setFont(font);
        txtKeyMappings->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black"));
        lblHeader = new QLabel(frame);
        lblHeader->setObjectName(QString::fromUtf8("lblHeader"));
        lblHeader->setGeometry(QRect(0, 0, 400, 31));
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

        retranslateUi(FrmViewKeyMappings);

        QMetaObject::connectSlotsByName(FrmViewKeyMappings);
    } // setupUi

    void retranslateUi(QDialog *FrmViewKeyMappings)
    {
        FrmViewKeyMappings->setWindowTitle(QApplication::translate("FrmViewKeyMappings", "Dialog", 0, QApplication::UnicodeUTF8));
        btnOK->setText(QApplication::translate("FrmViewKeyMappings", "OK", 0, QApplication::UnicodeUTF8));
        lblHeader->setText(QApplication::translate("FrmViewKeyMappings", "Current Key Mappings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmViewKeyMappings: public Ui_FrmViewKeyMappings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMVIEWKEYMAPPINGS_H
