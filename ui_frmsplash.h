/********************************************************************************
** Form generated from reading UI file 'frmsplash.ui'
**
** Created: Tue Jul 19 22:09:10 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSPLASH_H
#define UI_FRMSPLASH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmSplash
{
public:
    QFrame *frame;
    QLabel *lblLoading;
    QFrame *frameFirstTime;
    QLabel *lblInstructions;
    QLineEdit *txtMusicDir;
    QLabel *label_2;
    SKG_Button *btnChoose;
    QGroupBox *gbOperatingMode;
    QRadioButton *rbNormal;
    QRadioButton *rbNetbook;
    SKG_Button *btnOK;
    QCheckBox *chkConnected;
    QGroupBox *gbSize;
    QRadioButton *rbSmall;
    QRadioButton *rbLarge;
    QLabel *label;
    QLabel *lblVersion;

    void setupUi(QDialog *frmSplash)
    {
        if (frmSplash->objectName().isEmpty())
            frmSplash->setObjectName(QString::fromUtf8("frmSplash"));
        frmSplash->resize(800, 600);
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
        frmSplash->setPalette(palette);
        frame = new QFrame(frmSplash);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 791, 591));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        lblLoading = new QLabel(frame);
        lblLoading->setObjectName(QString::fromUtf8("lblLoading"));
        lblLoading->setGeometry(QRect(10, 500, 721, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        lblLoading->setFont(font);
        lblLoading->setAlignment(Qt::AlignCenter);
        frameFirstTime = new QFrame(frame);
        frameFirstTime->setObjectName(QString::fromUtf8("frameFirstTime"));
        frameFirstTime->setGeometry(QRect(40, 150, 721, 331));
        frameFirstTime->setFrameShape(QFrame::StyledPanel);
        frameFirstTime->setFrameShadow(QFrame::Raised);
        lblInstructions = new QLabel(frameFirstTime);
        lblInstructions->setObjectName(QString::fromUtf8("lblInstructions"));
        lblInstructions->setGeometry(QRect(10, -10, 701, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        lblInstructions->setFont(font1);
        lblInstructions->setAlignment(Qt::AlignCenter);
        lblInstructions->setWordWrap(true);
        txtMusicDir = new QLineEdit(frameFirstTime);
        txtMusicDir->setObjectName(QString::fromUtf8("txtMusicDir"));
        txtMusicDir->setGeometry(QRect(10, 120, 241, 27));
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
        txtMusicDir->setPalette(palette1);
        label_2 = new QLabel(frameFirstTime);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 241, 17));
        btnChoose = new SKG_Button(frameFirstTime);
        btnChoose->setObjectName(QString::fromUtf8("btnChoose"));
        btnChoose->setGeometry(QRect(260, 100, 101, 56));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Andale Mono"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        btnChoose->setFont(font2);
        btnChoose->setAutoFillBackground(true);
        gbOperatingMode = new QGroupBox(frameFirstTime);
        gbOperatingMode->setObjectName(QString::fromUtf8("gbOperatingMode"));
        gbOperatingMode->setGeometry(QRect(10, 160, 241, 101));
        gbOperatingMode->setStyleSheet(QString::fromUtf8("background : black;\n"
"color : white;\n"
"border-color : white;\n"
"border-width : 1px;\n"
"border-style : solid"));
        rbNormal = new QRadioButton(gbOperatingMode);
        rbNormal->setObjectName(QString::fromUtf8("rbNormal"));
        rbNormal->setGeometry(QRect(10, 30, 151, 22));
        rbNormal->setStyleSheet(QString::fromUtf8("border-style : none"));
        rbNetbook = new QRadioButton(gbOperatingMode);
        rbNetbook->setObjectName(QString::fromUtf8("rbNetbook"));
        rbNetbook->setGeometry(QRect(10, 60, 151, 22));
        rbNetbook->setStyleSheet(QString::fromUtf8("border-style : none"));
        btnOK = new SKG_Button(frameFirstTime);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(590, 250, 121, 71));
        btnOK->setAutoFillBackground(true);
        chkConnected = new QCheckBox(frameFirstTime);
        chkConnected->setObjectName(QString::fromUtf8("chkConnected"));
        chkConnected->setGeometry(QRect(370, 120, 301, 17));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        chkConnected->setPalette(palette2);
        chkConnected->setStyleSheet(QString::fromUtf8("background : black;\n"
"color : white;"));
        chkConnected->setChecked(true);
        gbSize = new QGroupBox(frameFirstTime);
        gbSize->setObjectName(QString::fromUtf8("gbSize"));
        gbSize->setGeometry(QRect(260, 160, 261, 101));
        gbSize->setStyleSheet(QString::fromUtf8("background : black;\n"
"color : white;\n"
"border-color : white;\n"
"border-width : 1px;\n"
"border-style : solid"));
        rbSmall = new QRadioButton(gbSize);
        rbSmall->setObjectName(QString::fromUtf8("rbSmall"));
        rbSmall->setGeometry(QRect(10, 30, 241, 22));
        rbSmall->setStyleSheet(QString::fromUtf8("border-style : none"));
        rbLarge = new QRadioButton(gbSize);
        rbLarge->setObjectName(QString::fromUtf8("rbLarge"));
        rbLarge->setGeometry(QRect(10, 60, 231, 22));
        rbLarge->setStyleSheet(QString::fromUtf8("border-style : none"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 791, 111));
        QPalette palette3;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        QBrush brush4(QColor(170, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        label->setPalette(palette3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Digital-7"));
        font3.setPointSize(72);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        lblVersion = new QLabel(frame);
        lblVersion->setObjectName(QString::fromUtf8("lblVersion"));
        lblVersion->setGeometry(QRect(180, 110, 431, 17));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        lblVersion->setFont(font4);
        lblVersion->setAlignment(Qt::AlignCenter);

        retranslateUi(frmSplash);

        QMetaObject::connectSlotsByName(frmSplash);
    } // setupUi

    void retranslateUi(QDialog *frmSplash)
    {
        frmSplash->setWindowTitle(QApplication::translate("frmSplash", "Dialog", 0, QApplication::UnicodeUTF8));
        lblLoading->setText(QApplication::translate("frmSplash", "Loading music library. Please wait.", 0, QApplication::UnicodeUTF8));
        lblInstructions->setText(QApplication::translate("frmSplash", "This appears to be the first time you have run SKG Jukebox. Please choose a primary music directory and an operating mode, and click OK. Uncheck the box if jukebox is not connected to the Internet. Keep in mind that some advanced features, such as album art downloading and CD ripping will not work if jukebox is not connected.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("frmSplash", "Music Directory", 0, QApplication::UnicodeUTF8));
        btnChoose->setText(QApplication::translate("frmSplash", "Choose", 0, QApplication::UnicodeUTF8));
        gbOperatingMode->setTitle(QApplication::translate("frmSplash", "Operating Mode", 0, QApplication::UnicodeUTF8));
        rbNormal->setText(QApplication::translate("frmSplash", "Normal", 0, QApplication::UnicodeUTF8));
        rbNetbook->setText(QApplication::translate("frmSplash", "Netbook", 0, QApplication::UnicodeUTF8));
        btnOK->setText(QApplication::translate("frmSplash", "OK", 0, QApplication::UnicodeUTF8));
        chkConnected->setText(QApplication::translate("frmSplash", "Jukebox is connected to the Internet", 0, QApplication::UnicodeUTF8));
        gbSize->setTitle(QApplication::translate("frmSplash", "Collection Size", 0, QApplication::UnicodeUTF8));
        rbSmall->setText(QApplication::translate("frmSplash", "Small (Less than 1000 albums)", 0, QApplication::UnicodeUTF8));
        rbLarge->setText(QApplication::translate("frmSplash", "Large 1000 - 9999 albums", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmSplash", "SKG Jukebox", 0, QApplication::UnicodeUTF8));
        lblVersion->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmSplash: public Ui_frmSplash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSPLASH_H
