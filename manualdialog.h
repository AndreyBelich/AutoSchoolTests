#ifndef MANUALDIALOG_H
#define MANUALDIALOG_H


#include <QDialog>

class ManualDialog:public QDialog
{
    Q_OBJECT
public:
    explicit ManualDialog(QWidget *parent = 0);//конструктор
};

#endif // MANUALDIALOG_H
