#ifndef FRMVOLUME_H
#define FRMVOLUME_H

#include <QDialog>

namespace Ui {
    class frmVolume;
}

class frmVolume : public QDialog {
    Q_OBJECT
public:
    frmVolume(QWidget *parent = 0);
    ~frmVolume();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmVolume *ui;

signals:
    void VolumeUp();
    void VolumeDown();
};

#endif // FRMVOLUME_H
