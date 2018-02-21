#include "frmviewkeymappings.h"
#include "ui_frmviewkeymappings.h"

FrmViewKeyMappings::FrmViewKeyMappings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmViewKeyMappings)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    QObject::connect(ui->btnOK,SIGNAL(clicked()),this,SLOT(accept()));
}

FrmViewKeyMappings::~FrmViewKeyMappings()
{
    delete ui;
}

void FrmViewKeyMappings::changeEvent(QEvent *e)
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

void FrmViewKeyMappings::Clear()
{
    Mappings.clear();
    ui->txtKeyMappings->clear();
}

void FrmViewKeyMappings::Display()
{
    ui->txtKeyMappings->setText(Mappings.join("\n"));
    exec();
}
