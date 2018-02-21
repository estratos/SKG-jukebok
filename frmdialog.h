#ifndef FRMDIALOG_H
#define FRMDIALOG_H

#include <QDialog>

namespace Ui {
    class frmDialog;
}

class frmDialog : public QDialog {
    Q_OBJECT
public:
    frmDialog(QWidget *parent = 0);
    ~frmDialog();

    int DisplayYesNo(QString msg);
    int DisplayOkCancel(QString msg);
    int DisplayOther(QString msg,QString yesbtncaption,QString nobtncaption);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmDialog *ui;
};

#endif // FRMDIALOG_H
