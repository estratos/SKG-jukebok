/********************************************************************************
** Form generated from reading UI file 'frmalbumartdialog.ui'
**
** Created: Tue Jul 19 22:09:09 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMALBUMARTDIALOG_H
#define UI_FRMALBUMARTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmAlbumArtDialog
{
public:
    QFrame *frame;
    SKG_Button *btnOK;
    QFrame *frame_2;
    QRadioButton *rbDownload;
    QRadioButton *rbFromFile;
    QLabel *label;
    SKG_Button *btnCancel;

    void setupUi(QDialog *frmAlbumArtDialog)
    {
        if (frmAlbumArtDialog->objectName().isEmpty())
            frmAlbumArtDialog->setObjectName(QString::fromUtf8("frmAlbumArtDialog"));
        frmAlbumArtDialog->resize(351, 265);
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
        frmAlbumArtDialog->setPalette(palette);
        frmAlbumArtDialog->setWindowTitle(QString::fromUtf8(""));
        frame = new QFrame(frmAlbumArtDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 345, 261));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        btnOK = new SKG_Button(frame);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(240, 190, 101, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        btnOK->setFont(font);
        btnOK->setAutoFillBackground(true);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 50, 331, 111));
        frame_2->setAutoFillBackground(true);
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        rbDownload = new QRadioButton(frame_2);
        rbDownload->setObjectName(QString::fromUtf8("rbDownload"));
        rbDownload->setGeometry(QRect(10, 20, 291, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bitstream Charter"));
        font1.setPointSize(12);
        rbDownload->setFont(font1);
        rbDownload->setMouseTracking(true);
        rbDownload->setAutoFillBackground(false);
        rbDownload->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        rbFromFile = new QRadioButton(frame_2);
        rbFromFile->setObjectName(QString::fromUtf8("rbFromFile"));
        rbFromFile->setGeometry(QRect(10, 60, 291, 22));
        rbFromFile->setFont(font1);
        rbFromFile->setMouseTracking(true);
        rbFromFile->setAutoFillBackground(false);
        rbFromFile->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 331, 31));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Digital-7"));
        font2.setPointSize(22);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        btnCancel = new SKG_Button(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(10, 190, 101, 61));
        btnCancel->setFont(font);
        btnCancel->setAutoFillBackground(true);

        retranslateUi(frmAlbumArtDialog);

        QMetaObject::connectSlotsByName(frmAlbumArtDialog);
    } // setupUi

    void retranslateUi(QDialog *frmAlbumArtDialog)
    {
        btnOK->setText(QApplication::translate("frmAlbumArtDialog", "OK", 0, QApplication::UnicodeUTF8));
        rbDownload->setText(QApplication::translate("frmAlbumArtDialog", "Download Album Art from Internet", 0, QApplication::UnicodeUTF8));
        rbFromFile->setText(QApplication::translate("frmAlbumArtDialog", "Assign Album Art From File", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmAlbumArtDialog", "Choose an option", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("frmAlbumArtDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(frmAlbumArtDialog);
    } // retranslateUi

};

namespace Ui {
    class frmAlbumArtDialog: public Ui_frmAlbumArtDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMALBUMARTDIALOG_H
