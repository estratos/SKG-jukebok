/********************************************************************************
** Form generated from reading UI file 'frmalbumartmulti.ui'
**
** Created: Tue Jul 19 22:09:10 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMALBUMARTMULTI_H
#define UI_FRMALBUMARTMULTI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QRadioButton>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmAlbumArtMulti
{
public:
    QFrame *frame;
    QListWidget *listAlbums;
    QFrame *line;
    QLabel *lblInstructions;
    SKG_Button *btnDownload;
    QFrame *frame_2;
    QLabel *lblStatus;
    SKG_Button *btnSave;
    SKG_Button *btnExit;
    QLabel *lblInfo;
    QLabel *lblArt;
    SKG_Button *btnNext;
    SKG_Button *btnPrev;
    SKG_Button *btnNextAlbum;
    QFrame *frame_3;
    QRadioButton *rbNoArt;
    QRadioButton *rbShowAll;
    SKG_Button *btnUp;
    SKG_Button *btnDown;
    QLabel *label;
    SKG_Button *btnToggle;

    void setupUi(QDialog *frmAlbumArtMulti)
    {
        if (frmAlbumArtMulti->objectName().isEmpty())
            frmAlbumArtMulti->setObjectName(QString::fromUtf8("frmAlbumArtMulti"));
        frmAlbumArtMulti->resize(800, 584);
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
        frmAlbumArtMulti->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        frmAlbumArtMulti->setFont(font);
        frame = new QFrame(frmAlbumArtMulti);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 795, 581));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        listAlbums = new QListWidget(frame);
        listAlbums->setObjectName(QString::fromUtf8("listAlbums"));
        listAlbums->setGeometry(QRect(5, 110, 261, 381));
        listAlbums->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listAlbums->setWordWrap(true);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 35, 900, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lblInstructions = new QLabel(frame);
        lblInstructions->setObjectName(QString::fromUtf8("lblInstructions"));
        lblInstructions->setGeometry(QRect(5, 40, 391, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        lblInstructions->setFont(font1);
        lblInstructions->setFrameShape(QFrame::Box);
        lblInstructions->setAlignment(Qt::AlignCenter);
        lblInstructions->setWordWrap(true);
        btnDownload = new SKG_Button(frame);
        btnDownload->setObjectName(QString::fromUtf8("btnDownload"));
        btnDownload->setGeometry(QRect(270, 420, 121, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        btnDownload->setFont(font2);
        btnDownload->setAutoFillBackground(true);
        btnDownload->setWordWrap(true);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(400, 40, 391, 535));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        lblStatus = new QLabel(frame_2);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setGeometry(QRect(5, 5, 380, 71));
        QFont font3;
        font3.setPointSize(12);
        lblStatus->setFont(font3);
        lblStatus->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblStatus->setWordWrap(true);
        btnSave = new SKG_Button(frame_2);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(260, 250, 111, 75));
        QFont font4;
        font4.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        btnSave->setFont(font4);
        btnSave->setAutoFillBackground(true);
        btnSave->setWordWrap(true);
        btnExit = new SKG_Button(frame_2);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(240, 440, 131, 81));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font5.setPointSize(22);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        btnExit->setFont(font5);
        btnExit->setAutoFillBackground(true);
        btnExit->setWordWrap(true);
        lblInfo = new QLabel(frame_2);
        lblInfo->setObjectName(QString::fromUtf8("lblInfo"));
        lblInfo->setGeometry(QRect(0, 330, 251, 71));
        lblInfo->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        lblArt = new QLabel(frame_2);
        lblArt->setObjectName(QString::fromUtf8("lblArt"));
        lblArt->setGeometry(QRect(5, 80, 250, 250));
        lblArt->setFrameShape(QFrame::Box);
        lblArt->setScaledContents(true);
        lblArt->setAlignment(Qt::AlignCenter);
        btnNext = new SKG_Button(frame_2);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(260, 150, 111, 60));
        btnNext->setAutoFillBackground(true);
        btnNext->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-right.jpg")));
        btnPrev = new SKG_Button(frame_2);
        btnPrev->setObjectName(QString::fromUtf8("btnPrev"));
        btnPrev->setGeometry(QRect(260, 80, 111, 60));
        btnPrev->setAutoFillBackground(true);
        btnPrev->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-left.jpg")));
        btnNextAlbum = new SKG_Button(frame_2);
        btnNextAlbum->setObjectName(QString::fromUtf8("btnNextAlbum"));
        btnNextAlbum->setGeometry(QRect(10, 445, 131, 81));
        btnNextAlbum->setFont(font5);
        btnNextAlbum->setAutoFillBackground(true);
        btnNextAlbum->setWordWrap(true);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(5, 500, 381, 75));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        rbNoArt = new QRadioButton(frame_3);
        rbNoArt->setObjectName(QString::fromUtf8("rbNoArt"));
        rbNoArt->setGeometry(QRect(10, 10, 361, 22));
        rbNoArt->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        rbShowAll = new QRadioButton(frame_3);
        rbShowAll->setObjectName(QString::fromUtf8("rbShowAll"));
        rbShowAll->setGeometry(QRect(20, 40, 351, 22));
        rbShowAll->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        btnUp = new SKG_Button(frame);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));
        btnUp->setGeometry(QRect(270, 110, 121, 71));
        btnUp->setAutoFillBackground(true);
        btnUp->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-up.jpg")));
        btnDown = new SKG_Button(frame);
        btnDown->setObjectName(QString::fromUtf8("btnDown"));
        btnDown->setGeometry(QRect(270, 190, 121, 71));
        btnDown->setAutoFillBackground(true);
        btnDown->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-down.jpg")));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 901, 31));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        label->setPalette(palette1);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Digital-7"));
        font6.setPointSize(24);
        label->setFont(font6);
        label->setAlignment(Qt::AlignCenter);
        btnToggle = new SKG_Button(frame);
        btnToggle->setObjectName(QString::fromUtf8("btnToggle"));
        btnToggle->setGeometry(QRect(270, 270, 121, 71));
        QFont font7;
        font7.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font7.setPointSize(18);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        btnToggle->setFont(font7);
        btnToggle->setAutoFillBackground(true);

        retranslateUi(frmAlbumArtMulti);

        QMetaObject::connectSlotsByName(frmAlbumArtMulti);
    } // setupUi

    void retranslateUi(QDialog *frmAlbumArtMulti)
    {
        frmAlbumArtMulti->setWindowTitle(QApplication::translate("frmAlbumArtMulti", "Dialog", 0, QApplication::UnicodeUTF8));
        lblInstructions->setText(QApplication::translate("frmAlbumArtMulti", "Check the albums you wish to download cover art for and press \"Download Now\". By default, all albums without cover art are checked.", 0, QApplication::UnicodeUTF8));
        btnDownload->setText(QApplication::translate("frmAlbumArtMulti", "Download Now", 0, QApplication::UnicodeUTF8));
        lblStatus->setText(QString());
        btnSave->setText(QApplication::translate("frmAlbumArtMulti", "Save as Album Art", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("frmAlbumArtMulti", "Exit", 0, QApplication::UnicodeUTF8));
        lblInfo->setText(QString());
        lblArt->setText(QString());
        btnNext->setText(QString());
        btnPrev->setText(QString());
        btnNextAlbum->setText(QApplication::translate("frmAlbumArtMulti", "Next Album", 0, QApplication::UnicodeUTF8));
        rbNoArt->setText(QApplication::translate("frmAlbumArtMulti", "Show Only Albums without Album Art", 0, QApplication::UnicodeUTF8));
        rbShowAll->setText(QApplication::translate("frmAlbumArtMulti", "Show All Albums", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmAlbumArtMulti", "Album Art -- Select Albums", 0, QApplication::UnicodeUTF8));
        btnToggle->setText(QApplication::translate("frmAlbumArtMulti", "Check", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmAlbumArtMulti: public Ui_frmAlbumArtMulti {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMALBUMARTMULTI_H
