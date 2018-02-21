/********************************************************************************
** Form generated from reading UI file 'frmoptions.ui'
**
** Created: Tue Jul 19 22:09:09 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMOPTIONS_H
#define UI_FRMOPTIONS_H

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

class Ui_frmOptions
{
public:
    QFrame *frame;
    QLabel *label;
    QFrame *line;
    SKG_Button *btnConfig;
    SKG_Button *btnRipper;
    SKG_Button *btnArt;
    SKG_Button *btnCancel;
    SKG_Button *btnCustomLists;
    SKG_Button *btnExit;
    SKG_Button *btnLoadPlaylist;
    SKG_Button *btnHelp;
    SKG_Button *btnSearch;
    SKG_Button *btnAddToPlaylist;
    SKG_Button *btnMinimize;
    SKG_Button *btnAbout;
    SKG_Button *btnRescan;

    void setupUi(QDialog *frmOptions)
    {
        if (frmOptions->objectName().isEmpty())
            frmOptions->setObjectName(QString::fromUtf8("frmOptions"));
        frmOptions->resize(500, 530);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmOptions->sizePolicy().hasHeightForWidth());
        frmOptions->setSizePolicy(sizePolicy);
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
        QBrush brush2(QColor(133, 131, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frmOptions->setPalette(palette);
        frame = new QFrame(frmOptions);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(5, 5, 491, 521));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(1);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 501, 41));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Digital-7"));
        font.setPointSize(28);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignCenter);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 501, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btnConfig = new SKG_Button(frame);
        btnConfig->setObjectName(QString::fromUtf8("btnConfig"));
        btnConfig->setGeometry(QRect(10, 60, 151, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        btnConfig->setFont(font1);
        btnConfig->setAutoFillBackground(true);
        btnConfig->setAlignment(Qt::AlignCenter);
        btnRipper = new SKG_Button(frame);
        btnRipper->setObjectName(QString::fromUtf8("btnRipper"));
        btnRipper->setGeometry(QRect(170, 60, 151, 81));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        btnRipper->setFont(font2);
        btnRipper->setAutoFillBackground(true);
        btnRipper->setAlignment(Qt::AlignCenter);
        btnArt = new SKG_Button(frame);
        btnArt->setObjectName(QString::fromUtf8("btnArt"));
        btnArt->setGeometry(QRect(330, 60, 151, 81));
        btnArt->setFont(font2);
        btnArt->setAutoFillBackground(true);
        btnArt->setAlignment(Qt::AlignCenter);
        btnCancel = new SKG_Button(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(10, 430, 151, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        btnCancel->setFont(font3);
        btnCancel->setAutoFillBackground(true);
        btnCustomLists = new SKG_Button(frame);
        btnCustomLists->setObjectName(QString::fromUtf8("btnCustomLists"));
        btnCustomLists->setGeometry(QRect(10, 150, 151, 81));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        btnCustomLists->setFont(font4);
        btnCustomLists->setAutoFillBackground(true);
        btnCustomLists->setAlignment(Qt::AlignCenter);
        btnCustomLists->setWordWrap(true);
        btnExit = new SKG_Button(frame);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(330, 430, 151, 81));
        btnExit->setFont(font4);
        btnExit->setAutoFillBackground(true);
        btnLoadPlaylist = new SKG_Button(frame);
        btnLoadPlaylist->setObjectName(QString::fromUtf8("btnLoadPlaylist"));
        btnLoadPlaylist->setGeometry(QRect(170, 150, 151, 81));
        btnLoadPlaylist->setFont(font4);
        btnLoadPlaylist->setAutoFillBackground(true);
        btnLoadPlaylist->setAlignment(Qt::AlignCenter);
        btnLoadPlaylist->setWordWrap(true);
        btnHelp = new SKG_Button(frame);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        btnHelp->setGeometry(QRect(330, 240, 151, 81));
        btnHelp->setFont(font2);
        btnHelp->setAutoFillBackground(true);
        btnHelp->setAlignment(Qt::AlignCenter);
        btnHelp->setWordWrap(true);
        btnSearch = new SKG_Button(frame);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setGeometry(QRect(10, 240, 151, 81));
        btnSearch->setFont(font2);
        btnSearch->setAutoFillBackground(true);
        btnSearch->setAlignment(Qt::AlignCenter);
        btnSearch->setWordWrap(true);
        btnAddToPlaylist = new SKG_Button(frame);
        btnAddToPlaylist->setObjectName(QString::fromUtf8("btnAddToPlaylist"));
        btnAddToPlaylist->setGeometry(QRect(330, 150, 151, 81));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        btnAddToPlaylist->setFont(font5);
        btnAddToPlaylist->setAutoFillBackground(true);
        btnAddToPlaylist->setAlignment(Qt::AlignCenter);
        btnAddToPlaylist->setWordWrap(true);
        btnMinimize = new SKG_Button(frame);
        btnMinimize->setObjectName(QString::fromUtf8("btnMinimize"));
        btnMinimize->setGeometry(QRect(170, 240, 151, 81));
        btnMinimize->setFont(font2);
        btnMinimize->setAutoFillBackground(true);
        btnMinimize->setAlignment(Qt::AlignCenter);
        btnMinimize->setWordWrap(true);
        btnAbout = new SKG_Button(frame);
        btnAbout->setObjectName(QString::fromUtf8("btnAbout"));
        btnAbout->setGeometry(QRect(10, 330, 151, 81));
        btnAbout->setFont(font3);
        btnAbout->setAutoFillBackground(true);
        btnRescan = new SKG_Button(frame);
        btnRescan->setObjectName(QString::fromUtf8("btnRescan"));
        btnRescan->setGeometry(QRect(330, 330, 151, 81));
        QFont font6;
        font6.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font6.setPointSize(16);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        btnRescan->setFont(font6);
        btnRescan->setAutoFillBackground(true);
        btnRescan->setAlignment(Qt::AlignCenter);
        btnRescan->setWordWrap(true);

        retranslateUi(frmOptions);

        QMetaObject::connectSlotsByName(frmOptions);
    } // setupUi

    void retranslateUi(QDialog *frmOptions)
    {
        frmOptions->setWindowTitle(QApplication::translate("frmOptions", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmOptions", "Options", 0, QApplication::UnicodeUTF8));
        btnConfig->setText(QApplication::translate("frmOptions", "Configuration", 0, QApplication::UnicodeUTF8));
        btnRipper->setText(QApplication::translate("frmOptions", "Rip CD", 0, QApplication::UnicodeUTF8));
        btnArt->setText(QApplication::translate("frmOptions", "Album Art", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("frmOptions", "Cancel", 0, QApplication::UnicodeUTF8));
        btnCustomLists->setText(QApplication::translate("frmOptions", "Load Custom List", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("frmOptions", "Exit Jukebox", 0, QApplication::UnicodeUTF8));
        btnLoadPlaylist->setText(QApplication::translate("frmOptions", "Load Playlist", 0, QApplication::UnicodeUTF8));
        btnHelp->setText(QApplication::translate("frmOptions", "Help", 0, QApplication::UnicodeUTF8));
        btnSearch->setText(QApplication::translate("frmOptions", "Search for Track", 0, QApplication::UnicodeUTF8));
        btnAddToPlaylist->setText(QApplication::translate("frmOptions", "Add Current Track to Playlist", 0, QApplication::UnicodeUTF8));
        btnMinimize->setText(QApplication::translate("frmOptions", "Minimize Jukebox", 0, QApplication::UnicodeUTF8));
        btnAbout->setText(QApplication::translate("frmOptions", "About", 0, QApplication::UnicodeUTF8));
        btnRescan->setText(QApplication::translate("frmOptions", "Rescan Music Library", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmOptions: public Ui_frmOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMOPTIONS_H
