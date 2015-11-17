#include "button.h"

Button::Button(int i,QWidget *parent):QPushButton(parent),index(i)
{
    setFixedSize(900,30);
    setStyleSheet("Button{background-color:#B9C5C2;}");
}

int Button::getIndex()const
{
    return index;
}

void Button::enterEvent(QEvent *)
{
    if(isEnabled())
        setStyleSheet("Button{background-color:#8827C5;}");
}


void Button::leaveEvent(QEvent *)
{
    if(isEnabled())
        setStyleSheet("Button{background-color:#B9C5C2;}");
}
