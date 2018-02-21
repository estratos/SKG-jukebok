/********************************************************************************
** Form generated from reading UI file 'frmrip.ui'
**
** Created: Tue Jul 19 22:09:11 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMRIP_H
#define UI_FRMRIP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QRadioButton>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_FrmRip
{
public:
    QFrame *frame;
    QLabel *lblTracksInfo;
    QLabel *label_3;
    QFrame *line;
    QLineEdit *txtArtist;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *txtGenre;
    QLabel *label_5;
    QListWidget *listTracks;
    SKG_Button *btnRip;
    QLineEdit *txtYear;
    QLineEdit *txtTitle;
    SKG_Button *btnExit;
    QLabel *label_6;
    QLabel *label;
    QLabel *lblStatus;
    QLabel *lblHeader;
    QFrame *frameMode;
    QRadioButton *rbMp3;
    QRadioButton *rbOgg;
    QRadioButton *rbFlac;

    void setupUi(QDialog *FrmRip)
    {
        if (FrmRip->objectName().isEmpty())
            FrmRip->setObjectName(QString::fromUtf8("FrmRip"));
        FrmRip->setWindowModality(Qt::NonModal);
        FrmRip->resize(800, 570);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(122, 122, 122, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        FrmRip->setPalette(palette);
        FrmRip->setAutoFillBackground(false);
        frame = new QFrame(FrmRip);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 793, 561));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        lblTracksInfo = new QLabel(frame);
        lblTracksInfo->setObjectName(QString::fromUtf8("lblTracksInfo"));
        lblTracksInfo->setGeometry(QRect(10, 510, 301, 17));
        lblTracksInfo->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 201, 17));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 32, 800, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        txtArtist = new QLineEdit(frame);
        txtArtist->setObjectName(QString::fromUtf8("txtArtist"));
        txtArtist->setGeometry(QRect(10, 60, 301, 27));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        txtArtist->setPalette(palette1);
        txtArtist->setReadOnly(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 40, 471, 17));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 90, 62, 17));
        txtGenre = new QLineEdit(frame);
        txtGenre->setObjectName(QString::fromUtf8("txtGenre"));
        txtGenre->setGeometry(QRect(10, 110, 201, 27));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        txtGenre->setPalette(palette2);
        txtGenre->setReadOnly(true);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 170, 301, 17));
        listTracks = new QListWidget(frame);
        listTracks->setObjectName(QString::fromUtf8("listTracks"));
        listTracks->setGeometry(QRect(10, 190, 301, 321));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        listTracks->setPalette(palette3);
        listTracks->setWordWrap(true);
        btnRip = new SKG_Button(frame);
        btnRip->setObjectName(QString::fromUtf8("btnRip"));
        btnRip->setEnabled(false);
        btnRip->setGeometry(QRect(660, 370, 121, 71));
        btnRip->setAutoFillBackground(true);
        txtYear = new QLineEdit(frame);
        txtYear->setObjectName(QString::fromUtf8("txtYear"));
        txtYear->setGeometry(QRect(320, 110, 113, 27));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        txtYear->setPalette(palette4);
        txtYear->setReadOnly(true);
        txtTitle = new QLineEdit(frame);
        txtTitle->setObjectName(QString::fromUtf8("txtTitle"));
        txtTitle->setGeometry(QRect(320, 60, 471, 27));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        txtTitle->setPalette(palette5);
        txtTitle->setReadOnly(true);
        btnExit = new SKG_Button(frame);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(660, 460, 121, 71));
        btnExit->setAutoFillBackground(true);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 190, 201, 17));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 301, 17));
        lblStatus = new QLabel(frame);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setGeometry(QRect(0, 545, 801, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        lblStatus->setFont(font);
        lblStatus->setFrameShape(QFrame::Box);
        lblHeader = new QLabel(frame);
        lblHeader->setObjectName(QString::fromUtf8("lblHeader"));
        lblHeader->setGeometry(QRect(0, 0, 800, 31));
        QPalette palette6;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        QBrush brush4(QColor(133, 131, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        lblHeader->setPalette(palette6);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Digital-7"));
        font1.setPointSize(22);
        lblHeader->setFont(font1);
        lblHeader->setAlignment(Qt::AlignCenter);
        frameMode = new QFrame(frame);
        frameMode->setObjectName(QString::fromUtf8("frameMode"));
        frameMode->setGeometry(QRect(320, 210, 201, 111));
        frameMode->setFrameShape(QFrame::Box);
        frameMode->setFrameShadow(QFrame::Raised);
        rbMp3 = new QRadioButton(frameMode);
        rbMp3->setObjectName(QString::fromUtf8("rbMp3"));
        rbMp3->setGeometry(QRect(10, 10, 109, 22));
        rbMp3->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        rbOgg = new QRadioButton(frameMode);
        rbOgg->setObjectName(QString::fromUtf8("rbOgg"));
        rbOgg->setGeometry(QRect(10, 40, 109, 22));
        rbOgg->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        rbFlac = new QRadioButton(frameMode);
        rbFlac->setObjectName(QString::fromUtf8("rbFlac"));
        rbFlac->setGeometry(QRect(10, 70, 109, 22));
        rbFlac->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));

        retranslateUi(FrmRip);

        QMetaObject::connectSlotsByName(FrmRip);
    } // setupUi

    void retranslateUi(QDialog *FrmRip)
    {
        FrmRip->setWindowTitle(QApplication::translate("FrmRip", "Dialog", 0, QApplication::UnicodeUTF8));
        lblTracksInfo->setText(QString());
        label_3->setText(QApplication::translate("FrmRip", "Genre", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FrmRip", "Album", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FrmRip", "Year", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FrmRip", "Track Information", 0, QApplication::UnicodeUTF8));
        btnRip->setText(QApplication::translate("FrmRip", "Rip CD", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("FrmRip", "Exit", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FrmRip", "Choose Encoding Format", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FrmRip", "Artist", 0, QApplication::UnicodeUTF8));
        lblStatus->setText(QString());
        lblHeader->setText(QApplication::translate("FrmRip", "Add CD to library", 0, QApplication::UnicodeUTF8));
        rbMp3->setText(QApplication::translate("FrmRip", "mp3", 0, QApplication::UnicodeUTF8));
        rbOgg->setText(QApplication::translate("FrmRip", "ogg", 0, QApplication::UnicodeUTF8));
        rbFlac->setText(QApplication::translate("FrmRip", "flac", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmRip: public Ui_FrmRip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMRIP_H
