#include "mainbutton.h"

MainButton::MainButton(int i,QWidget *parent):QPushButton(parent),index(i)
{
    setFixedSize(210,100);
}

void MainButton::enterEvent(QEvent *)
{
    setStyleSheet("MainButton{background-color:#776CC5;color:#C55B2A;font:20px,Arial;}");
}

void MainButton::leaveEvent(QEvent *)
{
    if(index == 1)
        setStyleSheet("MainButton{background-color:#C5221F;color:#3252C5;font:20px,Arial;}");
    else if(index == 2)
        setStyleSheet("MainButton{background-color:#BFC51F;color:#3252C5;font:20px,Arial;}");
    else if(index == 3)
        setStyleSheet("MainButton{background-color:#2FC51B;color:#3252C5;font:20px,Arial;}");
}
