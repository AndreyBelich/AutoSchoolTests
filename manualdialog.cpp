#include <QtWidgets>
#include "manualdialog.h"


ManualDialog::ManualDialog(QWidget *parent):QDialog(parent)
{
    QLabel *firstLabel = new QLabel(tr("1"));
    QTextEdit *firstText = new QTextEdit;
    firstText->setText(tr("     Перед началом теста правильно введите свои персональные данные, а так же выберите количество вопросов для теста. После того как вы убедитесь в том "
                          "что ввели данные правильно, нажмите кнопку \"Начать тест\". Учтите, что изменить персональные данные в процессе сдачи теста будет невозможно."
                          "Минимальное количество вопросов - 5."));
    firstText->setReadOnly(true);
    firstText->setAlignment(Qt::AlignJustify);
    QLabel *secondLabel = new QLabel(tr("2"));
    QTextEdit *secondText = new QTextEdit;
    secondText->setText(tr("    После нажатия кнопки \"Начать тест\" начнется тест. Учтите, что время для сдачи теста ограничено. "
                           "На каждый вопрос Вам будет выделена 1 минута времени. Для того что бы успешно сдать тест Вам необходимо дать как можно больше правильных ответов."
                           "Вы так же можете ответить неправильно. Учтите что количество неправильных ответов зависит от того сколько в тесте будет вопросов. На каждые 10 вопросов Вам предоставляется право на один неправильный ответ."
                           "Так же учтите что как только отведенное время закончится, тест завершится."));
    secondText->setReadOnly(true);
    secondText->setAlignment(Qt::AlignJustify);
    QLabel *thirdLabel = new QLabel(tr("3"));
    QTextEdit *thirdText = new QTextEdit;
    thirdText->setText(tr("     Во время теста студенту запрещено покидать комнату для тестирования, а так же использовать различные електронные приборы либо различного "
                          "рода литературу. В случае нарушения данных правил экзаменатор имеет право остановить тест и поставить за него неудовлетворительную оценку."
                          "Желаем удачи при сдаче теста!"));
    thirdText->setReadOnly(true);
    thirdText->setAlignment(Qt::AlignJustify);
    QHBoxLayout *firstLayout = new QHBoxLayout;
    firstLayout->addWidget(firstLabel);
    firstLayout->addWidget(firstText);

    QHBoxLayout *secondLayout = new QHBoxLayout;
    secondLayout->addWidget(secondLabel);
    secondLayout->addWidget(secondText);

    QHBoxLayout *thirdLayout = new QHBoxLayout;
    thirdLayout->addWidget(thirdLabel);
    thirdLayout->addWidget(thirdText);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(10);
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(secondLayout);
    mainLayout->addLayout(thirdLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("Справка"));
    setStyleSheet("QLabel{font-size:25px;font-weight:bold;}"
                  "QTextEdit{font-size:16px;}"
                  "ManualDialog{background-color:#C57C08;}");
    resize(750,550);
}
