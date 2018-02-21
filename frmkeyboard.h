#ifndef FRMKEYBOARD_H
#define FRMKEYBOARD_H

#include <QDialog>

namespace Ui {
    class FrmKeyboard;
}

class FrmKeyboard : public QDialog {
    Q_OBJECT
public:
    FrmKeyboard(QWidget *parent = 0);
    ~FrmKeyboard();

    void Display();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::FrmKeyboard *ui;
    bool Shifted;

signals:
    void KeyPressed(int keycode, bool shift);

private slots:
    void Btn0_Clicked(){KeyPressed(Qt::Key_0,false);}
    void Btn1_Clicked(){KeyPressed(Qt::Key_1,false);}
    void Btn2_Clicked(){KeyPressed(Qt::Key_2,false);}
    void Btn3_Clicked(){KeyPressed(Qt::Key_3,false);}
    void Btn4_Clicked(){KeyPressed(Qt::Key_4,false);}
    void Btn5_Clicked(){KeyPressed(Qt::Key_5,false);}
    void Btn6_Clicked(){KeyPressed(Qt::Key_6,false);}
    void Btn7_Clicked(){KeyPressed(Qt::Key_7,false);}
    void Btn8_Clicked(){KeyPressed(Qt::Key_8,false);}
    void Btn9_Clicked(){KeyPressed(Qt::Key_9,false);}
    //
    void BtnA_Clicked(){KeyPressed(Qt::Key_A,false);}
    void BtnB_Clicked(){KeyPressed(Qt::Key_B,false);}
    void BtnC_Clicked(){KeyPressed(Qt::Key_C,false);}
    void BtnD_Clicked(){KeyPressed(Qt::Key_D,false);}
    void BtnE_Clicked(){KeyPressed(Qt::Key_E,false);}
    void BtnF_Clicked(){KeyPressed(Qt::Key_F,false);}
    void BtnG_Clicked(){KeyPressed(Qt::Key_G,false);}
    void BtnH_Clicked(){KeyPressed(Qt::Key_H,false);}
    void BtnI_Clicked(){KeyPressed(Qt::Key_I,false);}
    void BtnJ_Clicked(){KeyPressed(Qt::Key_J,false);}
    void BtnK_Clicked(){KeyPressed(Qt::Key_K,false);}
    void BtnL_Clicked(){KeyPressed(Qt::Key_L,false);}
    void BtnM_Clicked(){KeyPressed(Qt::Key_M,false);}
    void BtnN_Clicked(){KeyPressed(Qt::Key_N,false);}
    void BtnO_Clicked(){KeyPressed(Qt::Key_O,false);}
    void BtnP_Clicked(){KeyPressed(Qt::Key_P,false);}
    void BtnQ_Clicked(){KeyPressed(Qt::Key_Q,false);}
    void BtnR_Clicked(){KeyPressed(Qt::Key_R,false);}
    void BtnS_Clicked(){KeyPressed(Qt::Key_S,false);}
    void BtnT_Clicked(){KeyPressed(Qt::Key_T,false);}
    void BtnU_Clicked(){KeyPressed(Qt::Key_U,false);}
    void BtnV_Clicked(){KeyPressed(Qt::Key_V,false);}
    void BtnW_Clicked(){KeyPressed(Qt::Key_W,false);}
    void BtnX_Clicked(){KeyPressed(Qt::Key_X,false);}
    void BtnY_Clicked(){KeyPressed(Qt::Key_Y,false);}
    void BtnZ_Clicked(){KeyPressed(Qt::Key_Z,false);}
    //
    void BtnBackspace_Clicked(){KeyPressed(Qt::Key_Backspace,false);}
    void BtnApostrophe_Clicked(){KeyPressed(Qt::Key_Apostrophe,false);}
    void BtnComma_Clicked(){KeyPressed(Qt::Key_Comma,false);}
    void BtnQuestionMark_Clicked(){KeyPressed(Qt::Key_Question,false);}
    void BtnSpace_Clicked(){KeyPressed(Qt::Key_Space,false);}
    //
    void Shift();
};

#endif // FRMKEYBOARD_H
