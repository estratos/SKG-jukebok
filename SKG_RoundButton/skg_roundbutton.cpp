#include "skg_roundbutton.h"
#include <QResizeEvent>
#include <QMouseEvent>

SKG_RoundButton::SKG_RoundButton(QWidget *parent) :
    QLabel(parent)
{
    pressed=false;
    this->sizePolicy().setHeightForWidth(true);
    this->setStyleSheet(ButtonStyleSheet().arg(QString::number(this->size().width() / 2),QString("outset")));
}

QString SKG_RoundButton::ButtonStyleSheet()
{
    return QString("border-radius:%1px;"
                   "border-style:%2;"
                   "border-width:3px;"
                   "border-color:gray;"
                   "background-color:white;");
}

void SKG_RoundButton::resizeEvent(QResizeEvent *event)
{
    int x;
    if (event->size().width() < event->size().height())
    {
        x = event->size().width();
    }
    else
    {
        x = event->size().height();
    }
    //this->setStyleSheet(ButtonStyleSheet().arg(QString::number(event->size().width() / 2),QString("outset")));
    this->setStyleSheet(ButtonStyleSheet().arg(QString::number(x / 2),QString("outset")));

}

void SKG_RoundButton::mousePressEvent(QMouseEvent *event)
{
    int x;
    if (this->size().width() < this->size().height())
    {
        x = this->size().width();
    }
    else
    {
        x = this->size().height();
    }
    pressed=true;
    this->setStyleSheet(ButtonStyleSheet().arg(QString::number(x / 2),QString("inset")));
}

void SKG_RoundButton::mouseReleaseEvent(QMouseEvent *event)
{
    int x;
    if (this->size().width() < this->size().height())
    {
        x = this->size().width();
    }
    else
    {
        x = this->size().height();
    }
    if (pressed)
    {
        pressed=false;
        this->setStyleSheet(ButtonStyleSheet().arg(QString::number(x / 2),QString("outset")));
        clicked(this->text());
    }
}

void SKG_RoundButton::Highlight()
{
    QPalette pal;
    pal.setColor(QPalette::Window,QColor("lightsteelgray"));
    pal.setColor(QPalette::Text,QColor("lightsteelgray"));
    this->setPalette(pal);
}

void SKG_RoundButton::UnHighlight()
{
    QPalette pal;
    pal.setColor(QPalette::Window,QColor("white"));
    pal.setColor(QPalette::Text,QColor("lightsteelgray"));
    this->setPalette(pal);
}
