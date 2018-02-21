#ifndef FRMSPLASH_H
#define FRMSPLASH_H

#include <QDialog>

namespace Ui {
    class frmSplash;
}

class frmSplash : public QDialog {
    Q_OBJECT
public:
    frmSplash(QWidget *parent = 0);
    ~frmSplash();

    void SetText(QString text);
    void ShowFirstTime();
    void ShowLoading();
    QString GetMusicDirectory();
    bool NormalSelected();
    bool Connected();
    bool LargeSelected();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmSplash *ui;

private slots:
    void OKButtonClicked();
    void ChooseButtonClicked();
};

#endif // FRMSPLASH_H
