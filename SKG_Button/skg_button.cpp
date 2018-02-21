#include "skg_button.h"

SKG_Button::SKG_Button(QWidget *parent) :
    QLabel(parent)
{
    QPalette pal;

    this->resize(75,75);
    pal.setColor(QPalette::Window,Qt::white);
    pal.setColor(QPalette::WindowText,QColor(139,24,1));
    this->setPalette(pal);
    this->setAlignment(Qt::AlignCenter);
    //this->setFont(QFont("Nimbus Roman No9 L",24,QFont::Bold));
    this->setFont(QFont("Times New Roman",18,QFont::Bold));
    this->setLineWidth(7);
    this->setFrameShape(QFrame::Panel);
    this->setFrameShadow(QFrame::Raised);
}

void SKG_Button::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
        this->setFrameShadow(QFrame::Sunken);
}

void SKG_Button::mouseReleaseEvent(QMouseEvent *event)
{
    if (this->frameShadow()==QFrame::Sunken)
    {
        this->setFrameShadow(QFrame::Raised);
        clicked();
    }
}
