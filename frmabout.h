#ifndef FRMABOUT_H
#define FRMABOUT_H

#include <QDialog>

namespace Ui {
    class frmAbout;
}

class frmAbout : public QDialog {
    Q_OBJECT
public:
    frmAbout(QWidget *parent = 0);
    ~frmAbout();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmAbout *ui;
};

#endif // FRMABOUT_H
