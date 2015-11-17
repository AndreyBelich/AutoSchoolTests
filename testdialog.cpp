#include <QtWidgets>
#include <cstdlib>
#include <ctime>
#include "ticket.h"
#include "testdialog.h"

TestDialog::TestDialog(QWidget *parent):QDialog(parent)
{
    readToFile();
    QLabel *nameLabel = new QLabel(tr("Введите Ваше &имя"));
    nameLine = new QLineEdit;
    nameLabel->setBuddy(nameLine);

    QLabel *surnameLabel = new QLabel(tr("Введите Вашу &фамилию"));
    surnameLine = new QLineEdit;
    surnameLabel->setBuddy(surnameLine);

    QLabel *patronymicLabel = new QLabel(tr("Введите Вашу &отчество"));
    patronymicLine = new QLineEdit;
    patronymicLabel->setBuddy(patronymicLine);

    QLabel *sizeLabel = new QLabel(tr("Выберите количество вопросов"));
    questSize = new QComboBox;
    setQuestSize();

    startButton = new QPushButton(tr("Начать тест"));
    startButton->setEnabled(false);
    startButton->setDefault(true);
    startButton->setStyleSheet("QPushButton{background-color:#CD1808;color:#4238CD;font:14px Verdana;}");
    exitButton = new QPushButton(tr("Выход"));
    exitButton->setStyleSheet("QPushButton{background-color:#1CCD1F;color:#4238CD;font:14px Verdana;}");

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(exitButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(surnameLabel,0,0);
    mainLayout->addWidget(surnameLine,0,1);
    mainLayout->addWidget(nameLabel,1,0);
    mainLayout->addWidget(nameLine,1,1);
    mainLayout->addWidget(patronymicLabel,2,0);
    mainLayout->addWidget(patronymicLine,2,1);
    mainLayout->addWidget(sizeLabel,3,0);
    mainLayout->addWidget(questSize,3,1);
    mainLayout->addLayout(buttonLayout,4,1);

    setLayout(mainLayout);
    setStyleSheet("TestDialog{background-color:#48CDB2;}");

    connect(nameLine,SIGNAL(textChanged(QString)),this,SLOT(startButtonEnabled()));
    connect(surnameLine,SIGNAL(textChanged(QString)),this,SLOT(startButtonEnabled()));
    connect(patronymicLine,SIGNAL(textChanged(QString)),this,SLOT(startButtonEnabled()));
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(startButton,SIGNAL(clicked()),this,SLOT(startTest()));

    setWindowTitle(tr("Стартовое окно"));
}

void TestDialog::readToFile()
{
    QFile mFile(":/source/Билет");
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(0,tr("Предупреждение"),tr("Не удалось открыть файл с вопросами"));
        return;
    }
    QTextStream stream(&mFile);
    Quest temp;
    while(!stream.atEnd())
    {
        stream>>temp;
        questions.push_back(temp);
        stream.flush();
    }
    mFile.close();
}

void TestDialog::setQuestSize()
{
    for(int i = 5; i <= questions.size(); i++)
    {
        questSize->addItem(QString::number(i));
    }
}

void TestDialog::startButtonEnabled()
{
    if(nameLine->text().isEmpty())
    {
        startButton->setEnabled(false);
        startButton->setStyleSheet("QPushButton{background-color:#CD1808;color:#4238CD;font:14px Verdana;}");
        return;
    }
    if(surnameLine->text().isEmpty())
    {
        startButton->setEnabled(false);
        startButton->setStyleSheet("QPushButton{background-color:#CD1808;color:#4238CD;font:14px Verdana;}");
        return;
    }
    if(patronymicLine->text().isEmpty())
    {
        startButton->setEnabled(false);
        startButton->setStyleSheet("QPushButton{background-color:#CD1808;color:#4238CD;font:14px Verdana;}");
        return;
    }
    startButton->setEnabled(true);
    startButton->setStyleSheet("QPushButton{background-color:#1CCD1F;color:#4238CD;font:14px Verdana;}");
}

void TestDialog::startTest()
{
    shuffle();
    int size = questSize->currentText().toInt();
    QVector<Quest> importVector;
    for(int i = 0; i < size; i++)
        importVector.push_back(questions[i]);
    student.setName(nameLine->text());
    student.setSurname(surnameLine->text());
    student.setPatronymic(patronymicLine->text());
    ticket = new Ticket(student,size,importVector);
    close();
    ticket->show();
    ticket->exec();
    delete ticket;
}

void TestDialog::shuffle()
{
    srand((unsigned)time(NULL));
    for(int i = 0; i < questions.size(); i++)
    {
        int random_index = rand()%questions.size();
        Quest temp = questions.at(i);
        questions[i] = questions[random_index];
        questions[random_index] = temp;
    }
}
