/********************************************************************************
** Form generated from reading UI file 'mainnormal.ui'
**
** Created: Tue Jul 19 22:09:09 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINNORMAL_H
#define UI_MAINNORMAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "SKG_AlbumPanel/skg_albumpanel.h"
#include "SKG_AlbumWidget/skg_albumwidget.h"
#include "SKG_Button/skg_button.h"
#include "SKG_RoundButton/skg_roundbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainNormal
{
public:
    QWidget *centralwidget;
    QFrame *frameSelectedAlbum;
    QHBoxLayout *horizontalLayout_4;
    SKG_AlbumWidget *SelectedAlbumWidget;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    SKG_Button *btnAddTrack;
    SKG_Button *btnCancelTrack;
    SKG_AlbumPanel *prevPanel;
    SKG_AlbumPanel *nextPanel;
    QFrame *Frame1;
    QVBoxLayout *verticalLayout_3;
    QFrame *frameLetterButtons;
    QHBoxLayout *horizontalLayout;
    SKG_RoundButton *rb_0thru9;
    SKG_RoundButton *rb_A;
    SKG_RoundButton *rb_B;
    SKG_RoundButton *rb_C;
    SKG_RoundButton *rb_D;
    SKG_RoundButton *rb_E;
    SKG_RoundButton *rb_F;
    SKG_RoundButton *rb_G;
    SKG_RoundButton *rb_H;
    SKG_RoundButton *rb_I;
    SKG_RoundButton *rb_J;
    SKG_RoundButton *rb_K;
    SKG_RoundButton *rb_L;
    SKG_RoundButton *rb_M;
    SKG_RoundButton *rb_N;
    SKG_RoundButton *rb_O;
    SKG_RoundButton *rb_P;
    SKG_RoundButton *rb_Q;
    SKG_RoundButton *rb_R;
    SKG_RoundButton *rb_S;
    SKG_RoundButton *rb_T;
    SKG_RoundButton *rb_U;
    SKG_RoundButton *rb_V;
    SKG_RoundButton *rb_W;
    SKG_RoundButton *rb_X;
    SKG_RoundButton *rb_Y;
    SKG_RoundButton *rb_Z;
    SKG_AlbumPanel *currPanel;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frameTrackList;
    QVBoxLayout *verticalLayout;
    QLabel *lblTrackString;
    QFrame *line;
    QLabel *lblTrackList;
    QFrame *frameNowPlaying;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblCurrTrackArt;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QFrame *line_2;
    QLabel *lblCurrArtist;
    QLabel *lblCurrTrackName;
    QLabel *lblCurrTrackData;
    QLabel *lblCurrTrackTime;
    QFrame *frameButtons;
    QGridLayout *gridLayout;
    SKG_Button *btn_1;
    SKG_Button *btn_2;
    SKG_Button *btn_3;
    SKG_Button *btn_4;
    SKG_Button *btn_5;
    SKG_Button *btn_Next;
    SKG_Button *btn_6;
    SKG_Button *btn_7;
    SKG_Button *btn_8;
    SKG_Button *btn_9;
    SKG_Button *btn_0;
    SKG_Button *btn_Prev;

    void setupUi(QMainWindow *MainNormal)
    {
        if (MainNormal->objectName().isEmpty())
            MainNormal->setObjectName(QString::fromUtf8("MainNormal"));
        MainNormal->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainNormal->sizePolicy().hasHeightForWidth());
        MainNormal->setSizePolicy(sizePolicy);
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
        MainNormal->setPalette(palette);
        MainNormal->setAutoFillBackground(true);
        centralwidget = new QWidget(MainNormal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        frameSelectedAlbum = new QFrame(centralwidget);
        frameSelectedAlbum->setObjectName(QString::fromUtf8("frameSelectedAlbum"));
        frameSelectedAlbum->setGeometry(QRect(20, 614, 232, 144));
        frameSelectedAlbum->setAutoFillBackground(true);
        frameSelectedAlbum->setFrameShape(QFrame::Box);
        frameSelectedAlbum->setFrameShadow(QFrame::Raised);
        frameSelectedAlbum->setLineWidth(1);
        frameSelectedAlbum->setMidLineWidth(0);
        horizontalLayout_4 = new QHBoxLayout(frameSelectedAlbum);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        SelectedAlbumWidget = new SKG_AlbumWidget(frameSelectedAlbum);
        SelectedAlbumWidget->setObjectName(QString::fromUtf8("SelectedAlbumWidget"));
        SelectedAlbumWidget->setFrameShape(QFrame::NoFrame);

        horizontalLayout_4->addWidget(SelectedAlbumWidget);

        horizontalSpacer = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        btnAddTrack = new SKG_Button(frameSelectedAlbum);
        btnAddTrack->setObjectName(QString::fromUtf8("btnAddTrack"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        btnAddTrack->setFont(font);
        btnAddTrack->setAutoFillBackground(true);
        btnAddTrack->setTextFormat(Qt::AutoText);
        btnAddTrack->setScaledContents(false);
        btnAddTrack->setAlignment(Qt::AlignCenter);
        btnAddTrack->setWordWrap(true);

        verticalLayout_4->addWidget(btnAddTrack);

        btnCancelTrack = new SKG_Button(frameSelectedAlbum);
        btnCancelTrack->setObjectName(QString::fromUtf8("btnCancelTrack"));
        btnCancelTrack->setFont(font);
        btnCancelTrack->setAutoFillBackground(true);
        btnCancelTrack->setTextFormat(Qt::AutoText);
        btnCancelTrack->setScaledContents(false);
        btnCancelTrack->setAlignment(Qt::AlignCenter);
        btnCancelTrack->setWordWrap(true);

        verticalLayout_4->addWidget(btnCancelTrack);

        verticalLayout_4->setStretch(0, 2);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 1);

        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalLayout_4->setStretch(0, 9);
        horizontalLayout_4->setStretch(1, 3);
        horizontalLayout_4->setStretch(2, 2);
        prevPanel = new SKG_AlbumPanel(centralwidget);
        prevPanel->setObjectName(QString::fromUtf8("prevPanel"));
        prevPanel->setGeometry(QRect(10, 614, 1019, 10));
        nextPanel = new SKG_AlbumPanel(centralwidget);
        nextPanel->setObjectName(QString::fromUtf8("nextPanel"));
        nextPanel->setGeometry(QRect(10, 630, 1019, 10));
        Frame1 = new QFrame(centralwidget);
        Frame1->setObjectName(QString::fromUtf8("Frame1"));
        Frame1->setGeometry(QRect(2, 2, 574, 212));
        Frame1->setFrameShape(QFrame::Box);
        Frame1->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(Frame1);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frameLetterButtons = new QFrame(Frame1);
        frameLetterButtons->setObjectName(QString::fromUtf8("frameLetterButtons"));
        sizePolicy.setHeightForWidth(frameLetterButtons->sizePolicy().hasHeightForWidth());
        frameLetterButtons->setSizePolicy(sizePolicy);
        frameLetterButtons->setFrameShape(QFrame::NoFrame);
        frameLetterButtons->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frameLetterButtons);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rb_0thru9 = new SKG_RoundButton(frameLetterButtons);
        rb_0thru9->setObjectName(QString::fromUtf8("rb_0thru9"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        rb_0thru9->setFont(font1);
        rb_0thru9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_0thru9);

        rb_A = new SKG_RoundButton(frameLetterButtons);
        rb_A->setObjectName(QString::fromUtf8("rb_A"));
        rb_A->setFont(font1);
        rb_A->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_A);

        rb_B = new SKG_RoundButton(frameLetterButtons);
        rb_B->setObjectName(QString::fromUtf8("rb_B"));
        rb_B->setFont(font1);
        rb_B->setAutoFillBackground(true);
        rb_B->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_B);

        rb_C = new SKG_RoundButton(frameLetterButtons);
        rb_C->setObjectName(QString::fromUtf8("rb_C"));
        rb_C->setFont(font1);
        rb_C->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_C);

        rb_D = new SKG_RoundButton(frameLetterButtons);
        rb_D->setObjectName(QString::fromUtf8("rb_D"));
        rb_D->setFont(font1);
        rb_D->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_D);

        rb_E = new SKG_RoundButton(frameLetterButtons);
        rb_E->setObjectName(QString::fromUtf8("rb_E"));
        rb_E->setFont(font1);
        rb_E->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_E);

        rb_F = new SKG_RoundButton(frameLetterButtons);
        rb_F->setObjectName(QString::fromUtf8("rb_F"));
        rb_F->setFont(font1);
        rb_F->setLineWidth(1);
        rb_F->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_F);

        rb_G = new SKG_RoundButton(frameLetterButtons);
        rb_G->setObjectName(QString::fromUtf8("rb_G"));
        rb_G->setFont(font1);
        rb_G->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_G);

        rb_H = new SKG_RoundButton(frameLetterButtons);
        rb_H->setObjectName(QString::fromUtf8("rb_H"));
        rb_H->setFont(font1);
        rb_H->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_H);

        rb_I = new SKG_RoundButton(frameLetterButtons);
        rb_I->setObjectName(QString::fromUtf8("rb_I"));
        rb_I->setFont(font1);
        rb_I->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_I);

        rb_J = new SKG_RoundButton(frameLetterButtons);
        rb_J->setObjectName(QString::fromUtf8("rb_J"));
        rb_J->setFont(font1);
        rb_J->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_J);

        rb_K = new SKG_RoundButton(frameLetterButtons);
        rb_K->setObjectName(QString::fromUtf8("rb_K"));
        rb_K->setFont(font1);
        rb_K->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_K);

        rb_L = new SKG_RoundButton(frameLetterButtons);
        rb_L->setObjectName(QString::fromUtf8("rb_L"));
        rb_L->setFont(font1);
        rb_L->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_L);

        rb_M = new SKG_RoundButton(frameLetterButtons);
        rb_M->setObjectName(QString::fromUtf8("rb_M"));
        rb_M->setFont(font1);
        rb_M->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_M);

        rb_N = new SKG_RoundButton(frameLetterButtons);
        rb_N->setObjectName(QString::fromUtf8("rb_N"));
        rb_N->setFont(font1);
        rb_N->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_N);

        rb_O = new SKG_RoundButton(frameLetterButtons);
        rb_O->setObjectName(QString::fromUtf8("rb_O"));
        rb_O->setFont(font1);
        rb_O->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_O);

        rb_P = new SKG_RoundButton(frameLetterButtons);
        rb_P->setObjectName(QString::fromUtf8("rb_P"));
        rb_P->setFont(font1);
        rb_P->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_P);

        rb_Q = new SKG_RoundButton(frameLetterButtons);
        rb_Q->setObjectName(QString::fromUtf8("rb_Q"));
        rb_Q->setFont(font1);
        rb_Q->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_Q);

        rb_R = new SKG_RoundButton(frameLetterButtons);
        rb_R->setObjectName(QString::fromUtf8("rb_R"));
        rb_R->setFont(font1);
        rb_R->setLineWidth(1);
        rb_R->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_R);

        rb_S = new SKG_RoundButton(frameLetterButtons);
        rb_S->setObjectName(QString::fromUtf8("rb_S"));
        rb_S->setFont(font1);
        rb_S->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_S);

        rb_T = new SKG_RoundButton(frameLetterButtons);
        rb_T->setObjectName(QString::fromUtf8("rb_T"));
        rb_T->setFont(font1);
        rb_T->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_T);

        rb_U = new SKG_RoundButton(frameLetterButtons);
        rb_U->setObjectName(QString::fromUtf8("rb_U"));
        rb_U->setFont(font1);
        rb_U->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_U);

        rb_V = new SKG_RoundButton(frameLetterButtons);
        rb_V->setObjectName(QString::fromUtf8("rb_V"));
        rb_V->setFont(font1);
        rb_V->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_V);

        rb_W = new SKG_RoundButton(frameLetterButtons);
        rb_W->setObjectName(QString::fromUtf8("rb_W"));
        rb_W->setFont(font1);
        rb_W->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_W);

        rb_X = new SKG_RoundButton(frameLetterButtons);
        rb_X->setObjectName(QString::fromUtf8("rb_X"));
        rb_X->setFont(font1);
        rb_X->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_X);

        rb_Y = new SKG_RoundButton(frameLetterButtons);
        rb_Y->setObjectName(QString::fromUtf8("rb_Y"));
        rb_Y->setFont(font1);
        rb_Y->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_Y);

        rb_Z = new SKG_RoundButton(frameLetterButtons);
        rb_Z->setObjectName(QString::fromUtf8("rb_Z"));
        rb_Z->setFont(font1);
        rb_Z->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(rb_Z);


        verticalLayout_3->addWidget(frameLetterButtons);

        currPanel = new SKG_AlbumPanel(Frame1);
        currPanel->setObjectName(QString::fromUtf8("currPanel"));
        currPanel->setAutoFillBackground(false);

        verticalLayout_3->addWidget(currPanel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        frameTrackList = new QFrame(Frame1);
        frameTrackList->setObjectName(QString::fromUtf8("frameTrackList"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        frameTrackList->setPalette(palette1);
        frameTrackList->setFrameShape(QFrame::Box);
        frameTrackList->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frameTrackList);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblTrackString = new QLabel(frameTrackList);
        lblTrackString->setObjectName(QString::fromUtf8("lblTrackString"));
        QPalette palette2;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        lblTrackString->setPalette(palette2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Digital-7"));
        font2.setPointSize(24);
        lblTrackString->setFont(font2);
        lblTrackString->setAutoFillBackground(true);
        lblTrackString->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTrackString);

        line = new QFrame(frameTrackList);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);

        lblTrackList = new QLabel(frameTrackList);
        lblTrackList->setObjectName(QString::fromUtf8("lblTrackList"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblTrackList->sizePolicy().hasHeightForWidth());
        lblTrackList->setSizePolicy(sizePolicy1);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        lblTrackList->setPalette(palette3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Digital-7"));
        font3.setPointSize(12);
        lblTrackList->setFont(font3);
        lblTrackList->setTextFormat(Qt::PlainText);
        lblTrackList->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblTrackList->setWordWrap(false);

        verticalLayout->addWidget(lblTrackList);

        verticalLayout->setStretch(0, 30);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 100);

        horizontalLayout_3->addWidget(frameTrackList);

        frameNowPlaying = new QFrame(Frame1);
        frameNowPlaying->setObjectName(QString::fromUtf8("frameNowPlaying"));
        sizePolicy.setHeightForWidth(frameNowPlaying->sizePolicy().hasHeightForWidth());
        frameNowPlaying->setSizePolicy(sizePolicy);
        frameNowPlaying->setFrameShape(QFrame::Box);
        frameNowPlaying->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameNowPlaying);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblCurrTrackArt = new QLabel(frameNowPlaying);
        lblCurrTrackArt->setObjectName(QString::fromUtf8("lblCurrTrackArt"));
        sizePolicy1.setHeightForWidth(lblCurrTrackArt->sizePolicy().hasHeightForWidth());
        lblCurrTrackArt->setSizePolicy(sizePolicy1);
        lblCurrTrackArt->setBaseSize(QSize(146, 169));
        lblCurrTrackArt->setFrameShape(QFrame::Box);
        lblCurrTrackArt->setScaledContents(true);
        lblCurrTrackArt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblCurrTrackArt);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_2->setContentsMargins(0, 5, 0, 5);
        label_2 = new QLabel(frameNowPlaying);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_2->setPalette(palette4);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        line_2 = new QFrame(frameNowPlaying);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy3);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        lblCurrArtist = new QLabel(frameNowPlaying);
        lblCurrArtist->setObjectName(QString::fromUtf8("lblCurrArtist"));
        sizePolicy2.setHeightForWidth(lblCurrArtist->sizePolicy().hasHeightForWidth());
        lblCurrArtist->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Bitstream Charter"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        lblCurrArtist->setFont(font4);
        lblCurrArtist->setAlignment(Qt::AlignCenter);
        lblCurrArtist->setWordWrap(true);

        verticalLayout_2->addWidget(lblCurrArtist);

        lblCurrTrackName = new QLabel(frameNowPlaying);
        lblCurrTrackName->setObjectName(QString::fromUtf8("lblCurrTrackName"));
        sizePolicy2.setHeightForWidth(lblCurrTrackName->sizePolicy().hasHeightForWidth());
        lblCurrTrackName->setSizePolicy(sizePolicy2);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Bitstream Charter"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        lblCurrTrackName->setFont(font5);
        lblCurrTrackName->setAlignment(Qt::AlignCenter);
        lblCurrTrackName->setWordWrap(true);

        verticalLayout_2->addWidget(lblCurrTrackName);

        lblCurrTrackData = new QLabel(frameNowPlaying);
        lblCurrTrackData->setObjectName(QString::fromUtf8("lblCurrTrackData"));
        sizePolicy2.setHeightForWidth(lblCurrTrackData->sizePolicy().hasHeightForWidth());
        lblCurrTrackData->setSizePolicy(sizePolicy2);
        lblCurrTrackData->setFont(font5);
        lblCurrTrackData->setAlignment(Qt::AlignCenter);
        lblCurrTrackData->setWordWrap(true);

        verticalLayout_2->addWidget(lblCurrTrackData);

        lblCurrTrackTime = new QLabel(frameNowPlaying);
        lblCurrTrackTime->setObjectName(QString::fromUtf8("lblCurrTrackTime"));
        sizePolicy2.setHeightForWidth(lblCurrTrackTime->sizePolicy().hasHeightForWidth());
        lblCurrTrackTime->setSizePolicy(sizePolicy2);
        lblCurrTrackTime->setFont(font5);
        lblCurrTrackTime->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblCurrTrackTime);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 7);
        horizontalLayout_2->setStretch(1, 13);

        horizontalLayout_3->addWidget(frameNowPlaying);

        frameButtons = new QFrame(Frame1);
        frameButtons->setObjectName(QString::fromUtf8("frameButtons"));
        sizePolicy.setHeightForWidth(frameButtons->sizePolicy().hasHeightForWidth());
        frameButtons->setSizePolicy(sizePolicy);
        frameButtons->setFrameShape(QFrame::Box);
        frameButtons->setFrameShadow(QFrame::Plain);
        gridLayout = new QGridLayout(frameButtons);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_1 = new SKG_Button(frameButtons);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font6.setPointSize(28);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        btn_1->setFont(font6);
        btn_1->setAutoFillBackground(true);

        gridLayout->addWidget(btn_1, 0, 0, 1, 1);

        btn_2 = new SKG_Button(frameButtons);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setFont(font6);
        btn_2->setAutoFillBackground(true);

        gridLayout->addWidget(btn_2, 0, 1, 1, 1);

        btn_3 = new SKG_Button(frameButtons);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setFont(font6);
        btn_3->setAutoFillBackground(true);

        gridLayout->addWidget(btn_3, 0, 2, 1, 1);

        btn_4 = new SKG_Button(frameButtons);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setFont(font6);
        btn_4->setAutoFillBackground(true);

        gridLayout->addWidget(btn_4, 0, 3, 1, 1);

        btn_5 = new SKG_Button(frameButtons);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setFont(font6);
        btn_5->setAutoFillBackground(true);

        gridLayout->addWidget(btn_5, 0, 4, 1, 1);

        btn_Next = new SKG_Button(frameButtons);
        btn_Next->setObjectName(QString::fromUtf8("btn_Next"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font7.setPointSize(36);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        btn_Next->setFont(font7);
        btn_Next->setAutoFillBackground(true);

        gridLayout->addWidget(btn_Next, 0, 5, 1, 1);

        btn_6 = new SKG_Button(frameButtons);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setFont(font6);
        btn_6->setAutoFillBackground(true);

        gridLayout->addWidget(btn_6, 1, 0, 1, 1);

        btn_7 = new SKG_Button(frameButtons);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setFont(font6);
        btn_7->setAutoFillBackground(true);

        gridLayout->addWidget(btn_7, 1, 1, 1, 1);

        btn_8 = new SKG_Button(frameButtons);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setFont(font6);
        btn_8->setAutoFillBackground(true);

        gridLayout->addWidget(btn_8, 1, 2, 1, 1);

        btn_9 = new SKG_Button(frameButtons);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setFont(font6);
        btn_9->setAutoFillBackground(true);

        gridLayout->addWidget(btn_9, 1, 3, 1, 1);

        btn_0 = new SKG_Button(frameButtons);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setFont(font6);
        btn_0->setAutoFillBackground(true);

        gridLayout->addWidget(btn_0, 1, 4, 1, 1);

        btn_Prev = new SKG_Button(frameButtons);
        btn_Prev->setObjectName(QString::fromUtf8("btn_Prev"));
        btn_Prev->setFont(font7);
        btn_Prev->setAutoFillBackground(true);

        gridLayout->addWidget(btn_Prev, 1, 5, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnStretch(3, 2);
        gridLayout->setColumnStretch(4, 2);
        gridLayout->setColumnStretch(5, 3);

        horizontalLayout_3->addWidget(frameButtons);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 8);
        horizontalLayout_3->setStretch(2, 8);

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 10);
        verticalLayout_3->setStretch(2, 4);
        MainNormal->setCentralWidget(centralwidget);

        retranslateUi(MainNormal);

        QMetaObject::connectSlotsByName(MainNormal);
    } // setupUi

    void retranslateUi(QMainWindow *MainNormal)
    {
        MainNormal->setWindowTitle(QApplication::translate("MainNormal", "MainWindow", 0, QApplication::UnicodeUTF8));
        btnAddTrack->setText(QApplication::translate("MainNormal", "Add Track", 0, QApplication::UnicodeUTF8));
        btnCancelTrack->setText(QApplication::translate("MainNormal", "Cancel", 0, QApplication::UnicodeUTF8));
        rb_0thru9->setText(QApplication::translate("MainNormal", "0..9", 0, QApplication::UnicodeUTF8));
        rb_A->setText(QApplication::translate("MainNormal", "A", 0, QApplication::UnicodeUTF8));
        rb_B->setText(QApplication::translate("MainNormal", "B", 0, QApplication::UnicodeUTF8));
        rb_C->setText(QApplication::translate("MainNormal", "C", 0, QApplication::UnicodeUTF8));
        rb_D->setText(QApplication::translate("MainNormal", "D", 0, QApplication::UnicodeUTF8));
        rb_E->setText(QApplication::translate("MainNormal", "E", 0, QApplication::UnicodeUTF8));
        rb_F->setText(QApplication::translate("MainNormal", "F", 0, QApplication::UnicodeUTF8));
        rb_G->setText(QApplication::translate("MainNormal", "G", 0, QApplication::UnicodeUTF8));
        rb_H->setText(QApplication::translate("MainNormal", "H", 0, QApplication::UnicodeUTF8));
        rb_I->setText(QApplication::translate("MainNormal", "I", 0, QApplication::UnicodeUTF8));
        rb_J->setText(QApplication::translate("MainNormal", "J", 0, QApplication::UnicodeUTF8));
        rb_K->setText(QApplication::translate("MainNormal", "K", 0, QApplication::UnicodeUTF8));
        rb_L->setText(QApplication::translate("MainNormal", "L", 0, QApplication::UnicodeUTF8));
        rb_M->setText(QApplication::translate("MainNormal", "M", 0, QApplication::UnicodeUTF8));
        rb_N->setText(QApplication::translate("MainNormal", "N", 0, QApplication::UnicodeUTF8));
        rb_O->setText(QApplication::translate("MainNormal", "O", 0, QApplication::UnicodeUTF8));
        rb_P->setText(QApplication::translate("MainNormal", "P", 0, QApplication::UnicodeUTF8));
        rb_Q->setText(QApplication::translate("MainNormal", "Q", 0, QApplication::UnicodeUTF8));
        rb_R->setText(QApplication::translate("MainNormal", "R", 0, QApplication::UnicodeUTF8));
        rb_S->setText(QApplication::translate("MainNormal", "S", 0, QApplication::UnicodeUTF8));
        rb_T->setText(QApplication::translate("MainNormal", "T", 0, QApplication::UnicodeUTF8));
        rb_U->setText(QApplication::translate("MainNormal", "U", 0, QApplication::UnicodeUTF8));
        rb_V->setText(QApplication::translate("MainNormal", "V", 0, QApplication::UnicodeUTF8));
        rb_W->setText(QApplication::translate("MainNormal", "W", 0, QApplication::UnicodeUTF8));
        rb_X->setText(QApplication::translate("MainNormal", "X", 0, QApplication::UnicodeUTF8));
        rb_Y->setText(QApplication::translate("MainNormal", "Y", 0, QApplication::UnicodeUTF8));
        rb_Z->setText(QApplication::translate("MainNormal", "Z", 0, QApplication::UnicodeUTF8));
        lblTrackString->setText(QApplication::translate("MainNormal", "Track List", 0, QApplication::UnicodeUTF8));
        lblTrackList->setText(QString());
        lblCurrTrackArt->setText(QString());
        label_2->setText(QApplication::translate("MainNormal", "Now Playing", 0, QApplication::UnicodeUTF8));
        lblCurrArtist->setText(QString());
        lblCurrTrackName->setText(QString());
        lblCurrTrackData->setText(QString());
        lblCurrTrackTime->setText(QString());
        btn_1->setText(QApplication::translate("MainNormal", "1", 0, QApplication::UnicodeUTF8));
        btn_2->setText(QApplication::translate("MainNormal", "2", 0, QApplication::UnicodeUTF8));
        btn_3->setText(QApplication::translate("MainNormal", "3", 0, QApplication::UnicodeUTF8));
        btn_4->setText(QApplication::translate("MainNormal", "4", 0, QApplication::UnicodeUTF8));
        btn_5->setText(QApplication::translate("MainNormal", "5", 0, QApplication::UnicodeUTF8));
        btn_Next->setText(QApplication::translate("MainNormal", ">", 0, QApplication::UnicodeUTF8));
        btn_6->setText(QApplication::translate("MainNormal", "6", 0, QApplication::UnicodeUTF8));
        btn_7->setText(QApplication::translate("MainNormal", "7", 0, QApplication::UnicodeUTF8));
        btn_8->setText(QApplication::translate("MainNormal", "8", 0, QApplication::UnicodeUTF8));
        btn_9->setText(QApplication::translate("MainNormal", "9", 0, QApplication::UnicodeUTF8));
        btn_0->setText(QApplication::translate("MainNormal", "0", 0, QApplication::UnicodeUTF8));
        btn_Prev->setText(QApplication::translate("MainNormal", "<", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainNormal: public Ui_MainNormal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINNORMAL_H
