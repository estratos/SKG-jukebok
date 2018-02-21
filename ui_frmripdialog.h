/********************************************************************************
** Form generated from reading UI file 'frmripdialog.ui'
**
** Created: Sat Jul 3 18:19:35 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMRIPDIALOG_H
#define UI_FRMRIPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_FrmRipDialog
{
public:
    QLabel *lblCaption;
    SKG_Button *btnCancel;
    SKG_Button *btnAccept;

    void setupUi(QDialog *FrmRipDialog)
    {
        if (FrmRipDialog->objectName().isEmpty())
            FrmRipDialog->setObjectName(QString::fromUtf8("FrmRipDialog"));
        FrmRipDialog->resize(479, 233);
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
        FrmRipDialog->setPalette(palette);
        lblCaption = new QLabel(FrmRipDialog);
        lblCaption->setObjectName(QString::fromUtf8("lblCaption"));
        lblCaption->setGeometry(QRect(10, 10, 461, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lblCaption->setFont(font);
        lblCaption->setAlignment(Qt::AlignCenter);
        btnCancel = new SKG_Button(FrmRipDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(10, 140, 131, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        btnCancel->setFont(font1);
        btnCancel->setAutoFillBackground(true);
        btnCancel->setWordWrap(true);
        btnAccept = new SKG_Button(FrmRipDialog);
        btnAccept->setObjectName(QString::fromUtf8("btnAccept"));
        btnAccept->setGeometry(QRect(340, 140, 131, 81));
        btnAccept->setFont(font1);
        btnAccept->setAutoFillBackground(true);
        btnAccept->setWordWrap(true);

        retranslateUi(FrmRipDialog);

        QMetaObject::connectSlotsByName(FrmRipDialog);
    } // setupUi

    void retranslateUi(QDialog *FrmRipDialog)
    {
        FrmRipDialog->setWindowTitle(QApplication::translate("FrmRipDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        lblCaption->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FrmRipDialog: public Ui_FrmRipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMRIPDIALOG_H
