#ifndef FRMVIEWKEYMAPPINGS_H
#define FRMVIEWKEYMAPPINGS_H

#include <QDialog>

namespace Ui {
    class FrmViewKeyMappings;
}

class FrmViewKeyMappings : public QDialog {
    Q_OBJECT

public:
    FrmViewKeyMappings(QWidget *parent = 0);
    ~FrmViewKeyMappings();

    void Clear();
    void AddKeyMapping(QString strin){Mappings.append(strin);}
    void Display();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::FrmViewKeyMappings *ui;

    QStringList Mappings;
};

#endif // FRMVIEWKEYMAPPINGS_H
