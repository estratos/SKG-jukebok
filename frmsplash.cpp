#include "frmsplash.h"
#include "ui_frmsplash.h"
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include "version.h"

frmSplash::frmSplash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmSplash)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    ui->rbNormal->setChecked(true);
    ui->rbSmall->setChecked(true);
    ui->txtMusicDir->insert(QDesktopServices::storageLocation(QDesktopServices::MusicLocation));
    ui->lblVersion->setText("Version " + cVERSION_STR + ". Copyright 2010-11 by The Skeptical Geek.");

    QObject::connect(ui->btnChoose,SIGNAL(clicked()),this,SLOT(ChooseButtonClicked()));
    QObject::connect(ui->btnOK,SIGNAL(clicked()),this,SLOT(OKButtonClicked()));
}

frmSplash::~frmSplash()
{
    delete ui;
}

void frmSplash::changeEvent(QEvent *e)
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

void frmSplash::OKButtonClicked()
{
    QMessageBox box;
    QDir dir;
    if (ui->txtMusicDir->text().trimmed() == "")
    {
        box.setText("Please choose a directory where your music is located");
        box.exec();
    }
    else if (!dir.exists(ui->txtMusicDir->text().trimmed()))
    {
        box.setText("Invalid directory");
        box.exec();
    }
    else
    {
        this->hide();
    }
}

void frmSplash::ChooseButtonClicked()
{
    QFileDialog fdialog;
    fdialog.setFileMode(QFileDialog::Directory);
    fdialog.setOption(QFileDialog::ShowDirsOnly,true);
    ui->txtMusicDir->setText(fdialog.getExistingDirectory(this,tr("Select Music Directory"),
                             QDesktopServices::storageLocation(QDesktopServices::MusicLocation)));
}

void frmSplash::SetText(QString text)
{
    ui->lblLoading->setText(text);
}

void frmSplash::ShowFirstTime()
{
    ui->frameFirstTime->setVisible(true);
    ui->lblLoading->setVisible(false);
    this->exec();
}

void frmSplash::ShowLoading()
{
    ui->frameFirstTime->setVisible(false);
    ui->lblLoading->setVisible(true);
    //this->showNormal();
    this->open();
    QApplication::processEvents();
}

QString frmSplash::GetMusicDirectory()
{
    return ui->txtMusicDir->text().trimmed();
}

bool frmSplash::NormalSelected()
{
    if (ui->rbNormal->isChecked())
        return true;
    else
        return false;
}

bool frmSplash::Connected()
{
    return (ui->chkConnected->isChecked());
}

bool frmSplash::LargeSelected()
{
    if (ui->rbLarge->isChecked())
        return true;
    else
        return false;
}
