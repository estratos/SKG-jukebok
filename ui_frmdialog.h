/********************************************************************************
** Form generated from reading UI file 'frmdialog.ui'
**
** Created: Tue Jul 19 22:09:10 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDIALOG_H
#define UI_FRMDIALOG_H

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

class Ui_frmDialog
{
public:
    QFrame *frame;
    SKG_Button *btnAccept;
    QLabel *lblCaption;
    SKG_Button *btnCancel;

    void setupUi(QDialog *frmDialog)
    {
        if (frmDialog->objectName().isEmpty())
            frmDialog->setObjectName(QString::fromUtf8("frmDialog"));
        frmDialog->resize(480, 240);
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
        frmDialog->setPalette(palette);
        frame = new QFrame(frmDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 473, 231));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        btnAccept = new SKG_Button(frame);
        btnAccept->setObjectName(QString::fromUtf8("btnAccept"));
        btnAccept->setGeometry(QRect(330, 140, 131, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        btnAccept->setFont(font);
        btnAccept->setAutoFillBackground(true);
        btnAccept->setWordWrap(true);
        lblCaption = new QLabel(frame);
        lblCaption->setObjectName(QString::fromUtf8("lblCaption"));
        lblCaption->setGeometry(QRect(10, 10, 461, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        lblCaption->setFont(font1);
        lblCaption->setAlignment(Qt::AlignCenter);
        btnCancel = new SKG_Button(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(10, 140, 131, 81));
        btnCancel->setFont(font);
        btnCancel->setAutoFillBackground(true);
        btnCancel->setWordWrap(true);

        retranslateUi(frmDialog);

        QMetaObject::connectSlotsByName(frmDialog);
    } // setupUi

    void retranslateUi(QDialog *frmDialog)
    {
        frmDialog->setWindowTitle(QApplication::translate("frmDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        lblCaption->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmDialog: public Ui_frmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDIALOG_H
