#include <QtWidgets>
#include "mainbutton.h"
#include "manualdialog.h"
#include "testdialog.h"
#include "resultdialog.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    titleImage = new QLabel;
    QPixmap pix(":/source/title");
    titleImage->resize(pix.size());
    titleImage->setPixmap(pix);

    manualButton = new MainButton(1);
    manualButton->setText(tr("Справка"));
    manualButton->setStyleSheet("MainButton{background-color:#C5221F;color:#3252C5;font:20px,Arial;}");
    testButton = new MainButton(2);
    testButton->setText(tr("Пройти тестирование"));
    testButton->setStyleSheet("MainButton{background-color:#BFC51F;color:#3252C5;font:20px,Arial;}");
    informationButton = new MainButton(3);
    informationButton->setText(tr("Информация"));
    informationButton->setStyleSheet("MainButton{background-color:#2FC51B;color:#3252C5;font:20px,Arial;}");

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(manualButton);
    buttonLayout->addWidget(testButton);
    buttonLayout->addWidget(informationButton);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(titleImage);
    mainLayout->addLayout(buttonLayout);

    QWidget *widget = new QWidget(this);
    widget->setLayout(mainLayout);

    setCentralWidget(widget);
    setWindowTitle(tr("Автошкола"));
    setStyleSheet("QWidget{background-color:#C57C08;}");

    connect(manualButton,SIGNAL(clicked()),this,SLOT(callManualDialog()));
    connect(testButton,SIGNAL(clicked()),this,SLOT(callTestDialog()));
    connect(informationButton,SIGNAL(clicked()),this,SLOT(callResultDialog()));
}


void MainWindow::callManualDialog()
{
    manual = new ManualDialog;
    manual->show();
    hide();
    manual->exec();
    delete manual;
    show();
}


void MainWindow::callTestDialog()
{
    test = new TestDialog;
    test->show();
    hide();
    test->exec();
    delete test;
    show();
}

void MainWindow::callResultDialog()
{
    result = new ResultDialog;
    result->show();
    hide();
    result->exec();
    delete result;
    show();
}
