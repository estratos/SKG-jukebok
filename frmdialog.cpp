#include "frmdialog.h"
#include "ui_frmdialog.h"

frmDialog::frmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    QObject::connect(ui->btnAccept,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
}

frmDialog::~frmDialog()
{
    delete ui;
}

void frmDialog::changeEvent(QEvent *e)
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

int frmDialog::DisplayYesNo(QString msg)
{
    ui->lblCaption->setText(msg);
    ui->btnAccept->setText("Yes");
    ui->btnCancel->setText("No");
    return exec();
}

int frmDialog::DisplayOkCancel(QString msg)
{
    ui->lblCaption->setText(msg);
    ui->btnAccept->setText("OK");
    ui->btnCancel->setText("Cancel");
    return exec();
}

int frmDialog::DisplayOther(QString msg,QString yesbtncaption,QString nobtncaption)
{
    ui->lblCaption->setText(msg);
    ui->btnAccept->setText(yesbtncaption);
    ui->btnCancel->setText(nobtncaption);
    return exec();
}
