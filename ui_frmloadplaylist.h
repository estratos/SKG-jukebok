/********************************************************************************
** Form generated from reading UI file 'frmloadplaylist.ui'
**
** Created: Tue Jul 19 22:09:10 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOADPLAYLIST_H
#define UI_FRMLOADPLAYLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmLoadPlaylist
{
public:
    QFrame *frame;
    QTextEdit *txtTracks;
    QCheckBox *chkRandom;
    SKG_Button *btnLoad;
    QLabel *label_2;
    QComboBox *cmbPlaylists;
    QLabel *label;
    SKG_Button *btnExit;
    QFrame *line;

    void setupUi(QDialog *frmLoadPlaylist)
    {
        if (frmLoadPlaylist->objectName().isEmpty())
            frmLoadPlaylist->setObjectName(QString::fromUtf8("frmLoadPlaylist"));
        frmLoadPlaylist->resize(500, 412);
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
        frmLoadPlaylist->setPalette(palette);
        frame = new QFrame(frmLoadPlaylist);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 493, 403));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        txtTracks = new QTextEdit(frame);
        txtTracks->setObjectName(QString::fromUtf8("txtTracks"));
        txtTracks->setGeometry(QRect(5, 88, 341, 271));
        txtTracks->setFrameShape(QFrame::Box);
        txtTracks->setFrameShadow(QFrame::Plain);
        txtTracks->setReadOnly(true);
        chkRandom = new QCheckBox(frame);
        chkRandom->setObjectName(QString::fromUtf8("chkRandom"));
        chkRandom->setGeometry(QRect(10, 368, 321, 22));
        chkRandom->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white\n"
""));
        btnLoad = new SKG_Button(frame);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setGeometry(QRect(360, 88, 121, 81));
        btnLoad->setAutoFillBackground(true);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(5, 38, 341, 17));
        cmbPlaylists = new QComboBox(frame);
        cmbPlaylists->setObjectName(QString::fromUtf8("cmbPlaylists"));
        cmbPlaylists->setGeometry(QRect(2, 58, 341, 27));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -2, 500, 31));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        QBrush brush4(QColor(133, 131, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Digital-7"));
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        btnExit = new SKG_Button(frame);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(360, 308, 121, 81));
        btnExit->setAutoFillBackground(true);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 30, 500, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(frmLoadPlaylist);

        QMetaObject::connectSlotsByName(frmLoadPlaylist);
    } // setupUi

    void retranslateUi(QDialog *frmLoadPlaylist)
    {
        frmLoadPlaylist->setWindowTitle(QApplication::translate("frmLoadPlaylist", "Dialog", 0, QApplication::UnicodeUTF8));
        chkRandom->setText(QApplication::translate("frmLoadPlaylist", "Play in Random Order", 0, QApplication::UnicodeUTF8));
        btnLoad->setText(QApplication::translate("frmLoadPlaylist", "Load", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("frmLoadPlaylist", "Choose a playlist to load", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmLoadPlaylist", "Load playlist", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("frmLoadPlaylist", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmLoadPlaylist: public Ui_frmLoadPlaylist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOADPLAYLIST_H
