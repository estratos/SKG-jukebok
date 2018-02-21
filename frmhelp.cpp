#include "frmhelp.h"
#include "ui_frmhelp.h"
#include "jukeboxconfig.h"

frmHelp::frmHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmHelp)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ui->btnUp->setPixmap(QPixmap(UpArrow()));
    ui->btnDown->setPixmap(QPixmap(DownArrow()));

    QObject::connect(ui->btnUp,SIGNAL(clicked()),this,SLOT(btnUpClicked()));
    QObject::connect(ui->btnDown,SIGNAL(clicked()),this,SLOT(btnDownClicked()));
    QObject::connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(accept()));
    //ui->textBrowser->setSource(QUrl(ResourcesDirectory() + "/manual/manual.html"));
    ui->textBrowser->setSource(QUrl("resources/manual/manual.html"));
}

frmHelp::~frmHelp()
{
    delete ui;
}

void frmHelp::changeEvent(QEvent *e)
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

void frmHelp::btnUpClicked()
{
    QApplication::sendEvent(ui->textBrowser,new QKeyEvent(QEvent::KeyPress, Qt::Key_Up, 0, 0));
}

void frmHelp::btnDownClicked()
{
    QApplication::sendEvent(ui->textBrowser,new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, 0, 0));
}

