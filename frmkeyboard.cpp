#include "frmkeyboard.h"
#include "ui_frmkeyboard.h"
#include "jukeboxconfig.h"

FrmKeyboard::FrmKeyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmKeyboard)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    QObject::connect(ui->btn0,SIGNAL(clicked()),this,SLOT(Btn0_Clicked()));
    QObject::connect(ui->btn1,SIGNAL(clicked()),this,SLOT(Btn1_Clicked()));
    QObject::connect(ui->btn2,SIGNAL(clicked()),this,SLOT(Btn2_Clicked()));
    QObject::connect(ui->btn3,SIGNAL(clicked()),this,SLOT(Btn3_Clicked()));
    QObject::connect(ui->btn4,SIGNAL(clicked()),this,SLOT(Btn4_Clicked()));
    QObject::connect(ui->btn5,SIGNAL(clicked()),this,SLOT(Btn5_Clicked()));
    QObject::connect(ui->btn6,SIGNAL(clicked()),this,SLOT(Btn6_Clicked()));
    QObject::connect(ui->btn7,SIGNAL(clicked()),this,SLOT(Btn7_Clicked()));
    QObject::connect(ui->btn8,SIGNAL(clicked()),this,SLOT(Btn8_Clicked()));
    QObject::connect(ui->btn9,SIGNAL(clicked()),this,SLOT(Btn9_Clicked()));
    //
    QObject::connect(ui->btnA,SIGNAL(clicked()),this,SLOT(BtnA_Clicked()));
    QObject::connect(ui->btnB,SIGNAL(clicked()),this,SLOT(BtnB_Clicked()));
    QObject::connect(ui->btnC,SIGNAL(clicked()),this,SLOT(BtnC_Clicked()));
    QObject::connect(ui->btnD,SIGNAL(clicked()),this,SLOT(BtnD_Clicked()));
    QObject::connect(ui->btnE,SIGNAL(clicked()),this,SLOT(BtnE_Clicked()));
    QObject::connect(ui->btnF,SIGNAL(clicked()),this,SLOT(BtnF_Clicked()));
    QObject::connect(ui->btnG,SIGNAL(clicked()),this,SLOT(BtnG_Clicked()));
    QObject::connect(ui->btnH,SIGNAL(clicked()),this,SLOT(BtnH_Clicked()));
    QObject::connect(ui->btnI,SIGNAL(clicked()),this,SLOT(BtnI_Clicked()));
    QObject::connect(ui->btnJ,SIGNAL(clicked()),this,SLOT(BtnJ_Clicked()));
    QObject::connect(ui->btnK,SIGNAL(clicked()),this,SLOT(BtnK_Clicked()));
    QObject::connect(ui->btnL,SIGNAL(clicked()),this,SLOT(BtnL_Clicked()));
    QObject::connect(ui->btnM,SIGNAL(clicked()),this,SLOT(BtnM_Clicked()));
    QObject::connect(ui->btnN,SIGNAL(clicked()),this,SLOT(BtnN_Clicked()));
    QObject::connect(ui->btnO,SIGNAL(clicked()),this,SLOT(BtnO_Clicked()));
    QObject::connect(ui->btnP,SIGNAL(clicked()),this,SLOT(BtnP_Clicked()));
    QObject::connect(ui->btnQ,SIGNAL(clicked()),this,SLOT(BtnQ_Clicked()));
    QObject::connect(ui->btnR,SIGNAL(clicked()),this,SLOT(BtnR_Clicked()));
    QObject::connect(ui->btnS,SIGNAL(clicked()),this,SLOT(BtnS_Clicked()));
    QObject::connect(ui->btnT,SIGNAL(clicked()),this,SLOT(BtnT_Clicked()));
    QObject::connect(ui->btnU,SIGNAL(clicked()),this,SLOT(BtnU_Clicked()));
    QObject::connect(ui->btnV,SIGNAL(clicked()),this,SLOT(BtnV_Clicked()));
    QObject::connect(ui->btnW,SIGNAL(clicked()),this,SLOT(BtnW_Clicked()));
    QObject::connect(ui->btnX,SIGNAL(clicked()),this,SLOT(BtnX_Clicked()));
    QObject::connect(ui->btnY,SIGNAL(clicked()),this,SLOT(BtnY_Clicked()));
    QObject::connect(ui->btnZ,SIGNAL(clicked()),this,SLOT(BtnZ_Clicked()));
    //
    QObject::connect(ui->btnBackspace,SIGNAL(clicked()),this,SLOT(BtnBackspace_Clicked()));
    QObject::connect(ui->btnApostrophe,SIGNAL(clicked()),this,SLOT(BtnApostrophe_Clicked()));
    QObject::connect(ui->btnComma,SIGNAL(clicked()),this,SLOT(BtnComma_Clicked()));
    QObject::connect(ui->btnQuestionMark,SIGNAL(clicked()),this,SLOT(BtnQuestionMark_Clicked()));
    QObject::connect(ui->btnSpace,SIGNAL(clicked()),this,SLOT(BtnSpace_Clicked()));
    QObject::connect(ui->btnShift,SIGNAL(clicked()),this,SLOT(Shift()));
    QObject::connect(ui->btnClose,SIGNAL(clicked()),this,SLOT(accept()));
}

FrmKeyboard::~FrmKeyboard()
{
    delete ui;
}

void FrmKeyboard::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void FrmKeyboard::Shift()
{
    Shifted = !(Shifted);

    if (Shifted)
    {
        ui->btnA->setText("A");
        ui->btnB->setText("B");
        ui->btnC->setText("C");
        ui->btnD->setText("D");
        ui->btnE->setText("E");
        ui->btnF->setText("F");
        ui->btnG->setText("G");
        ui->btnH->setText("H");
        ui->btnI->setText("I");
        ui->btnJ->setText("J");
        ui->btnK->setText("K");
        ui->btnL->setText("L");
        ui->btnM->setText("M");
        ui->btnN->setText("N");
        ui->btnO->setText("O");
        ui->btnP->setText("P");
        ui->btnQ->setText("Q");
        ui->btnR->setText("R");
        ui->btnS->setText("S");
        ui->btnT->setText("T");
        ui->btnU->setText("U");
        ui->btnV->setText("V");
        ui->btnW->setText("W");
        ui->btnX->setText("X");
        ui->btnY->setText("Y");
        ui->btnZ->setText("Z");

        ui->btnShift->setPixmap(DownArrow());
    }
    else
    {
        ui->btnA->setText("a");
        ui->btnB->setText("b");
        ui->btnC->setText("c");
        ui->btnD->setText("d");
        ui->btnE->setText("e");
        ui->btnF->setText("f");
        ui->btnG->setText("g");
        ui->btnH->setText("h");
        ui->btnI->setText("i");
        ui->btnJ->setText("j");
        ui->btnK->setText("k");
        ui->btnL->setText("l");
        ui->btnM->setText("m");
        ui->btnN->setText("n");
        ui->btnO->setText("o");
        ui->btnP->setText("p");
        ui->btnQ->setText("q");
        ui->btnR->setText("r");
        ui->btnS->setText("s");
        ui->btnT->setText("t");
        ui->btnU->setText("u");
        ui->btnV->setText("v");
        ui->btnW->setText("w");
        ui->btnX->setText("x");
        ui->btnY->setText("y");
        ui->btnZ->setText("z");

        ui->btnShift->setPixmap(UpArrow());
    }
}

void FrmKeyboard::Display()
{
    Shifted = false;
    Shift();
    exec();
}
