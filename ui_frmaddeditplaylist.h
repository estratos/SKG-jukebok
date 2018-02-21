/********************************************************************************
** Form generated from reading UI file 'frmaddeditplaylist.ui'
**
** Created: Tue Jul 19 22:09:10 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMADDEDITPLAYLIST_H
#define UI_FRMADDEDITPLAYLIST_H

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
#include <QtGui/QTreeWidget>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmAddEditPlaylist
{
public:
    QFrame *frame;
    QLineEdit *txtName;
    SKG_Button *btnRemoveTracks;
    SKG_Button *btnCancel;
    QLabel *label_3;
    SKG_Button *btnAddTracks;
    QFrame *line;
    SKG_Button *btnSave;
    QTreeWidget *treeAvailableTracks;
    QLabel *lblHeader;
    QListWidget *listTracksInList;
    QLabel *label_2;
    SKG_Button *btnMoveTrackDown;
    QLabel *label_4;
    SKG_Button *btnMoveTrackUp;
    SKG_Button *btnKeyboard;

    void setupUi(QDialog *frmAddEditPlaylist)
    {
        if (frmAddEditPlaylist->objectName().isEmpty())
            frmAddEditPlaylist->setObjectName(QString::fromUtf8("frmAddEditPlaylist"));
        frmAddEditPlaylist->resize(800, 580);
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
        frmAddEditPlaylist->setPalette(palette);
        frame = new QFrame(frmAddEditPlaylist);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 791, 571));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        txtName = new QLineEdit(frame);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setGeometry(QRect(10, 60, 281, 27));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        txtName->setPalette(palette1);
        txtName->setStyleSheet(QString::fromUtf8("background:black;\n"
"color:white"));
        btnRemoveTracks = new SKG_Button(frame);
        btnRemoveTracks->setObjectName(QString::fromUtf8("btnRemoveTracks"));
        btnRemoveTracks->setGeometry(QRect(300, 260, 81, 71));
        btnRemoveTracks->setAutoFillBackground(true);
        btnRemoveTracks->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-left.jpg")));
        btnCancel = new SKG_Button(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(10, 490, 121, 71));
        btnCancel->setAutoFillBackground(true);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 301, 17));
        btnAddTracks = new SKG_Button(frame);
        btnAddTracks->setObjectName(QString::fromUtf8("btnAddTracks"));
        btnAddTracks->setGeometry(QRect(300, 180, 81, 71));
        btnAddTracks->setAutoFillBackground(true);
        btnAddTracks->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-right.jpg")));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 32, 800, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btnSave = new SKG_Button(frame);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(550, 490, 121, 71));
        btnSave->setAutoFillBackground(true);
        treeAvailableTracks = new QTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeAvailableTracks->setHeaderItem(__qtreewidgetitem);
        treeAvailableTracks->setObjectName(QString::fromUtf8("treeAvailableTracks"));
        treeAvailableTracks->setGeometry(QRect(10, 120, 281, 361));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        treeAvailableTracks->setFont(font);
        treeAvailableTracks->setFrameShape(QFrame::Box);
        treeAvailableTracks->setFrameShadow(QFrame::Plain);
        treeAvailableTracks->header()->setVisible(false);
        lblHeader = new QLabel(frame);
        lblHeader->setObjectName(QString::fromUtf8("lblHeader"));
        lblHeader->setGeometry(QRect(0, 0, 800, 31));
        QPalette palette2;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        QBrush brush4(QColor(133, 131, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        lblHeader->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Digital-7"));
        font1.setPointSize(22);
        lblHeader->setFont(font1);
        lblHeader->setAlignment(Qt::AlignCenter);
        listTracksInList = new QListWidget(frame);
        listTracksInList->setObjectName(QString::fromUtf8("listTracksInList"));
        listTracksInList->setGeometry(QRect(390, 120, 281, 361));
        listTracksInList->setFont(font);
        listTracksInList->setFrameShape(QFrame::Box);
        listTracksInList->setFrameShadow(QFrame::Plain);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 211, 17));
        btnMoveTrackDown = new SKG_Button(frame);
        btnMoveTrackDown->setObjectName(QString::fromUtf8("btnMoveTrackDown"));
        btnMoveTrackDown->setGeometry(QRect(680, 270, 101, 81));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        btnMoveTrackDown->setFont(font2);
        btnMoveTrackDown->setAutoFillBackground(true);
        btnMoveTrackDown->setWordWrap(true);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(390, 100, 281, 17));
        btnMoveTrackUp = new SKG_Button(frame);
        btnMoveTrackUp->setObjectName(QString::fromUtf8("btnMoveTrackUp"));
        btnMoveTrackUp->setGeometry(QRect(680, 170, 101, 81));
        btnMoveTrackUp->setFont(font2);
        btnMoveTrackUp->setAutoFillBackground(true);
        btnMoveTrackUp->setWordWrap(true);
        btnKeyboard = new SKG_Button(frame);
        btnKeyboard->setObjectName(QString::fromUtf8("btnKeyboard"));
        btnKeyboard->setGeometry(QRect(280, 490, 121, 71));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        btnKeyboard->setFont(font3);
        btnKeyboard->setAutoFillBackground(true);
        btnKeyboard->setWordWrap(true);

        retranslateUi(frmAddEditPlaylist);

        QMetaObject::connectSlotsByName(frmAddEditPlaylist);
    } // setupUi

    void retranslateUi(QDialog *frmAddEditPlaylist)
    {
        frmAddEditPlaylist->setWindowTitle(QApplication::translate("frmAddEditPlaylist", "Dialog", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("frmAddEditPlaylist", "Cancel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("frmAddEditPlaylist", "Available Tracks", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("frmAddEditPlaylist", "Save", 0, QApplication::UnicodeUTF8));
        lblHeader->setText(QApplication::translate("frmAddEditPlaylist", "Add Playist", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("frmAddEditPlaylist", "List Name", 0, QApplication::UnicodeUTF8));
        btnMoveTrackDown->setText(QApplication::translate("frmAddEditPlaylist", "Move Track Down List", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("frmAddEditPlaylist", "Tracks in List", 0, QApplication::UnicodeUTF8));
        btnMoveTrackUp->setText(QApplication::translate("frmAddEditPlaylist", "Move Track Up List", 0, QApplication::UnicodeUTF8));
        btnKeyboard->setText(QApplication::translate("frmAddEditPlaylist", "Onscreen Keyboard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmAddEditPlaylist: public Ui_frmAddEditPlaylist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMADDEDITPLAYLIST_H
