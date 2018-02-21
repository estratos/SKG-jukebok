/********************************************************************************
** Form generated from reading UI file 'framekbd.ui'
**
** Created: Thu Nov 18 23:57:52 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEKBD_H
#define UI_FRAMEKBD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include "skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_framekbd
{
public:
    SKG_Button *btn1;
    SKG_Button *btn2;
    SKG_Button *btn3;
    SKG_Button *btn4;
    SKG_Button *btn5;
    SKG_Button *btn6;
    SKG_Button *btn7;
    SKG_Button *btn8;
    SKG_Button *btn9;
    SKG_Button *btn0;
    SKG_Button *btnBackspace;
    SKG_Button *btnQ;
    SKG_Button *btnW;
    SKG_Button *btnE;
    SKG_Button *btnR;
    SKG_Button *btnT;
    SKG_Button *btnY;
    SKG_Button *btnU;
    SKG_Button *btnI;
    SKG_Button *btnO;
    SKG_Button *btnP;
    SKG_Button *btnA;
    SKG_Button *btnS;
    SKG_Button *btnD;
    SKG_Button *btnF;
    SKG_Button *btnG;
    SKG_Button *btnH;
    SKG_Button *btnJ;
    SKG_Button *btnK;
    SKG_Button *btnL;
    SKG_Button *btnApostrophe;
    SKG_Button *btnZ;
    SKG_Button *btnX;
    SKG_Button *btnC;
    SKG_Button *btnV;
    SKG_Button *btnB;
    SKG_Button *btnN;
    SKG_Button *btnM;
    SKG_Button *btnComma;
    SKG_Button *btnQuestionMark;
    SKG_Button *btnSpace;

    void setupUi(QFrame *framekbd)
    {
        if (framekbd->objectName().isEmpty())
            framekbd->setObjectName(QString::fromUtf8("framekbd"));
        framekbd->resize(560, 230);
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
        QBrush brush2(QColor(122, 122, 122, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        framekbd->setPalette(palette);
        framekbd->setAutoFillBackground(true);
        framekbd->setFrameShape(QFrame::StyledPanel);
        framekbd->setFrameShadow(QFrame::Raised);
        btn1 = new SKG_Button(framekbd);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setGeometry(QRect(5, 5, 40, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        btn1->setFont(font);
        btn1->setAutoFillBackground(true);
        btn2 = new SKG_Button(framekbd);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(50, 5, 40, 40));
        btn2->setFont(font);
        btn2->setAutoFillBackground(true);
        btn3 = new SKG_Button(framekbd);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setGeometry(QRect(95, 5, 40, 40));
        btn3->setFont(font);
        btn3->setAutoFillBackground(true);
        btn4 = new SKG_Button(framekbd);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setGeometry(QRect(140, 5, 40, 40));
        btn4->setFont(font);
        btn4->setAutoFillBackground(true);
        btn5 = new SKG_Button(framekbd);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setGeometry(QRect(185, 5, 40, 40));
        btn5->setFont(font);
        btn5->setAutoFillBackground(true);
        btn6 = new SKG_Button(framekbd);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setGeometry(QRect(230, 5, 40, 40));
        btn6->setFont(font);
        btn6->setAutoFillBackground(true);
        btn7 = new SKG_Button(framekbd);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setGeometry(QRect(275, 5, 40, 40));
        btn7->setFont(font);
        btn7->setAutoFillBackground(true);
        btn8 = new SKG_Button(framekbd);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setGeometry(QRect(320, 5, 40, 40));
        btn8->setFont(font);
        btn8->setAutoFillBackground(true);
        btn9 = new SKG_Button(framekbd);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setGeometry(QRect(365, 5, 40, 40));
        btn9->setFont(font);
        btn9->setAutoFillBackground(true);
        btn0 = new SKG_Button(framekbd);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        btn0->setGeometry(QRect(410, 5, 40, 40));
        btn0->setFont(font);
        btn0->setAutoFillBackground(true);
        btnBackspace = new SKG_Button(framekbd);
        btnBackspace->setObjectName(QString::fromUtf8("btnBackspace"));
        btnBackspace->setGeometry(QRect(455, 5, 101, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        btnBackspace->setFont(font1);
        btnBackspace->setAutoFillBackground(true);
        btnQ = new SKG_Button(framekbd);
        btnQ->setObjectName(QString::fromUtf8("btnQ"));
        btnQ->setGeometry(QRect(25, 50, 40, 40));
        btnQ->setFont(font);
        btnQ->setAutoFillBackground(true);
        btnW = new SKG_Button(framekbd);
        btnW->setObjectName(QString::fromUtf8("btnW"));
        btnW->setGeometry(QRect(70, 50, 40, 40));
        btnW->setFont(font);
        btnW->setAutoFillBackground(true);
        btnE = new SKG_Button(framekbd);
        btnE->setObjectName(QString::fromUtf8("btnE"));
        btnE->setGeometry(QRect(115, 50, 40, 40));
        btnE->setFont(font);
        btnE->setAutoFillBackground(true);
        btnR = new SKG_Button(framekbd);
        btnR->setObjectName(QString::fromUtf8("btnR"));
        btnR->setGeometry(QRect(160, 50, 40, 40));
        btnR->setFont(font);
        btnR->setAutoFillBackground(true);
        btnT = new SKG_Button(framekbd);
        btnT->setObjectName(QString::fromUtf8("btnT"));
        btnT->setGeometry(QRect(205, 50, 40, 40));
        btnT->setFont(font);
        btnT->setAutoFillBackground(true);
        btnY = new SKG_Button(framekbd);
        btnY->setObjectName(QString::fromUtf8("btnY"));
        btnY->setGeometry(QRect(250, 50, 40, 40));
        btnY->setFont(font);
        btnY->setAutoFillBackground(true);
        btnU = new SKG_Button(framekbd);
        btnU->setObjectName(QString::fromUtf8("btnU"));
        btnU->setGeometry(QRect(295, 50, 40, 40));
        btnU->setFont(font);
        btnU->setAutoFillBackground(true);
        btnI = new SKG_Button(framekbd);
        btnI->setObjectName(QString::fromUtf8("btnI"));
        btnI->setGeometry(QRect(340, 50, 40, 40));
        btnI->setFont(font);
        btnI->setAutoFillBackground(true);
        btnO = new SKG_Button(framekbd);
        btnO->setObjectName(QString::fromUtf8("btnO"));
        btnO->setGeometry(QRect(385, 50, 40, 40));
        btnO->setFont(font);
        btnO->setAutoFillBackground(true);
        btnP = new SKG_Button(framekbd);
        btnP->setObjectName(QString::fromUtf8("btnP"));
        btnP->setGeometry(QRect(430, 50, 40, 40));
        btnP->setFont(font);
        btnP->setAutoFillBackground(true);
        btnA = new SKG_Button(framekbd);
        btnA->setObjectName(QString::fromUtf8("btnA"));
        btnA->setGeometry(QRect(25, 95, 40, 40));
        btnA->setFont(font);
        btnA->setAutoFillBackground(true);
        btnS = new SKG_Button(framekbd);
        btnS->setObjectName(QString::fromUtf8("btnS"));
        btnS->setGeometry(QRect(70, 95, 40, 40));
        btnS->setFont(font);
        btnS->setAutoFillBackground(true);
        btnD = new SKG_Button(framekbd);
        btnD->setObjectName(QString::fromUtf8("btnD"));
        btnD->setGeometry(QRect(115, 95, 40, 40));
        btnD->setFont(font);
        btnD->setAutoFillBackground(true);
        btnF = new SKG_Button(framekbd);
        btnF->setObjectName(QString::fromUtf8("btnF"));
        btnF->setGeometry(QRect(160, 95, 40, 40));
        btnF->setFont(font);
        btnF->setAutoFillBackground(true);
        btnG = new SKG_Button(framekbd);
        btnG->setObjectName(QString::fromUtf8("btnG"));
        btnG->setGeometry(QRect(205, 95, 40, 40));
        btnG->setFont(font);
        btnG->setAutoFillBackground(true);
        btnH = new SKG_Button(framekbd);
        btnH->setObjectName(QString::fromUtf8("btnH"));
        btnH->setGeometry(QRect(250, 95, 40, 40));
        btnH->setFont(font);
        btnH->setAutoFillBackground(true);
        btnJ = new SKG_Button(framekbd);
        btnJ->setObjectName(QString::fromUtf8("btnJ"));
        btnJ->setGeometry(QRect(295, 95, 40, 40));
        btnJ->setFont(font);
        btnJ->setAutoFillBackground(true);
        btnK = new SKG_Button(framekbd);
        btnK->setObjectName(QString::fromUtf8("btnK"));
        btnK->setGeometry(QRect(340, 95, 40, 40));
        btnK->setFont(font);
        btnK->setAutoFillBackground(true);
        btnL = new SKG_Button(framekbd);
        btnL->setObjectName(QString::fromUtf8("btnL"));
        btnL->setGeometry(QRect(385, 95, 40, 40));
        btnL->setFont(font);
        btnL->setAutoFillBackground(true);
        btnApostrophe = new SKG_Button(framekbd);
        btnApostrophe->setObjectName(QString::fromUtf8("btnApostrophe"));
        btnApostrophe->setGeometry(QRect(430, 95, 40, 40));
        btnApostrophe->setFont(font);
        btnApostrophe->setAutoFillBackground(true);
        btnZ = new SKG_Button(framekbd);
        btnZ->setObjectName(QString::fromUtf8("btnZ"));
        btnZ->setGeometry(QRect(45, 140, 40, 40));
        btnZ->setFont(font);
        btnZ->setAutoFillBackground(true);
        btnX = new SKG_Button(framekbd);
        btnX->setObjectName(QString::fromUtf8("btnX"));
        btnX->setGeometry(QRect(90, 140, 40, 40));
        btnX->setFont(font);
        btnX->setAutoFillBackground(true);
        btnC = new SKG_Button(framekbd);
        btnC->setObjectName(QString::fromUtf8("btnC"));
        btnC->setGeometry(QRect(135, 140, 40, 40));
        btnC->setFont(font);
        btnC->setAutoFillBackground(true);
        btnV = new SKG_Button(framekbd);
        btnV->setObjectName(QString::fromUtf8("btnV"));
        btnV->setGeometry(QRect(180, 140, 40, 40));
        btnV->setFont(font);
        btnV->setAutoFillBackground(true);
        btnB = new SKG_Button(framekbd);
        btnB->setObjectName(QString::fromUtf8("btnB"));
        btnB->setGeometry(QRect(225, 140, 40, 40));
        btnB->setFont(font);
        btnB->setAutoFillBackground(true);
        btnN = new SKG_Button(framekbd);
        btnN->setObjectName(QString::fromUtf8("btnN"));
        btnN->setGeometry(QRect(270, 140, 40, 40));
        btnN->setFont(font);
        btnN->setAutoFillBackground(true);
        btnM = new SKG_Button(framekbd);
        btnM->setObjectName(QString::fromUtf8("btnM"));
        btnM->setGeometry(QRect(315, 140, 40, 40));
        btnM->setFont(font);
        btnM->setAutoFillBackground(true);
        btnComma = new SKG_Button(framekbd);
        btnComma->setObjectName(QString::fromUtf8("btnComma"));
        btnComma->setGeometry(QRect(360, 140, 40, 40));
        btnComma->setFont(font);
        btnComma->setAutoFillBackground(true);
        btnQuestionMark = new SKG_Button(framekbd);
        btnQuestionMark->setObjectName(QString::fromUtf8("btnQuestionMark"));
        btnQuestionMark->setGeometry(QRect(405, 140, 40, 40));
        btnQuestionMark->setFont(font);
        btnQuestionMark->setAutoFillBackground(true);
        btnSpace = new SKG_Button(framekbd);
        btnSpace->setObjectName(QString::fromUtf8("btnSpace"));
        btnSpace->setGeometry(QRect(65, 185, 361, 40));
        btnSpace->setFont(font);
        btnSpace->setAutoFillBackground(true);

        retranslateUi(framekbd);

        QMetaObject::connectSlotsByName(framekbd);
    } // setupUi

    void retranslateUi(QFrame *framekbd)
    {
        framekbd->setWindowTitle(QApplication::translate("framekbd", "Frame", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("framekbd", "1", 0, QApplication::UnicodeUTF8));
        btn2->setText(QApplication::translate("framekbd", "2", 0, QApplication::UnicodeUTF8));
        btn3->setText(QApplication::translate("framekbd", "3", 0, QApplication::UnicodeUTF8));
        btn4->setText(QApplication::translate("framekbd", "4", 0, QApplication::UnicodeUTF8));
        btn5->setText(QApplication::translate("framekbd", "5", 0, QApplication::UnicodeUTF8));
        btn6->setText(QApplication::translate("framekbd", "6", 0, QApplication::UnicodeUTF8));
        btn7->setText(QApplication::translate("framekbd", "7", 0, QApplication::UnicodeUTF8));
        btn8->setText(QApplication::translate("framekbd", "8", 0, QApplication::UnicodeUTF8));
        btn9->setText(QApplication::translate("framekbd", "9", 0, QApplication::UnicodeUTF8));
        btn0->setText(QApplication::translate("framekbd", "0", 0, QApplication::UnicodeUTF8));
        btnBackspace->setText(QApplication::translate("framekbd", "Backspace", 0, QApplication::UnicodeUTF8));
        btnQ->setText(QApplication::translate("framekbd", "Q", 0, QApplication::UnicodeUTF8));
        btnW->setText(QApplication::translate("framekbd", "W", 0, QApplication::UnicodeUTF8));
        btnE->setText(QApplication::translate("framekbd", "E", 0, QApplication::UnicodeUTF8));
        btnR->setText(QApplication::translate("framekbd", "R", 0, QApplication::UnicodeUTF8));
        btnT->setText(QApplication::translate("framekbd", "T", 0, QApplication::UnicodeUTF8));
        btnY->setText(QApplication::translate("framekbd", "Y", 0, QApplication::UnicodeUTF8));
        btnU->setText(QApplication::translate("framekbd", "U", 0, QApplication::UnicodeUTF8));
        btnI->setText(QApplication::translate("framekbd", "I", 0, QApplication::UnicodeUTF8));
        btnO->setText(QApplication::translate("framekbd", "O", 0, QApplication::UnicodeUTF8));
        btnP->setText(QApplication::translate("framekbd", "P", 0, QApplication::UnicodeUTF8));
        btnA->setText(QApplication::translate("framekbd", "A", 0, QApplication::UnicodeUTF8));
        btnS->setText(QApplication::translate("framekbd", "S", 0, QApplication::UnicodeUTF8));
        btnD->setText(QApplication::translate("framekbd", "D", 0, QApplication::UnicodeUTF8));
        btnF->setText(QApplication::translate("framekbd", "F", 0, QApplication::UnicodeUTF8));
        btnG->setText(QApplication::translate("framekbd", "G", 0, QApplication::UnicodeUTF8));
        btnH->setText(QApplication::translate("framekbd", "H", 0, QApplication::UnicodeUTF8));
        btnJ->setText(QApplication::translate("framekbd", "J", 0, QApplication::UnicodeUTF8));
        btnK->setText(QApplication::translate("framekbd", "K", 0, QApplication::UnicodeUTF8));
        btnL->setText(QApplication::translate("framekbd", "L", 0, QApplication::UnicodeUTF8));
        btnApostrophe->setText(QApplication::translate("framekbd", "'", 0, QApplication::UnicodeUTF8));
        btnZ->setText(QApplication::translate("framekbd", "Z", 0, QApplication::UnicodeUTF8));
        btnX->setText(QApplication::translate("framekbd", "X", 0, QApplication::UnicodeUTF8));
        btnC->setText(QApplication::translate("framekbd", "C", 0, QApplication::UnicodeUTF8));
        btnV->setText(QApplication::translate("framekbd", "V", 0, QApplication::UnicodeUTF8));
        btnB->setText(QApplication::translate("framekbd", "B", 0, QApplication::UnicodeUTF8));
        btnN->setText(QApplication::translate("framekbd", "N", 0, QApplication::UnicodeUTF8));
        btnM->setText(QApplication::translate("framekbd", "M", 0, QApplication::UnicodeUTF8));
        btnComma->setText(QApplication::translate("framekbd", ",", 0, QApplication::UnicodeUTF8));
        btnQuestionMark->setText(QApplication::translate("framekbd", "?", 0, QApplication::UnicodeUTF8));
        btnSpace->setText(QApplication::translate("framekbd", "Space", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class framekbd: public Ui_framekbd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEKBD_H
