#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H


#include <QDialog>
#include <QVector>
#include "student.h"

class QLabel;
class QPushButton;
class QTableWidget;

class ResultDialog: public QDialog
{
    Q_OBJECT
private:
    QVector<Student> collections;
    QLabel *countLabel;
    QLabel *goodLabel;
    QLabel *badLabel;
    QTableWidget *tWidget;
    void readToFile();
public:
    explicit ResultDialog(QWidget *parent = 0);
};

#endif // RESULTDIALOG_H
