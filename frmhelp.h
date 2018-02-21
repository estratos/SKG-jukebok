#ifndef FRMHELP_H
#define FRMHELP_H

#include <QDialog>
#include <QApplication>

namespace Ui {
    class frmHelp;
}

class frmHelp : public QDialog {
    Q_OBJECT
public:
    frmHelp(QWidget *parent = 0);
    ~frmHelp();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmHelp *ui;

private slots:
    void btnDownClicked();
    void btnUpClicked();
};

#endif // FRMHELP_H
