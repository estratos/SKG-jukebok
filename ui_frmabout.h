/********************************************************************************
** Form generated from reading UI file 'frmabout.ui'
**
** Created: Tue Jul 19 22:09:11 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMABOUT_H
#define UI_FRMABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmAbout
{
public:
    QFrame *frame;
    QFrame *line;
    QLabel *lblHeader;
    SKG_Button *btnOK;
    QLabel *lblVersion;
    QLabel *lblCopyright;

    void setupUi(QDialog *frmAbout)
    {
        if (frmAbout->objectName().isEmpty())
            frmAbout->setObjectName(QString::fromUtf8("frmAbout"));
        frmAbout->resize(400, 300);
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
        QBrush brush2(QColor(122, 122, 122, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frmAbout->setPalette(palette);
        frmAbout->setAutoFillBackground(true);
        frame = new QFrame(frmAbout);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 396, 296));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 32, 400, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
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
        QFont font;
        font.setFamily(QString::fromUtf8("Digital-7"));
        font.setPointSize(22);
        lblHeader->setFont(font);
        lblHeader->setAlignment(Qt::AlignCenter);
        btnOK = new SKG_Button(frame);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(280, 215, 101, 71));
        btnOK->setAutoFillBackground(true);
        lblVersion = new QLabel(frame);
        lblVersion->setObjectName(QString::fromUtf8("lblVersion"));
        lblVersion->setGeometry(QRect(10, 40, 381, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bitstream Charter"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        lblVersion->setFont(font1);
        lblVersion->setAlignment(Qt::AlignCenter);
        lblCopyright = new QLabel(frame);
        lblCopyright->setObjectName(QString::fromUtf8("lblCopyright"));
        lblCopyright->setGeometry(QRect(10, 120, 381, 81));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bitstream Charter"));
        font2.setPointSize(12);
        lblCopyright->setFont(font2);
        lblCopyright->setAlignment(Qt::AlignCenter);
        lblCopyright->setWordWrap(true);

        retranslateUi(frmAbout);

        QMetaObject::connectSlotsByName(frmAbout);
    } // setupUi

    void retranslateUi(QDialog *frmAbout)
    {
        frmAbout->setWindowTitle(QApplication::translate("frmAbout", "Dialog", 0, QApplication::UnicodeUTF8));
        lblHeader->setText(QApplication::translate("frmAbout", "About", 0, QApplication::UnicodeUTF8));
        btnOK->setText(QApplication::translate("frmAbout", "OK", 0, QApplication::UnicodeUTF8));
        lblVersion->setText(QString());
        lblCopyright->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmAbout: public Ui_frmAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMABOUT_H
