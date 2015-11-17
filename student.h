#ifndef STUDENT_H
#define STUDENT_H


#include <QString>
#include <QTextStream>

class Student
{
private:
    QString name;
    QString surname;
    QString patronymic;
    int result;
    int day;
    int month;
    int year;
public:
    Student();
    bool getResult()const;
    QString getName()const;
    QString getSurname()const;
    QString getPatronymic()const;
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    void setResult(int r);
    void setName(const QString &n);
    void setSurname(const QString &s);
    void setPatronymic(const QString &p);
    friend QTextStream &operator<<(QTextStream &stream, const Student &s);
    friend QTextStream &operator>>(QTextStream &stream, Student &s);
};

#endif // STUDENT_H
