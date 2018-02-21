#ifndef SKG_BUTTON_H
#define SKG_BUTTON_H

#include <QtGui/QLabel>
#include <QMouseEvent>

class SKG_Button : public QLabel
{
    Q_OBJECT

public:
    SKG_Button(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void clicked();
};

#endif
