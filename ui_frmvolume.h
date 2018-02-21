/********************************************************************************
** Form generated from reading UI file 'frmvolume.ui'
**
** Created: Tue Jul 19 22:09:11 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMVOLUME_H
#define UI_FRMVOLUME_H

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

class Ui_frmVolume
{
public:
    QFrame *frame;
    SKG_Button *btnDown;
    SKG_Button *btnUp;
    QLabel *lblHeader;
    SKG_Button *btnExit;
    QFrame *line;

    void setupUi(QDialog *frmVolume)
    {
        if (frmVolume->objectName().isEmpty())
            frmVolume->setObjectName(QString::fromUtf8("frmVolume"));
        frmVolume->resize(400, 173);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(248, 248, 248, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(122, 122, 122, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        frmVolume->setPalette(palette);
        frame = new QFrame(frmVolume);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 398, 171));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        btnDown = new SKG_Button(frame);
        btnDown->setObjectName(QString::fromUtf8("btnDown"));
        btnDown->setGeometry(QRect(140, 68, 111, 71));
        btnDown->setAutoFillBackground(true);
        btnDown->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-down.jpg")));
        btnUp = new SKG_Button(frame);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));
        btnUp->setGeometry(QRect(11, 68, 101, 71));
        btnUp->setAutoFillBackground(true);
        btnUp->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-up.jpg")));
        lblHeader = new QLabel(frame);
        lblHeader->setObjectName(QString::fromUtf8("lblHeader"));
        lblHeader->setGeometry(QRect(0, -2, 400, 31));
        QPalette palette1;
        QBrush brush4(QColor(255, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        QBrush brush5(QColor(133, 131, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        lblHeader->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Digital-7"));
        font.setPointSize(22);
        lblHeader->setFont(font);
        lblHeader->setAlignment(Qt::AlignCenter);
        btnExit = new SKG_Button(frame);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(280, 68, 111, 71));
        btnExit->setAutoFillBackground(true);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 30, 400, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(frmVolume);

        QMetaObject::connectSlotsByName(frmVolume);
    } // setupUi

    void retranslateUi(QDialog *frmVolume)
    {
        frmVolume->setWindowTitle(QApplication::translate("frmVolume", "Dialog", 0, QApplication::UnicodeUTF8));
        lblHeader->setText(QApplication::translate("frmVolume", "Adjust Volume", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("frmVolume", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmVolume: public Ui_frmVolume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMVOLUME_H
