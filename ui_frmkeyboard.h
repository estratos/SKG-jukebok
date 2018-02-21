/********************************************************************************
** Form generated from reading UI file 'frmkeyboard.ui'
**
** Created: Tue Jul 19 22:09:11 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMKEYBOARD_H
#define UI_FRMKEYBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include "SKG_Button/skg_button.h"

QT_BEGIN_NAMESPACE

class Ui_FrmKeyboard
{
public:
    QFrame *frame;
    SKG_Button *btn2;
    SKG_Button *btnZ;
    SKG_Button *btnF;
    SKG_Button *btnK;
    SKG_Button *btnY;
    SKG_Button *btnBackspace;
    SKG_Button *btnH;
    SKG_Button *btnV;
    SKG_Button *btnSpace;
    SKG_Button *btnComma;
    SKG_Button *btnW;
    SKG_Button *btnApostrophe;
    SKG_Button *btnS;
    SKG_Button *btnC;
    SKG_Button *btnE;
    SKG_Button *btn8;
    SKG_Button *btnL;
    SKG_Button *btnI;
    SKG_Button *btn1;
    SKG_Button *btnQ;
    SKG_Button *btnQuestionMark;
    SKG_Button *btnU;
    SKG_Button *btn6;
    SKG_Button *btnP;
    SKG_Button *btnT;
    SKG_Button *btn4;
    SKG_Button *btn7;
    SKG_Button *btnG;
    SKG_Button *btn3;
    SKG_Button *btnX;
    SKG_Button *btnD;
    SKG_Button *btn0;
    SKG_Button *btn9;
    SKG_Button *btnO;
    SKG_Button *btnA;
    SKG_Button *btn5;
    SKG_Button *btnM;
    SKG_Button *btnN;
    SKG_Button *btnJ;
    SKG_Button *btnR;
    SKG_Button *btnB;
    SKG_Button *btnShift;
    SKG_Button *btnClose;

    void setupUi(QDialog *FrmKeyboard)
    {
        if (FrmKeyboard->objectName().isEmpty())
            FrmKeyboard->setObjectName(QString::fromUtf8("FrmKeyboard"));
        FrmKeyboard->resize(800, 400);
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
        FrmKeyboard->setPalette(palette);
        frame = new QFrame(FrmKeyboard);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(2, 2, 796, 396));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        btn2 = new SKG_Button(frame);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(70, 5, 60, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Roman No9 L"));
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        btn2->setFont(font);
        btn2->setAutoFillBackground(true);
        btnZ = new SKG_Button(frame);
        btnZ->setObjectName(QString::fromUtf8("btnZ"));
        btnZ->setGeometry(QRect(65, 200, 60, 60));
        btnZ->setFont(font);
        btnZ->setAutoFillBackground(true);
        btnF = new SKG_Button(frame);
        btnF->setObjectName(QString::fromUtf8("btnF"));
        btnF->setGeometry(QRect(230, 135, 60, 60));
        btnF->setFont(font);
        btnF->setAutoFillBackground(true);
        btnK = new SKG_Button(frame);
        btnK->setObjectName(QString::fromUtf8("btnK"));
        btnK->setGeometry(QRect(490, 135, 60, 60));
        btnK->setFont(font);
        btnK->setAutoFillBackground(true);
        btnY = new SKG_Button(frame);
        btnY->setObjectName(QString::fromUtf8("btnY"));
        btnY->setGeometry(QRect(360, 70, 60, 60));
        btnY->setFont(font);
        btnY->setAutoFillBackground(true);
        btnBackspace = new SKG_Button(frame);
        btnBackspace->setObjectName(QString::fromUtf8("btnBackspace"));
        btnBackspace->setGeometry(QRect(655, 5, 131, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        btnBackspace->setFont(font1);
        btnBackspace->setAutoFillBackground(true);
        btnH = new SKG_Button(frame);
        btnH->setObjectName(QString::fromUtf8("btnH"));
        btnH->setGeometry(QRect(360, 135, 60, 60));
        btnH->setFont(font);
        btnH->setAutoFillBackground(true);
        btnV = new SKG_Button(frame);
        btnV->setObjectName(QString::fromUtf8("btnV"));
        btnV->setGeometry(QRect(260, 200, 60, 60));
        btnV->setFont(font);
        btnV->setAutoFillBackground(true);
        btnSpace = new SKG_Button(frame);
        btnSpace->setObjectName(QString::fromUtf8("btnSpace"));
        btnSpace->setGeometry(QRect(195, 270, 361, 60));
        btnSpace->setFont(font);
        btnSpace->setAutoFillBackground(true);
        btnComma = new SKG_Button(frame);
        btnComma->setObjectName(QString::fromUtf8("btnComma"));
        btnComma->setGeometry(QRect(520, 200, 60, 60));
        btnComma->setFont(font);
        btnComma->setAutoFillBackground(true);
        btnW = new SKG_Button(frame);
        btnW->setObjectName(QString::fromUtf8("btnW"));
        btnW->setGeometry(QRect(100, 70, 60, 60));
        btnW->setFont(font);
        btnW->setAutoFillBackground(true);
        btnApostrophe = new SKG_Button(frame);
        btnApostrophe->setObjectName(QString::fromUtf8("btnApostrophe"));
        btnApostrophe->setGeometry(QRect(620, 135, 60, 60));
        btnApostrophe->setFont(font);
        btnApostrophe->setAutoFillBackground(true);
        btnS = new SKG_Button(frame);
        btnS->setObjectName(QString::fromUtf8("btnS"));
        btnS->setGeometry(QRect(100, 135, 60, 60));
        btnS->setFont(font);
        btnS->setAutoFillBackground(true);
        btnC = new SKG_Button(frame);
        btnC->setObjectName(QString::fromUtf8("btnC"));
        btnC->setGeometry(QRect(195, 200, 60, 60));
        btnC->setFont(font);
        btnC->setAutoFillBackground(true);
        btnE = new SKG_Button(frame);
        btnE->setObjectName(QString::fromUtf8("btnE"));
        btnE->setGeometry(QRect(165, 70, 60, 60));
        btnE->setFont(font);
        btnE->setAutoFillBackground(true);
        btn8 = new SKG_Button(frame);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setGeometry(QRect(460, 5, 60, 60));
        btn8->setFont(font);
        btn8->setAutoFillBackground(true);
        btnL = new SKG_Button(frame);
        btnL->setObjectName(QString::fromUtf8("btnL"));
        btnL->setGeometry(QRect(555, 135, 60, 60));
        btnL->setFont(font);
        btnL->setAutoFillBackground(true);
        btnI = new SKG_Button(frame);
        btnI->setObjectName(QString::fromUtf8("btnI"));
        btnI->setGeometry(QRect(490, 70, 60, 60));
        btnI->setFont(font);
        btnI->setAutoFillBackground(true);
        btn1 = new SKG_Button(frame);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setGeometry(QRect(5, 5, 60, 60));
        btn1->setFont(font);
        btn1->setAutoFillBackground(true);
        btnQ = new SKG_Button(frame);
        btnQ->setObjectName(QString::fromUtf8("btnQ"));
        btnQ->setGeometry(QRect(35, 70, 60, 60));
        btnQ->setFont(font);
        btnQ->setAutoFillBackground(true);
        btnQuestionMark = new SKG_Button(frame);
        btnQuestionMark->setObjectName(QString::fromUtf8("btnQuestionMark"));
        btnQuestionMark->setGeometry(QRect(585, 200, 60, 60));
        btnQuestionMark->setFont(font);
        btnQuestionMark->setAutoFillBackground(true);
        btnU = new SKG_Button(frame);
        btnU->setObjectName(QString::fromUtf8("btnU"));
        btnU->setGeometry(QRect(425, 70, 60, 60));
        btnU->setFont(font);
        btnU->setAutoFillBackground(true);
        btn6 = new SKG_Button(frame);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setGeometry(QRect(330, 5, 60, 60));
        btn6->setFont(font);
        btn6->setAutoFillBackground(true);
        btnP = new SKG_Button(frame);
        btnP->setObjectName(QString::fromUtf8("btnP"));
        btnP->setGeometry(QRect(620, 70, 60, 60));
        btnP->setFont(font);
        btnP->setAutoFillBackground(true);
        btnT = new SKG_Button(frame);
        btnT->setObjectName(QString::fromUtf8("btnT"));
        btnT->setGeometry(QRect(295, 70, 60, 60));
        btnT->setFont(font);
        btnT->setAutoFillBackground(true);
        btn4 = new SKG_Button(frame);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setGeometry(QRect(200, 5, 60, 60));
        btn4->setFont(font);
        btn4->setAutoFillBackground(true);
        btn7 = new SKG_Button(frame);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setGeometry(QRect(395, 5, 60, 60));
        btn7->setFont(font);
        btn7->setAutoFillBackground(true);
        btnG = new SKG_Button(frame);
        btnG->setObjectName(QString::fromUtf8("btnG"));
        btnG->setGeometry(QRect(295, 135, 60, 60));
        btnG->setFont(font);
        btnG->setAutoFillBackground(true);
        btn3 = new SKG_Button(frame);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setGeometry(QRect(135, 5, 60, 60));
        btn3->setFont(font);
        btn3->setAutoFillBackground(true);
        btnX = new SKG_Button(frame);
        btnX->setObjectName(QString::fromUtf8("btnX"));
        btnX->setGeometry(QRect(130, 200, 60, 60));
        btnX->setFont(font);
        btnX->setAutoFillBackground(true);
        btnD = new SKG_Button(frame);
        btnD->setObjectName(QString::fromUtf8("btnD"));
        btnD->setGeometry(QRect(165, 135, 60, 60));
        btnD->setFont(font);
        btnD->setAutoFillBackground(true);
        btn0 = new SKG_Button(frame);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        btn0->setGeometry(QRect(590, 5, 60, 60));
        btn0->setFont(font);
        btn0->setAutoFillBackground(true);
        btn9 = new SKG_Button(frame);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setGeometry(QRect(525, 5, 60, 60));
        btn9->setFont(font);
        btn9->setAutoFillBackground(true);
        btnO = new SKG_Button(frame);
        btnO->setObjectName(QString::fromUtf8("btnO"));
        btnO->setGeometry(QRect(555, 70, 60, 60));
        btnO->setFont(font);
        btnO->setAutoFillBackground(true);
        btnA = new SKG_Button(frame);
        btnA->setObjectName(QString::fromUtf8("btnA"));
        btnA->setGeometry(QRect(35, 135, 60, 60));
        btnA->setFont(font);
        btnA->setAutoFillBackground(true);
        btn5 = new SKG_Button(frame);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setGeometry(QRect(265, 5, 60, 60));
        btn5->setFont(font);
        btn5->setAutoFillBackground(true);
        btnM = new SKG_Button(frame);
        btnM->setObjectName(QString::fromUtf8("btnM"));
        btnM->setGeometry(QRect(455, 200, 60, 60));
        btnM->setFont(font);
        btnM->setAutoFillBackground(true);
        btnN = new SKG_Button(frame);
        btnN->setObjectName(QString::fromUtf8("btnN"));
        btnN->setGeometry(QRect(390, 200, 60, 60));
        btnN->setFont(font);
        btnN->setAutoFillBackground(true);
        btnJ = new SKG_Button(frame);
        btnJ->setObjectName(QString::fromUtf8("btnJ"));
        btnJ->setGeometry(QRect(425, 135, 60, 60));
        btnJ->setFont(font);
        btnJ->setAutoFillBackground(true);
        btnR = new SKG_Button(frame);
        btnR->setObjectName(QString::fromUtf8("btnR"));
        btnR->setGeometry(QRect(230, 70, 60, 60));
        btnR->setFont(font);
        btnR->setAutoFillBackground(true);
        btnB = new SKG_Button(frame);
        btnB->setObjectName(QString::fromUtf8("btnB"));
        btnB->setGeometry(QRect(325, 200, 60, 60));
        btnB->setFont(font);
        btnB->setAutoFillBackground(true);
        btnShift = new SKG_Button(frame);
        btnShift->setObjectName(QString::fromUtf8("btnShift"));
        btnShift->setGeometry(QRect(10, 270, 111, 60));
        btnShift->setAutoFillBackground(true);
        btnClose = new SKG_Button(frame);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(670, 250, 121, 81));
        btnClose->setFont(font1);
        btnClose->setAutoFillBackground(true);
        btnClose->setWordWrap(true);

        retranslateUi(FrmKeyboard);

        QMetaObject::connectSlotsByName(FrmKeyboard);
    } // setupUi

    void retranslateUi(QDialog *FrmKeyboard)
    {
        FrmKeyboard->setWindowTitle(QApplication::translate("FrmKeyboard", "Dialog", 0, QApplication::UnicodeUTF8));
        btn2->setText(QApplication::translate("FrmKeyboard", "2", 0, QApplication::UnicodeUTF8));
        btnZ->setText(QApplication::translate("FrmKeyboard", "Z", 0, QApplication::UnicodeUTF8));
        btnF->setText(QApplication::translate("FrmKeyboard", "F", 0, QApplication::UnicodeUTF8));
        btnK->setText(QApplication::translate("FrmKeyboard", "K", 0, QApplication::UnicodeUTF8));
        btnY->setText(QApplication::translate("FrmKeyboard", "Y", 0, QApplication::UnicodeUTF8));
        btnBackspace->setText(QApplication::translate("FrmKeyboard", "Backspace", 0, QApplication::UnicodeUTF8));
        btnH->setText(QApplication::translate("FrmKeyboard", "H", 0, QApplication::UnicodeUTF8));
        btnV->setText(QApplication::translate("FrmKeyboard", "V", 0, QApplication::UnicodeUTF8));
        btnSpace->setText(QApplication::translate("FrmKeyboard", "Space", 0, QApplication::UnicodeUTF8));
        btnComma->setText(QApplication::translate("FrmKeyboard", ",", 0, QApplication::UnicodeUTF8));
        btnW->setText(QApplication::translate("FrmKeyboard", "W", 0, QApplication::UnicodeUTF8));
        btnApostrophe->setText(QApplication::translate("FrmKeyboard", "'", 0, QApplication::UnicodeUTF8));
        btnS->setText(QApplication::translate("FrmKeyboard", "S", 0, QApplication::UnicodeUTF8));
        btnC->setText(QApplication::translate("FrmKeyboard", "C", 0, QApplication::UnicodeUTF8));
        btnE->setText(QApplication::translate("FrmKeyboard", "E", 0, QApplication::UnicodeUTF8));
        btn8->setText(QApplication::translate("FrmKeyboard", "8", 0, QApplication::UnicodeUTF8));
        btnL->setText(QApplication::translate("FrmKeyboard", "L", 0, QApplication::UnicodeUTF8));
        btnI->setText(QApplication::translate("FrmKeyboard", "I", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("FrmKeyboard", "1", 0, QApplication::UnicodeUTF8));
        btnQ->setText(QApplication::translate("FrmKeyboard", "Q", 0, QApplication::UnicodeUTF8));
        btnQuestionMark->setText(QApplication::translate("FrmKeyboard", "?", 0, QApplication::UnicodeUTF8));
        btnU->setText(QApplication::translate("FrmKeyboard", "U", 0, QApplication::UnicodeUTF8));
        btn6->setText(QApplication::translate("FrmKeyboard", "6", 0, QApplication::UnicodeUTF8));
        btnP->setText(QApplication::translate("FrmKeyboard", "P", 0, QApplication::UnicodeUTF8));
        btnT->setText(QApplication::translate("FrmKeyboard", "T", 0, QApplication::UnicodeUTF8));
        btn4->setText(QApplication::translate("FrmKeyboard", "4", 0, QApplication::UnicodeUTF8));
        btn7->setText(QApplication::translate("FrmKeyboard", "7", 0, QApplication::UnicodeUTF8));
        btnG->setText(QApplication::translate("FrmKeyboard", "G", 0, QApplication::UnicodeUTF8));
        btn3->setText(QApplication::translate("FrmKeyboard", "3", 0, QApplication::UnicodeUTF8));
        btnX->setText(QApplication::translate("FrmKeyboard", "X", 0, QApplication::UnicodeUTF8));
        btnD->setText(QApplication::translate("FrmKeyboard", "D", 0, QApplication::UnicodeUTF8));
        btn0->setText(QApplication::translate("FrmKeyboard", "0", 0, QApplication::UnicodeUTF8));
        btn9->setText(QApplication::translate("FrmKeyboard", "9", 0, QApplication::UnicodeUTF8));
        btnO->setText(QApplication::translate("FrmKeyboard", "O", 0, QApplication::UnicodeUTF8));
        btnA->setText(QApplication::translate("FrmKeyboard", "A", 0, QApplication::UnicodeUTF8));
        btn5->setText(QApplication::translate("FrmKeyboard", "5", 0, QApplication::UnicodeUTF8));
        btnM->setText(QApplication::translate("FrmKeyboard", "M", 0, QApplication::UnicodeUTF8));
        btnN->setText(QApplication::translate("FrmKeyboard", "N", 0, QApplication::UnicodeUTF8));
        btnJ->setText(QApplication::translate("FrmKeyboard", "J", 0, QApplication::UnicodeUTF8));
        btnR->setText(QApplication::translate("FrmKeyboard", "R", 0, QApplication::UnicodeUTF8));
        btnB->setText(QApplication::translate("FrmKeyboard", "B", 0, QApplication::UnicodeUTF8));
        btnShift->setText(QString());
        btnClose->setText(QApplication::translate("FrmKeyboard", "Close Keyboard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrmKeyboard: public Ui_FrmKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMKEYBOARD_H
