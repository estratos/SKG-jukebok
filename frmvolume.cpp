#include "frmvolume.h"
#include "ui_frmvolume.h"

frmVolume::frmVolume(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmVolume)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    QObject::connect(ui->btnUp,SIGNAL(clicked()),this,SIGNAL(VolumeUp()));
    QObject::connect(ui->btnDown,SIGNAL(clicked()),this,SIGNAL(VolumeDown()));
    QObject::connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(accept()));
}

frmVolume::~frmVolume()
{
    delete ui;
}

void frmVolume::changeEvent(QEvent *e)
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
