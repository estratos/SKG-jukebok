/********************************************************************************
** Form generated from reading UI file 'frmtracklist.ui'
**
** Created: Tue Jul 19 22:09:09 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTRACKLIST_H
#define UI_FRMTRACKLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_frmTrackList
{
public:
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *ListTracks;
    QHBoxLayout *horizontalLayout;
    SKG_Button *btnUp;
    QSpacerItem *horizontalSpacer;
    SKG_Button *btnDown;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblArt;
    QLabel *lblMetaData;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    SKG_Button *btnRemoveTrack;
    SKG_Button *btmMoveToTop;
    SKG_Button *btnMoveTrackUp;
    SKG_Button *btnMoveTrackDown;
    SKG_Button *btnPlayNow;
    SKG_Button *btnPause;
    SKG_Button *btnClearList;
    SKG_Button *btnShuffle;
    QHBoxLayout *horizontalLayout_3;
    SKG_Button *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    SKG_Button *btnSave;

    void setupUi(QDialog *frmTrackList)
    {
        if (frmTrackList->objectName().isEmpty())
            frmTrackList->setObjectName(QString::fromUtf8("frmTrackList"));
        frmTrackList->resize(800, 600);
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
        frmTrackList->setPalette(palette);
        frmTrackList->setAutoFillBackground(true);
        frmTrackList->setModal(true);
        frame = new QFrame(frmTrackList);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 796, 601));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
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
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        ListTracks = new QListWidget(frame);
        ListTracks->setObjectName(QString::fromUtf8("ListTracks"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ListTracks->sizePolicy().hasHeightForWidth());
        ListTracks->setSizePolicy(sizePolicy);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        ListTracks->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Digital-7"));
        font1.setPointSize(16);
        ListTracks->setFont(font1);

        verticalLayout->addWidget(ListTracks);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnUp = new SKG_Button(frame);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));
        btnUp->setAutoFillBackground(true);
        btnUp->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-up.jpg")));

        horizontalLayout->addWidget(btnUp);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnDown = new SKG_Button(frame);
        btnDown->setObjectName(QString::fromUtf8("btnDown"));
        btnDown->setAutoFillBackground(true);
        btnDown->setPixmap(QPixmap(QString::fromUtf8("resources/arrow-bold-down.jpg")));

        horizontalLayout->addWidget(btnDown);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 11);
        verticalLayout->setStretch(2, 2);

        horizontalLayout_4->addLayout(verticalLayout);

        frame1 = new QFrame(frame);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setFrameShape(QFrame::Box);
        frame1->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblArt = new QLabel(frame1);
        lblArt->setObjectName(QString::fromUtf8("lblArt"));
        lblArt->setFrameShape(QFrame::NoFrame);
        lblArt->setScaledContents(true);

        horizontalLayout_2->addWidget(lblArt);

        lblMetaData = new QLabel(frame1);
        lblMetaData->setObjectName(QString::fromUtf8("lblMetaData"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("FreeSerif"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        lblMetaData->setFont(font2);
        lblMetaData->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        lblMetaData->setWordWrap(true);

        horizontalLayout_2->addWidget(lblMetaData);


        verticalLayout_3->addLayout(horizontalLayout_2);

        line = new QFrame(frame1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnRemoveTrack = new SKG_Button(frame1);
        btnRemoveTrack->setObjectName(QString::fromUtf8("btnRemoveTrack"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        btnRemoveTrack->setFont(font3);
        btnRemoveTrack->setAutoFillBackground(true);
        btnRemoveTrack->setWordWrap(true);

        gridLayout->addWidget(btnRemoveTrack, 2, 0, 1, 1);

        btmMoveToTop = new SKG_Button(frame1);
        btmMoveToTop->setObjectName(QString::fromUtf8("btmMoveToTop"));
        btmMoveToTop->setFont(font3);
        btmMoveToTop->setAutoFillBackground(true);
        btmMoveToTop->setWordWrap(true);

        gridLayout->addWidget(btmMoveToTop, 0, 2, 1, 1);

        btnMoveTrackUp = new SKG_Button(frame1);
        btnMoveTrackUp->setObjectName(QString::fromUtf8("btnMoveTrackUp"));
        btnMoveTrackUp->setFont(font3);
        btnMoveTrackUp->setAutoFillBackground(true);
        btnMoveTrackUp->setWordWrap(true);

        gridLayout->addWidget(btnMoveTrackUp, 0, 0, 1, 1);

        btnMoveTrackDown = new SKG_Button(frame1);
        btnMoveTrackDown->setObjectName(QString::fromUtf8("btnMoveTrackDown"));
        btnMoveTrackDown->setFont(font3);
        btnMoveTrackDown->setAutoFillBackground(true);
        btnMoveTrackDown->setWordWrap(true);

        gridLayout->addWidget(btnMoveTrackDown, 0, 1, 1, 1);

        btnPlayNow = new SKG_Button(frame1);
        btnPlayNow->setObjectName(QString::fromUtf8("btnPlayNow"));
        btnPlayNow->setFont(font3);
        btnPlayNow->setAutoFillBackground(true);
        btnPlayNow->setWordWrap(true);

        gridLayout->addWidget(btnPlayNow, 1, 0, 1, 1);

        btnPause = new SKG_Button(frame1);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setFont(font3);
        btnPause->setAutoFillBackground(true);
        btnPause->setWordWrap(true);

        gridLayout->addWidget(btnPause, 1, 2, 1, 1);

        btnClearList = new SKG_Button(frame1);
        btnClearList->setObjectName(QString::fromUtf8("btnClearList"));
        btnClearList->setFont(font3);
        btnClearList->setAutoFillBackground(true);
        btnClearList->setWordWrap(true);

        gridLayout->addWidget(btnClearList, 2, 2, 1, 1);

        btnShuffle = new SKG_Button(frame1);
        btnShuffle->setObjectName(QString::fromUtf8("btnShuffle"));
        btnShuffle->setFont(font3);
        btnShuffle->setAutoFillBackground(true);
        btnShuffle->setWordWrap(true);

        gridLayout->addWidget(btnShuffle, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);

        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnCancel = new SKG_Button(frame1);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        btnCancel->setFont(font4);
        btnCancel->setAutoFillBackground(true);

        horizontalLayout_3->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnSave = new SKG_Button(frame1);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font5.setPointSize(20);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        btnSave->setFont(font5);
        btnSave->setAutoFillBackground(true);
        btnSave->setWordWrap(true);

        horizontalLayout_3->addWidget(btnSave);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 5);

        horizontalLayout_4->addWidget(frame1);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 5);

        retranslateUi(frmTrackList);

        QMetaObject::connectSlotsByName(frmTrackList);
    } // setupUi

    void retranslateUi(QDialog *frmTrackList)
    {
        frmTrackList->setWindowTitle(QApplication::translate("frmTrackList", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("frmTrackList", "Track List", 0, QApplication::UnicodeUTF8));
        lblArt->setText(QString());
        lblMetaData->setText(QApplication::translate("frmTrackList", "TextLabel", 0, QApplication::UnicodeUTF8));
        btnRemoveTrack->setText(QApplication::translate("frmTrackList", "Remove Track From List", 0, QApplication::UnicodeUTF8));
        btmMoveToTop->setText(QApplication::translate("frmTrackList", "Move to Top of List", 0, QApplication::UnicodeUTF8));
        btnMoveTrackUp->setText(QApplication::translate("frmTrackList", "Move Track Up List", 0, QApplication::UnicodeUTF8));
        btnMoveTrackDown->setText(QApplication::translate("frmTrackList", "Move Track Down List", 0, QApplication::UnicodeUTF8));
        btnPlayNow->setText(QApplication::translate("frmTrackList", "Play Now", 0, QApplication::UnicodeUTF8));
        btnPause->setText(QApplication::translate("frmTrackList", "Pause Current Track", 0, QApplication::UnicodeUTF8));
        btnClearList->setText(QApplication::translate("frmTrackList", "Clear Track List", 0, QApplication::UnicodeUTF8));
        btnShuffle->setText(QApplication::translate("frmTrackList", "Shufle Track List", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("frmTrackList", "Cancel", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("frmTrackList", "Save and Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmTrackList: public Ui_frmTrackList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTRACKLIST_H
