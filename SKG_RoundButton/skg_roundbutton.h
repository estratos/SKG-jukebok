#ifndef SKG_ROUNDBUTON_H
#define SKG_ROUNDBUTON_H

#include <QtGui/QLabel>

class SKG_RoundButton : public QLabel
{
    Q_OBJECT

public:
    SKG_RoundButton(QWidget *parent = 0);
    void Highlight();
    void UnHighlight();

private:
    QString ButtonStyleSheet();
    bool pressed;
    QColor HighlightColor;
    QColor UnHighlightColor;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:
    void clicked(QString caption);

};

#endif
