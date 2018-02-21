/********************************************************************************
** Form generated from reading UI file 'frmalbumart.ui'
**
** Created: Tue Jul 19 22:09:09 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMALBUMART_H
#define UI_FRMALBUMART_H

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

class Ui_frmAlbumArt
{
public:
    QFrame *frame;
    QLabel *lblArt;
    QLabel *lblStatus;
    QLabel *lblInfo;
    SKG_Button *btnPrev;
    SKG_Button *btnNext;
    SKG_Button *btnSave;
    SKG_Button *btnExit;

    void setupUi(QDialog *frmAlbumArt)
    {
        if (frmAlbumArt->objectName().isEmpty())
            frmAlbumArt->setObjectName(QString::fromUtf8("frmAlbumArt"));
        frmAlbumArt->resize(700, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmAlbumArt->sizePolicy().hasHeightForWidth());
        frmAlbumArt->setSizePolicy(sizePolicy);
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
        frmAlbumArt->setPalette(palette);
        frame = new QFrame(frmAlbumArt);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 691, 471));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        lblArt = new QLabel(frame);
        lblArt->setObjectName(QString::fromUtf8("lblArt"));
        lblArt->setGeometry(QRect(10, 75, 300, 300));
        lblArt->setFrameShape(QFrame::Box);
        lblArt->setScaledContents(true);
        lblArt->setAlignment(Qt::AlignCenter);
        lblStatus = new QLabel(frame);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setGeometry(QRect(10, 10, 601, 61));
        lblStatus->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblInfo = new QLabel(frame);
        lblInfo->setObjectName(QString::fromUtf8("lblInfo"));
        lblInfo->setGeometry(QRect(10, 380, 301, 71));
        lblInfo->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        btnPrev = new SKG_Button(frame);
        btnPrev->setObjectName(QString::fromUtf8("btnPrev"));
        btnPrev->setGeometry(QRect(320, 80, 131, 81));
        btnPrev->setAutoFillBackground(true);
        btnPrev->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-left.jpg")));
        btnNext = new SKG_Button(frame);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(320, 170, 131, 81));
        btnNext->setAutoFillBackground(true);
        btnNext->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-right.jpg")));
        btnSave = new SKG_Button(frame);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(320, 290, 131, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        btnSave->setFont(font);
        btnSave->setAutoFillBackground(true);
        btnSave->setWordWrap(true);
        btnExit = new SKG_Button(frame);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(540, 370, 131, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        btnExit->setFont(font1);
        btnExit->setAutoFillBackground(true);
        btnExit->setWordWrap(true);

        retranslateUi(frmAlbumArt);

        QMetaObject::connectSlotsByName(frmAlbumArt);
    } // setupUi

    void retranslateUi(QDialog *frmAlbumArt)
    {
        frmAlbumArt->setWindowTitle(QApplication::translate("frmAlbumArt", "Dialog", 0, QApplication::UnicodeUTF8));
        lblArt->setText(QString());
        lblStatus->setText(QApplication::translate("frmAlbumArt", "TextLabel", 0, QApplication::UnicodeUTF8));
        lblInfo->setText(QString());
        btnPrev->setText(QString());
        btnNext->setText(QString());
        btnSave->setText(QApplication::translate("frmAlbumArt", "Save as Album Art", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("frmAlbumArt", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmAlbumArt: public Ui_frmAlbumArt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMALBUMART_H
