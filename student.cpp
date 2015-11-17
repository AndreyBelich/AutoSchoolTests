#include <QDate>
#include "student.h"

Student::Student():name(""),surname(""),patronymic(""),result(false)
{
    QDate date = QDate::currentDate();
    day = date.day();
    month = date.month();
    year = date.year();
}

bool Student::getResult()const
{
    return result;
}

QString Student::getName()const
{
    return name;
}

QString Student::getSurname()const
{
    return surname;
}


QString Student::getPatronymic()const
{
    return patronymic;
}

int Student::getDay()const
{
    return day;
}

int Student::getMonth()const
{
    return month;
}

int Student::getYear()const
{
    return year;
}

void Student::setResult(int r)
{
    result = r;
}

void Student::setName(const QString &n)
{
    name = n;
}

void Student::setSurname(const QString &s)
{
    surname = s;
}

void Student::setPatronymic(const QString &p)
{
    patronymic = p;
}

QTextStream &operator<<(QTextStream &stream, const Student &s)
{
    stream<<s.getName()<<"\n"<<s.getSurname()<<"\n"<<s.getPatronymic()<<"\n"<<s.getResult()<<"\n";
    stream<<s.getDay()<<"\n"<<s.getMonth()<<"\n"<<s.getYear();
    return stream;
}

QTextStream &operator>>(QTextStream &stream, Student &s)
{
    s.name = stream.readLine();
    s.surname = stream.readLine();
    s.patronymic = stream.readLine();
    s.setResult(stream.readLine().toInt());
    s.day = stream.readLine().toInt();
    s.month = stream.readLine().toInt();
    s.year = stream.readLine().toInt();
    return stream;
}
