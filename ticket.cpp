#include <QtWidgets>
#include "button.h"
#include "timer.h"
#include "ticket.h"

Ticket::Ticket(const Student &s,int size, const QVector<Quest> &q, QWidget *parent):QDialog(parent),questCount(size),student(s),currentIndex(0),correctCounter(0),incorrectCounter(0),
                                minIndex(0),maxIndex(size - 1)
{
    questList = q;
    inspectArr = new bool[size];
    for(int i = 0; i < getQuestSize(); i++)
        inspectArr[i] = false;
    questNumber = new QLabel(tr("<h2 align=center>Вопрос № %1</h2>").arg(currentIndex + 1));
    QPixmap pix;
    try
    {
        if(!pix.load(questList[currentIndex].getImageName()))
            throw 1;
    }
    catch(int)
    {
        pix.load(":/ticket_1/no_image");
    }
    image = new QLabel;
    image->setPixmap(pix);
    question = new QLabel;
    question->setText(questList.at(currentIndex).getQuestionText());
    question->setAlignment(Qt::AlignCenter);
    question->setStyleSheet("QLabel{font-size:14px;font-weight:bold;}");

    firstAnswer = new Button(1,this);
    firstAnswer->setText(questList.at(currentIndex).getFirstAnswer());
    firstAnswer->setCheckable(true);
    secondAnswer = new Button(2,this);
    secondAnswer->setText(questList.at(currentIndex).getSecondAnswer());
    secondAnswer->setCheckable(true);
    thirdAnswer = new Button(3,this);
    thirdAnswer->setText(questList.at(currentIndex).getThirdAnswer());
    thirdAnswer->setCheckable(true);

    nextButton = new QPushButton(tr("&Следующий вопрос"));
    endTest = new QPushButton(tr("&Завершить тест"));
    previousButton = new QPushButton(tr("&Предыдущий вопрос"));
    closeButton = new QPushButton(tr("&Выход"));
    closeButton->setVisible(false);

    myTimer = new Timer(getQuestSize() * 60,this);
    correctAnswerLabel = new QLabel(tr("<h3>Количество правильных ответов: %1</h3>").arg(correctCounter));
    incorrectAnswerLabel = new QLabel(tr("<h3>Количество неправильных ответов: %1</h3>").arg(incorrectCounter));

    QHBoxLayout *endLayout = new QHBoxLayout;
    endLayout->addWidget(endTest);
    endLayout->addWidget(closeButton);

    QVBoxLayout *timerLayout = new QVBoxLayout;
    timerLayout->setSpacing(10);
    timerLayout->addWidget(myTimer);
    timerLayout->addWidget(correctAnswerLabel);
    timerLayout->addWidget(incorrectAnswerLabel);
    timerLayout->addLayout(endLayout);

    QHBoxLayout *imageLayout = new QHBoxLayout;
    imageLayout->setSpacing(40);
    imageLayout->addWidget(image);
    imageLayout->addLayout(timerLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(previousButton);
    buttonLayout->addWidget(nextButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(questNumber);
    layout->addSpacing(25);
    layout->addLayout(imageLayout);
    layout->addSpacing(25);
    layout->addWidget(question);
    layout->addSpacing(25);
    layout->addWidget(firstAnswer);
    layout->addWidget(secondAnswer);
    layout->addWidget(thirdAnswer);
    layout->addLayout(buttonLayout);

    setLayout(layout);

    connect(nextButton,SIGNAL(clicked()),this,SLOT(nextConnect()));
    connect(previousButton,SIGNAL(clicked()),this,SLOT(previousConnect()));
    connect(firstAnswer,SIGNAL(clicked()),this,SLOT(inspectAnswer()));
    connect(secondAnswer,SIGNAL(clicked()),this,SLOT(inspectAnswer()));
    connect(thirdAnswer,SIGNAL(clicked()),this,SLOT(inspectAnswer()));
    connect(endTest,SIGNAL(clicked()),this,SLOT(finishTest()));
    connect(myTimer,SIGNAL(endTime()),this,SLOT(finishTest()));
    connect(this,SIGNAL(lastAnswer()),this,SLOT(finishTest()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
    setWindowTitle(tr("Тестовый билет"));
}

void Ticket::nextConnect()
{
    navigatorsButton();
    currentIndex++;
    if(currentIndex > maxIndex)
        currentIndex = minIndex;
    for(int i = currentIndex; i < getQuestSize(); i++)
    {
        if(inspectArr[i] == false)
        {
            currentIndex = i;
            break;
        }
    }
    questNumber->setText(tr("<h2 align=center>Вопрос № %1</h2>").arg(currentIndex + 1));
    QPixmap pix;
    try
    {
        if(!pix.load(questList.at(currentIndex).getImageName()))
            throw 1;
    }
    catch(int)
    {
        pix.load(":/ticket_1/no_image");
    }
    image->setPixmap(pix);
    question->setText(questList.at(currentIndex).getQuestionText());
    question->setAlignment(Qt::AlignCenter);
    firstAnswer->setText(questList.at(currentIndex).getFirstAnswer());
    secondAnswer->setText(questList.at(currentIndex).getSecondAnswer());
    thirdAnswer->setText(questList.at(currentIndex).getThirdAnswer());
}

void Ticket::previousConnect()
{
    navigatorsButton();
    currentIndex--;
    if(currentIndex < minIndex)
        currentIndex = maxIndex;
    for(int i = currentIndex; i >= 0; i--)
    {
        if(inspectArr[i] == false)
        {
            currentIndex = i;
            break;
        }
    }
    questNumber->setText(tr("<h2 align=center>Вопрос № %1</h2>").arg(currentIndex + 1));
    QPixmap pix;
    try
    {
        if(!pix.load(questList.at(currentIndex).getImageName()))
            throw 1;
    }
    catch(int)
    {
        pix.load(":/ticket_1/no_image");
    }
    image->setPixmap(pix);
    question->setText(questList.at(currentIndex).getQuestionText());
    question->setAlignment(Qt::AlignCenter);
    firstAnswer->setText(questList.at(currentIndex).getFirstAnswer());
    secondAnswer->setText(questList.at(currentIndex).getSecondAnswer());
    thirdAnswer->setText(questList.at(currentIndex).getThirdAnswer());
}

void Ticket::navigatorsButton()
{
    firstAnswer->setEnabled(true);
    firstAnswer->setStyleSheet("Button{background-color:#B9C5C2;}");
    firstAnswer->setCheckable(true);
    secondAnswer->setEnabled(true);
    secondAnswer->setStyleSheet("Button{background-color:#B9C5C2;}");
    secondAnswer->setCheckable(true);
    thirdAnswer->setEnabled(true);
    thirdAnswer->setStyleSheet("Button{background-color:#B9C5C2;}");
    thirdAnswer->setCheckable(true);
}

void Ticket::inspectAnswer()
{
    firstAnswer->setEnabled(false);
    secondAnswer->setEnabled(false);
    thirdAnswer->setEnabled(false);
    if(firstAnswer->isChecked() && firstAnswer->getIndex() == questList.at(currentIndex).getCorrectAnswer())
    {
        firstAnswer->setCheckable(false);
        firstAnswer->setStyleSheet("Button{background-color:green;color:black;}");
        TrueAnswer();
    }
    else if(secondAnswer->isChecked() && secondAnswer->getIndex() == questList.at(currentIndex).getCorrectAnswer())
    {
        secondAnswer->setCheckable(false);
        secondAnswer->setStyleSheet("Button{background-color:green;color:black;}");
        TrueAnswer();
    }
    else if(thirdAnswer->isChecked() && thirdAnswer->getIndex() == questList.at(currentIndex).getCorrectAnswer())
    {
        thirdAnswer->setCheckable(false);
        thirdAnswer->setStyleSheet("Button{background-color:green;color:black;}");
        TrueAnswer();
    }
    else
    {
        firstAnswer->setCheckable(false);
        secondAnswer->setCheckable(false);
        thirdAnswer->setCheckable(false);
        if(firstAnswer->getIndex() == questList.at(currentIndex).getCorrectAnswer())
        {
            firstAnswer->setStyleSheet("Button{background-color:green;color:black;}");
            secondAnswer->setStyleSheet("Button{background-color:#C51400;color:black;}");
            thirdAnswer->setStyleSheet("Button{background-color:#C51400;color:black;}");
        }
        else if(secondAnswer->getIndex() == questList.at(currentIndex).getCorrectAnswer())
        {
            firstAnswer->setStyleSheet("Button{background-color:#C51400;color:black;}");
            secondAnswer->setStyleSheet("Button{background-color:green;color:black;}");
            thirdAnswer->setStyleSheet("Button{background-color:#C51400;color:black;}");
        }
        else if(thirdAnswer->getIndex() == questList.at(currentIndex).getCorrectAnswer())
        {
            firstAnswer->setStyleSheet("Button{background-color:#C51400;color:black;}");
            secondAnswer->setStyleSheet("Button{background-color:#C51400;color:black;}");
            thirdAnswer->setStyleSheet("Button{background-color:green;color:black;}");
        }
        incorrectCounter++;
        correctAnswerLabel->setText(tr("<h3>Количество правильных ответов: %1</h3>").arg(correctCounter));
        incorrectAnswerLabel->setText(tr("<h3>Количество неправильных ответов: %1</h3>").arg(incorrectCounter));
    }
    inspectArr[currentIndex] = true;
    for(int i = 0; i < getQuestSize(); i++)
    {
        if(inspectArr[i] == false)
        {
            minIndex = i;
            break;
        }
    }
    for(int i = (getQuestSize() - 1); i >= 0; i--)
    {
        if(inspectArr[i] == false)
        {
            maxIndex = i;
            break;
        }
    }
    if((correctCounter + incorrectCounter) == getQuestSize())
    {
        nextButton->setEnabled(false);
        previousButton->setEnabled(false);
        emit lastAnswer();
    }
}

void Ticket::TrueAnswer()
{
    correctCounter++;
    correctAnswerLabel->setText(tr("<h3>Количество правильных ответов: %1</h3>").arg(correctCounter));
    incorrectAnswerLabel->setText(tr("<h3>Количество неправильных ответов: %1</h3>").arg(incorrectCounter));
}

void Ticket::finishTest()
{
    if((correctCounter + incorrectCounter) < getQuestSize() && myTimer->getTime() > 0)
    {
        int userAnswer = QMessageBox::information(0,tr("Сообщение"),tr("Вы ответили не на все вопросы. Вы уверены что хотите завершить тест?"),
                QMessageBox::Yes | QMessageBox::No);
        if(userAnswer == QMessageBox::Yes)
            finishFunction();
    }
    else
        finishFunction();
}

void Ticket::finishFunction()
{
    myTimer->stopTimer();
    endTest->setEnabled(false);
    nextButton->setEnabled(false);
    previousButton->setEnabled(false);
    firstAnswer->setEnabled(false);
    secondAnswer->setEnabled(false);
    thirdAnswer->setEnabled(false);
    int badAnswerCounter = getQuestSize() / 10;
    if(correctCounter >= (getQuestSize() - badAnswerCounter))
    {
        QMessageBox::information(this,tr("Сообщение"),tr("Поздравляем Вы сдали тест!"));
        student.setResult(1);
    }
    else
    {
        QMessageBox::information(this,tr("Сообщение"),tr("К сожалению Вы не сдали тест!<br>Подготовьтесь получше и повторите попытку"));
        student.setResult(0);
    }
    closeButton->setVisible(true);
}

int Ticket::getQuestSize()const
{
    return questCount;
}

Ticket::~Ticket()
{
    delete [] inspectArr;
}

void Ticket::writeToFile()
{
    QFile mFile("result.txt");
    if(!mFile.open(QFile::WriteOnly | QFile::Append | QFile::Text))
    {
        QMessageBox::information(0,tr("Сообщение"),tr("Не удалось открыть файл"));
        return;
    }
    QTextStream stream(&mFile);
    stream<<"\n"<<student;
    mFile.close();
}

void Ticket::closeEvent(QCloseEvent *)
{
    writeToFile();
}
