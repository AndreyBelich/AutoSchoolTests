#ifndef MAINBUTTON_H
#define MAINBUTTON_H



#include <QPushButton>

class MainButton:public QPushButton
{
    Q_OBJECT
private:
    int index;
public:
    MainButton(int i,QWidget *parent = 0);
protected:
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
};

#endif // MAINBUTTON_H
