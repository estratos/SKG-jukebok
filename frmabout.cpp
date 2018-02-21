#include "frmabout.h"
#include "ui_frmabout.h"
#include "version.h"

frmAbout::frmAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmAbout)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    ui->lblVersion->setText("SKG Jukebox version " + cVERSION_STR);
    ui->lblCopyright->setText("Copyright 2010-11 by The Skeptical Geek.\n Distributed under the terms of the General Public License.");
    QObject::connect(ui->btnOK,SIGNAL(clicked()),this,SLOT(accept()));
}

frmAbout::~frmAbout()
{
    delete ui;
}

void frmAbout::changeEvent(QEvent *e)
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
