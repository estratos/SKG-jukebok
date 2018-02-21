/********************************************************************************
** Form generated from reading UI file 'frmhelp.ui'
**
** Created: Tue Jul 19 22:09:11 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMHELP_H
#define UI_FRMHELP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmHelp
{
public:
    QFrame *frame;
    SKG_Button *btnExit;
    SKG_Button *btnDown;
    SKG_Button *btnUp;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *frmHelp)
    {
        if (frmHelp->objectName().isEmpty())
            frmHelp->setObjectName(QString::fromUtf8("frmHelp"));
        frmHelp->resize(799, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmHelp->sizePolicy().hasHeightForWidth());
        frmHelp->setSizePolicy(sizePolicy);
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
        frmHelp->setPalette(palette);
        frame = new QFrame(frmHelp);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 796, 596));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        btnExit = new SKG_Button(frame);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(10, 510, 121, 71));
        btnExit->setAutoFillBackground(true);
        btnDown = new SKG_Button(frame);
        btnDown->setObjectName(QString::fromUtf8("btnDown"));
        btnDown->setGeometry(QRect(699, 510, 91, 71));
        btnDown->setAutoFillBackground(true);
        btnDown->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-down.jpg")));
        btnUp = new SKG_Button(frame);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));
        btnUp->setGeometry(QRect(600, 510, 91, 71));
        btnUp->setAutoFillBackground(true);
        btnUp->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-up.jpg")));
        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 781, 481));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        textBrowser->setPalette(palette1);
        textBrowser->setAutoFillBackground(true);
        textBrowser->setFrameShape(QFrame::Box);

        retranslateUi(frmHelp);

        QMetaObject::connectSlotsByName(frmHelp);
    } // setupUi

    void retranslateUi(QDialog *frmHelp)
    {
        frmHelp->setWindowTitle(QApplication::translate("frmHelp", "Dialog", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("frmHelp", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmHelp: public Ui_frmHelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMHELP_H
