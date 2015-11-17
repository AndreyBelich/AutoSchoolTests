#ifndef TESTDIALOG_H
#define TESTDIALOG_H


#include <QDialog>
#include <QVector>
#include "student.h"
#include "quest.h"

class QComboBox;
class QLineEdit;
class QPushButton;
class Ticket;

class TestDialog: public QDialog
{
    Q_OBJECT
private:
    QLineEdit *nameLine;
    QLineEdit *surnameLine;
    QLineEdit *patronymicLine;
    QComboBox *questSize;
    QPushButton *startButton;
    QPushButton *exitButton;
    Ticket *ticket;
    QVector<Quest> questions;
    Student student;
    void readToFile();
    void setQuestSize();
    void shuffle();
public:
    explicit TestDialog(QWidget *parent = 0);
private slots:
    void startButtonEnabled();
    void startTest();
};

#endif // TESTDIALOG_H
