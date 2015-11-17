#ifndef TICKET_H
#define TICKET_H


#include <QDialog>
#include <QVector>
#include "student.h"
#include "quest.h"


class QLabel;
class Button;
class QPushButton;
class Timer;

class Ticket : public QDialog
{
    Q_OBJECT
private:
    int questCount;
    Student student;
    QLabel *image;
    QLabel *question;
    QLabel *questNumber;
    QLabel *correctAnswerLabel;
    QLabel *incorrectAnswerLabel;
    Button *firstAnswer;
    Button *secondAnswer;
    Button *thirdAnswer;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *endTest;
    QPushButton *closeButton;
    Timer *myTimer;
    QVector<Quest> questList;
    int currentIndex;
    int correctCounter;
    int incorrectCounter;
    int minIndex;
    int maxIndex;
    bool *inspectArr;
    void navigatorsButton();
    void TrueAnswer();
    void writeToFile();
    void finishFunction();
public:
    Ticket(const Student &s,int size,const QVector<Quest> &q,QWidget * parent = 0);
    ~Ticket();
    int getQuestSize()const;
protected:
    virtual void closeEvent(QCloseEvent *);
signals:
    void lastAnswer();
private slots:
    void nextConnect();
    void inspectAnswer();
    void finishTest();
    void previousConnect();
};

#endif // TICKET_H
