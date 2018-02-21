/********************************************************************************
** Form generated from reading UI file 'frmaddtoplaylist.ui'
**
** Created: Tue Jul 19 22:09:11 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMADDTOPLAYLIST_H
#define UI_FRMADDTOPLAYLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_FrmAddToPlaylist
{
public:
    QFrame *frame;
    SKG_Button *btnAdd;
    QCheckBox *chkSelectAll;
    QLabel *lblInstructions;
    QLabel *lblHeader;
    SKG_Button *btnCancel;
    QListWidget *listPlaylists;
    QFrame *line;

    void setupUi(QDialog *FrmAddToPlaylist)
    {
        if (FrmAddToPlaylist->objectName().isEmpty())
            FrmAddToPlaylist->setObjectName(QString::fromUtf8("FrmAddToPlaylist"));
        FrmAddToPlaylist->resize(500, 450);
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
        FrmAddToPlaylist->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        FrmAddToPlaylist->setFont(font);
        frame = new QFrame(FrmAddToPlaylist);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 496, 446));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btnAdd = new SKG_Button(frame);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(370, 378, 121, 61));
        btnAdd->setAutoFillBackground(true);
        chkSelectAll = new QCheckBox(frame);
        chkSelectAll->setObjectName(QString::fromUtf8("chkSelectAll"));
        chkSelectAll->setGeometry(QRect(10, 138, 171, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font1.setPointSize(12);
        chkSelectAll->setFont(font1);
        chkSelectAll->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white\n"
""));
        lblInstructions = new QLabel(frame);
        lblInstructions->setObjectName(QString::fromUtf8("lblInstructions"));
        lblInstructions->setGeometry(QRect(5, 48, 490, 81));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lblInstructions->setFont(font2);
        lblInstructions->setFrameShape(QFrame::Box);
        lblInstructions->setAlignment(Qt::AlignCenter);
        lblInstructions->setWordWrap(true);
        lblHeader = new QLabel(frame);
        lblHeader->setObjectName(QString::fromUtf8("lblHeader"));
        lblHeader->setGeometry(QRect(0, 8, 500, 31));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        QBrush brush4(QColor(133, 131, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        lblHeader->setPalette(palette1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Digital-7"));
        font3.setPointSize(22);
        lblHeader->setFont(font3);
        lblHeader->setAlignment(Qt::AlignCenter);
        btnCancel = new SKG_Button(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(10, 378, 121, 61));
        btnCancel->setAutoFillBackground(true);
        listPlaylists = new QListWidget(frame);
        listPlaylists->setObjectName(QString::fromUtf8("listPlaylists"));
        listPlaylists->setGeometry(QRect(10, 169, 480, 201));
        QFont font4;
        font4.setPointSize(12);
        listPlaylists->setFont(font4);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 500, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(FrmAddToPlaylist);

        QMetaObject::connectSlotsByName(FrmAddToPlaylist);
    } // setupUi

    void retranslateUi(QDialog *FrmAddToPlaylist)
    {
        FrmAddToPlaylist->setWindowTitle(QApplication::translate("FrmAddToPlaylist", "Dialog", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("FrmAddToPlaylist", "Add", 0, QApplication::UnicodeUTF8));
        chkSelectAll->setText(QApplication::translate("FrmAddToPlaylist", "Select All", 0, QApplication::UnicodeUTF8));
        lblInstructions->setText(QString());
        lblHeader->setText(QApplication::translate("FrmAddToPlaylist", "Add Current Track to Playist", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("FrmAddToPlaylist", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmAddToPlaylist: public Ui_FrmAddToPlaylist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMADDTOPLAYLIST_H
