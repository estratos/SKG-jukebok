/********************************************************************************
** Form generated from reading UI file 'frmconfig.ui'
**
** Created: Tue Jul 19 22:09:10 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCONFIG_H
#define UI_FRMCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmConfig
{
public:
    QFrame *frame;
    QLabel *label;
    SKG_Button *btnSave;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_3;
    QListWidget *listMusicDirs;
    QLabel *label_2;
    QFrame *frameOperatingMode;
    QRadioButton *rbNormal;
    QRadioButton *rbNetbook;
    SKG_Button *btnAddDirectory;
    SKG_Button *btnRemoveDirectory;
    QCheckBox *chkConnected;
    QFrame *frameOperatingMode_2;
    QRadioButton *rbSmall;
    QRadioButton *rbLarge;
    QLabel *label_5;
    QCheckBox *chkSlidingSound;
    QCheckBox *chkRandom;
    QCheckBox *chkAnimation;
    QWidget *tab_2;
    QListWidget *listCustomLists;
    QLabel *label_4;
    SKG_Button *btnAddList;
    SKG_Button *btnEditList;
    SKG_Button *btnDeleteList;
    QWidget *tab_3;
    QListWidget *listPlaylists;
    SKG_Button *btnEditPlaylist;
    SKG_Button *btnDeletePlaylist;
    QLabel *lblAvailablePlaylists;
    SKG_Button *btnAddPlaylist;
    QWidget *tab_4;
    QLabel *label_6;
    QGroupBox *gbKeyin;
    QComboBox *cbKeyin;
    QCheckBox *chkKeyinCtrl;
    QCheckBox *chkKeyinAlt;
    QCheckBox *chkKeyinShift;
    QGroupBox *gbMapto;
    QComboBox *cbMapto;
    SKG_Button *btnClearKeys;
    SKG_Button *btnAddKey;
    QLabel *lblKeyStatus;
    SKG_Button *btnViewKeyMappings;
    QFrame *line;
    SKG_Button *btnCancel;

    void setupUi(QDialog *frmConfig)
    {
        if (frmConfig->objectName().isEmpty())
            frmConfig->setObjectName(QString::fromUtf8("frmConfig"));
        frmConfig->resize(600, 520);
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
        frmConfig->setPalette(palette);
        frame = new QFrame(frmConfig);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 591, 511));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 600, 31));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Digital-7"));
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        btnSave = new SKG_Button(frame);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(470, 440, 111, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        btnSave->setFont(font1);
        btnSave->setAutoFillBackground(true);
        btnSave->setFrameShadow(QFrame::Raised);
        btnSave->setWordWrap(true);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(5, 40, 591, 391));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Andale Mono"));
        font2.setPointSize(10);
        tabWidget->setFont(font2);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 80, 251, 17));
        listMusicDirs = new QListWidget(tab);
        listMusicDirs->setObjectName(QString::fromUtf8("listMusicDirs"));
        listMusicDirs->setGeometry(QRect(10, 100, 256, 191));
        listMusicDirs->setWordWrap(true);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 251, 17));
        frameOperatingMode = new QFrame(tab);
        frameOperatingMode->setObjectName(QString::fromUtf8("frameOperatingMode"));
        frameOperatingMode->setGeometry(QRect(5, 30, 261, 41));
        frameOperatingMode->setAutoFillBackground(false);
        frameOperatingMode->setFrameShape(QFrame::Box);
        frameOperatingMode->setFrameShadow(QFrame::Plain);
        rbNormal = new QRadioButton(frameOperatingMode);
        rbNormal->setObjectName(QString::fromUtf8("rbNormal"));
        rbNormal->setGeometry(QRect(10, 10, 111, 22));
        rbNormal->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        rbNetbook = new QRadioButton(frameOperatingMode);
        rbNetbook->setObjectName(QString::fromUtf8("rbNetbook"));
        rbNetbook->setGeometry(QRect(130, 10, 91, 22));
        rbNetbook->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        btnAddDirectory = new SKG_Button(tab);
        btnAddDirectory->setObjectName(QString::fromUtf8("btnAddDirectory"));
        btnAddDirectory->setGeometry(QRect(10, 300, 111, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        btnAddDirectory->setFont(font3);
        btnAddDirectory->setAutoFillBackground(false);
        btnAddDirectory->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        btnRemoveDirectory = new SKG_Button(tab);
        btnRemoveDirectory->setObjectName(QString::fromUtf8("btnRemoveDirectory"));
        btnRemoveDirectory->setGeometry(QRect(150, 300, 111, 61));
        btnRemoveDirectory->setFont(font3);
        btnRemoveDirectory->setAutoFillBackground(false);
        btnRemoveDirectory->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        chkConnected = new QCheckBox(tab);
        chkConnected->setObjectName(QString::fromUtf8("chkConnected"));
        chkConnected->setGeometry(QRect(280, 140, 281, 17));
        frameOperatingMode_2 = new QFrame(tab);
        frameOperatingMode_2->setObjectName(QString::fromUtf8("frameOperatingMode_2"));
        frameOperatingMode_2->setGeometry(QRect(280, 30, 291, 91));
        frameOperatingMode_2->setAutoFillBackground(false);
        frameOperatingMode_2->setFrameShape(QFrame::Box);
        frameOperatingMode_2->setFrameShadow(QFrame::Plain);
        rbSmall = new QRadioButton(frameOperatingMode_2);
        rbSmall->setObjectName(QString::fromUtf8("rbSmall"));
        rbSmall->setGeometry(QRect(10, 10, 201, 22));
        rbSmall->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        rbLarge = new QRadioButton(frameOperatingMode_2);
        rbLarge->setObjectName(QString::fromUtf8("rbLarge"));
        rbLarge->setGeometry(QRect(10, 50, 221, 22));
        rbLarge->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(290, 10, 251, 17));
        chkSlidingSound = new QCheckBox(tab);
        chkSlidingSound->setObjectName(QString::fromUtf8("chkSlidingSound"));
        chkSlidingSound->setGeometry(QRect(280, 170, 281, 22));
        chkRandom = new QCheckBox(tab);
        chkRandom->setObjectName(QString::fromUtf8("chkRandom"));
        chkRandom->setGeometry(QRect(280, 250, 291, 17));
        chkAnimation = new QCheckBox(tab);
        chkAnimation->setObjectName(QString::fromUtf8("chkAnimation"));
        chkAnimation->setGeometry(QRect(280, 210, 281, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        listCustomLists = new QListWidget(tab_2);
        listCustomLists->setObjectName(QString::fromUtf8("listCustomLists"));
        listCustomLists->setGeometry(QRect(5, 30, 341, 320));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 251, 17));
        btnAddList = new SKG_Button(tab_2);
        btnAddList->setObjectName(QString::fromUtf8("btnAddList"));
        btnAddList->setGeometry(QRect(360, 30, 101, 61));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        btnAddList->setFont(font4);
        btnAddList->setAutoFillBackground(false);
        btnAddList->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        btnEditList = new SKG_Button(tab_2);
        btnEditList->setObjectName(QString::fromUtf8("btnEditList"));
        btnEditList->setGeometry(QRect(360, 100, 101, 61));
        btnEditList->setFont(font4);
        btnEditList->setAutoFillBackground(false);
        btnEditList->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        btnDeleteList = new SKG_Button(tab_2);
        btnDeleteList->setObjectName(QString::fromUtf8("btnDeleteList"));
        btnDeleteList->setGeometry(QRect(360, 170, 101, 61));
        btnDeleteList->setFont(font4);
        btnDeleteList->setAutoFillBackground(false);
        btnDeleteList->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        listPlaylists = new QListWidget(tab_3);
        listPlaylists->setObjectName(QString::fromUtf8("listPlaylists"));
        listPlaylists->setGeometry(QRect(5, 30, 341, 320));
        btnEditPlaylist = new SKG_Button(tab_3);
        btnEditPlaylist->setObjectName(QString::fromUtf8("btnEditPlaylist"));
        btnEditPlaylist->setGeometry(QRect(360, 100, 101, 61));
        btnEditPlaylist->setFont(font4);
        btnEditPlaylist->setAutoFillBackground(false);
        btnEditPlaylist->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        btnDeletePlaylist = new SKG_Button(tab_3);
        btnDeletePlaylist->setObjectName(QString::fromUtf8("btnDeletePlaylist"));
        btnDeletePlaylist->setGeometry(QRect(360, 170, 101, 61));
        btnDeletePlaylist->setFont(font4);
        btnDeletePlaylist->setAutoFillBackground(false);
        btnDeletePlaylist->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        lblAvailablePlaylists = new QLabel(tab_3);
        lblAvailablePlaylists->setObjectName(QString::fromUtf8("lblAvailablePlaylists"));
        lblAvailablePlaylists->setGeometry(QRect(10, 10, 571, 17));
        btnAddPlaylist = new SKG_Button(tab_3);
        btnAddPlaylist->setObjectName(QString::fromUtf8("btnAddPlaylist"));
        btnAddPlaylist->setGeometry(QRect(360, 30, 101, 61));
        btnAddPlaylist->setFont(font4);
        btnAddPlaylist->setAutoFillBackground(false);
        btnAddPlaylist->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 571, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Times New Roman"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        label_6->setFont(font5);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);
        gbKeyin = new QGroupBox(tab_4);
        gbKeyin->setObjectName(QString::fromUtf8("gbKeyin"));
        gbKeyin->setGeometry(QRect(10, 80, 271, 111));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(12);
        gbKeyin->setFont(font6);
        cbKeyin = new QComboBox(gbKeyin);
        cbKeyin->setObjectName(QString::fromUtf8("cbKeyin"));
        cbKeyin->setGeometry(QRect(10, 30, 171, 31));
        cbKeyin->setStyleSheet(QString::fromUtf8("color : black;\n"
"background : white"));
        chkKeyinCtrl = new QCheckBox(gbKeyin);
        chkKeyinCtrl->setObjectName(QString::fromUtf8("chkKeyinCtrl"));
        chkKeyinCtrl->setGeometry(QRect(10, 70, 71, 22));
        chkKeyinAlt = new QCheckBox(gbKeyin);
        chkKeyinAlt->setObjectName(QString::fromUtf8("chkKeyinAlt"));
        chkKeyinAlt->setGeometry(QRect(100, 70, 71, 22));
        chkKeyinShift = new QCheckBox(gbKeyin);
        chkKeyinShift->setObjectName(QString::fromUtf8("chkKeyinShift"));
        chkKeyinShift->setGeometry(QRect(190, 70, 71, 22));
        gbMapto = new QGroupBox(tab_4);
        gbMapto->setObjectName(QString::fromUtf8("gbMapto"));
        gbMapto->setGeometry(QRect(300, 80, 271, 111));
        gbMapto->setFont(font6);
        cbMapto = new QComboBox(gbMapto);
        cbMapto->setObjectName(QString::fromUtf8("cbMapto"));
        cbMapto->setGeometry(QRect(0, 30, 271, 31));
        cbMapto->setStyleSheet(QString::fromUtf8("color : black;\n"
"background : white"));
        btnClearKeys = new SKG_Button(tab_4);
        btnClearKeys->setObjectName(QString::fromUtf8("btnClearKeys"));
        btnClearKeys->setGeometry(QRect(10, 260, 131, 81));
        QPalette palette2;
        QBrush brush4(QColor(170, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        btnClearKeys->setPalette(palette2);
        QFont font7;
        font7.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        btnClearKeys->setFont(font7);
        btnClearKeys->setAutoFillBackground(false);
        btnClearKeys->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        btnClearKeys->setWordWrap(true);
        btnAddKey = new SKG_Button(tab_4);
        btnAddKey->setObjectName(QString::fromUtf8("btnAddKey"));
        btnAddKey->setGeometry(QRect(440, 260, 131, 81));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        btnAddKey->setPalette(palette3);
        btnAddKey->setAutoFillBackground(false);
        btnAddKey->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        lblKeyStatus = new QLabel(tab_4);
        lblKeyStatus->setObjectName(QString::fromUtf8("lblKeyStatus"));
        lblKeyStatus->setGeometry(QRect(10, 210, 571, 17));
        btnViewKeyMappings = new SKG_Button(tab_4);
        btnViewKeyMappings->setObjectName(QString::fromUtf8("btnViewKeyMappings"));
        btnViewKeyMappings->setGeometry(QRect(160, 260, 131, 81));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        btnViewKeyMappings->setPalette(palette4);
        btnViewKeyMappings->setFont(font7);
        btnViewKeyMappings->setAutoFillBackground(false);
        btnViewKeyMappings->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:rgb(170,0,0)"));
        btnViewKeyMappings->setWordWrap(true);
        tabWidget->addTab(tab_4, QString());
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 32, 600, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btnCancel = new SKG_Button(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(10, 440, 111, 61));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font8.setPointSize(17);
        font8.setBold(true);
        font8.setItalic(false);
        font8.setWeight(75);
        btnCancel->setFont(font8);
        btnCancel->setAutoFillBackground(true);
#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(frmConfig);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmConfig);
    } // setupUi

    void retranslateUi(QDialog *frmConfig)
    {
        frmConfig->setWindowTitle(QApplication::translate("frmConfig", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmConfig", "Configuration", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("frmConfig", "Save and Exit", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("frmConfig", "Music Directories", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("frmConfig", "Operating Mode", 0, QApplication::UnicodeUTF8));
        rbNormal->setText(QApplication::translate("frmConfig", "Normal", 0, QApplication::UnicodeUTF8));
        rbNetbook->setText(QApplication::translate("frmConfig", "Netbook", 0, QApplication::UnicodeUTF8));
        btnAddDirectory->setText(QApplication::translate("frmConfig", "Add", 0, QApplication::UnicodeUTF8));
        btnRemoveDirectory->setText(QApplication::translate("frmConfig", "Remove", 0, QApplication::UnicodeUTF8));
        chkConnected->setText(QApplication::translate("frmConfig", "Jukebox is connected to the Internet", 0, QApplication::UnicodeUTF8));
        rbSmall->setText(QApplication::translate("frmConfig", "Small (Less than 1000 albums)", 0, QApplication::UnicodeUTF8));
        rbLarge->setText(QApplication::translate("frmConfig", "Large (1000-9999 albums)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("frmConfig", "Collection Size", 0, QApplication::UnicodeUTF8));
        chkSlidingSound->setText(QApplication::translate("frmConfig", "Play Album Sliding Sound", 0, QApplication::UnicodeUTF8));
        chkRandom->setText(QApplication::translate("frmConfig", "Play Random Track when Idle", 0, QApplication::UnicodeUTF8));
        chkAnimation->setText(QApplication::translate("frmConfig", "Play Album Sliding Animation", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("frmConfig", "General", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("frmConfig", "Available Lists", 0, QApplication::UnicodeUTF8));
        btnAddList->setText(QApplication::translate("frmConfig", "Add", 0, QApplication::UnicodeUTF8));
        btnEditList->setText(QApplication::translate("frmConfig", "Edit", 0, QApplication::UnicodeUTF8));
        btnDeleteList->setText(QApplication::translate("frmConfig", "Delete", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("frmConfig", "Custom Album Lists", 0, QApplication::UnicodeUTF8));
        btnEditPlaylist->setText(QApplication::translate("frmConfig", "Edit", 0, QApplication::UnicodeUTF8));
        btnDeletePlaylist->setText(QApplication::translate("frmConfig", "Delete", 0, QApplication::UnicodeUTF8));
        lblAvailablePlaylists->setText(QApplication::translate("frmConfig", "Available Playlists", 0, QApplication::UnicodeUTF8));
        btnAddPlaylist->setText(QApplication::translate("frmConfig", "Add", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("frmConfig", "Playlists", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("frmConfig", "Select the keystroke being entered, and the key you wish to map it to, and press \"Add\"", 0, QApplication::UnicodeUTF8));
        gbKeyin->setTitle(QApplication::translate("frmConfig", "Keystroke Entered", 0, QApplication::UnicodeUTF8));
        chkKeyinCtrl->setText(QApplication::translate("frmConfig", "Ctrl", 0, QApplication::UnicodeUTF8));
        chkKeyinAlt->setText(QApplication::translate("frmConfig", "Alt", 0, QApplication::UnicodeUTF8));
        chkKeyinShift->setText(QApplication::translate("frmConfig", "Shift", 0, QApplication::UnicodeUTF8));
        gbMapto->setTitle(QApplication::translate("frmConfig", "Map To", 0, QApplication::UnicodeUTF8));
        btnClearKeys->setText(QApplication::translate("frmConfig", "Clear Custom Keys", 0, QApplication::UnicodeUTF8));
        btnAddKey->setText(QApplication::translate("frmConfig", "Add", 0, QApplication::UnicodeUTF8));
        lblKeyStatus->setText(QString());
        btnViewKeyMappings->setText(QApplication::translate("frmConfig", "View Current Key Mappings", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("frmConfig", "Key Mapper", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("frmConfig", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmConfig: public Ui_frmConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCONFIG_H
