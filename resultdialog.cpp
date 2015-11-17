#include <QtWidgets>
#include "resultdialog.h"

ResultDialog::ResultDialog(QWidget *parent):QDialog(parent)
{
    tWidget = new QTableWidget;
    readToFile();
    if(collections.isEmpty())
        tWidget->setVisible(false);
    countLabel = new QLabel;
    countLabel->setText(tr("<h2 align = center>Количество человек проходивших тест: %1</h2>").arg(collections.size()));
    countLabel->setStyleSheet("QLabel{font-size:12px;color:black;}");//налаштувати для нього стиль
    int good = 0;
    int bad = 0;
    for(int i = 0; i < collections.size(); i++)
    {
        if(collections[i].getResult())
            good++;
        else
            bad++;
    }
    goodLabel = new QLabel(tr("<h2 align=center>Количество человек успешно сдавших тест: %1</h2>").arg(good));
    goodLabel->setStyleSheet("QLabel{font-size:12px;color:#18CD1B;}");
    badLabel = new QLabel(tr("<h2 align=center>Количество человек не сдавших тест: %1</h2>").arg(bad));
    badLabel->setStyleSheet("QLabel{font-size:12px;color:#CD0E00}");
    tWidget->setColumnCount(3);
    tWidget->setRowCount(collections.size());
    QStringList header;
    header<<tr("Фамилия имя отчество")<<tr("Дата сдачи теста")<<tr("Результат");
    tWidget->setHorizontalHeaderLabels(header);
    tWidget->setColumnWidth(0,220);
    tWidget->setColumnWidth(1,120);
    tWidget->setColumnWidth(2,120);
    QTableWidgetItem *item = NULL;
    QString itemText;
    for(int i = 0; i < collections.size(); i++)
    {
        int j = 0;
        itemText = collections[i].getSurname() + " " + collections[i].getName() + " " +
                collections[i].getPatronymic();
        item = new QTableWidgetItem;
        item->setText(itemText);
        item->setTextAlignment(Qt::AlignCenter);
        item->setFlags(Qt::ItemIsEditable);
        tWidget->setItem(i,j,item);
        j++;
        itemText = QString::number(collections[i].getDay()) + "." + QString::number(collections[i].getMonth())
                + "." + QString::number(collections[i].getYear());
        item = new QTableWidgetItem;
        item->setText(itemText);
        item->setTextAlignment(Qt::AlignCenter);
        item->setFlags(Qt::ItemIsEditable);
        tWidget->setItem(i,j,item);
        j++;
        if(collections[i].getResult() == true)
            itemText = tr("Сдал");
        else
            itemText = tr("Не сдал");
        item = new QTableWidgetItem;
        item->setText(itemText);
        item->setTextAlignment(Qt::AlignCenter);
        item->setFlags(Qt::ItemIsEditable);
        tWidget->setItem(i,j,item);
    }
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(countLabel);
    mainLayout->addWidget(goodLabel);
    mainLayout->addWidget(badLabel);
    mainLayout->addWidget(tWidget);
    setLayout(mainLayout);
    setFixedWidth(500);
    setMaximumHeight(600);
    setStyleSheet("QTableWidget{background-color:#DCDEC0;color:black;border:2px solid green;}");
    QPalette pal = palette();
    pal.setColor(backgroundRole(),QColor("#C57C08"));
    setPalette(pal);
    setAutoFillBackground(true);
}

void ResultDialog::readToFile()
{
    QFile mFile("result.txt");
    try
    {
        if(!mFile.open(QFile::ReadOnly | QFile::Text))
        {
            throw tr("Не удаось открыть файл!");
        }
    }
    catch(const QString &message)
    {
        QMessageBox::warning(0,tr("Предупреждение"),message);
        tWidget->setVisible(false);
        return;
    }
    QTextStream stream(&mFile);
    QString str;
    Student temp;
    str = stream.readLine();
    while(!stream.atEnd())
    {
        stream >> temp;
        collections.push_back(temp);
        stream.flush();
    }
    mFile.close();
}
