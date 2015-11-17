#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainButton;
class QLabel;
class ManualDialog;
class TestDialog;
class ResultDialog;

class MainWindow:public QMainWindow
{
    Q_OBJECT
private:
    QLabel *titleImage;
    MainButton *manualButton;
    MainButton *testButton;
    MainButton *informationButton;
    ManualDialog *manual;
    TestDialog *test;
    ResultDialog *result;
public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void callManualDialog();
    void callTestDialog();
    void callResultDialog();
};

#endif // MAINWINDOW_H
