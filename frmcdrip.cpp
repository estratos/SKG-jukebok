#include "frmcdrip.h"
#include "ui_frmcdrip.h"

frmCDRip::frmCDRip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmCDRip)
{
    ui->setupUi(this);
}

frmCDRip::~frmCDRip()
{
    delete ui;
}
