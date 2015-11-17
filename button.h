#ifndef BUTTON_H
#define BUTTON_H


#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
private:
    int index;
public:
    Button(int i = 0,QWidget *parent = 0);
    int getIndex()const;
protected:
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
};
#endif // BUTTON_H
