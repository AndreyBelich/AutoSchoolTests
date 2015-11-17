#ifndef QUEST_H
#define QUEST_H

#include <QString>
#include <QTextStream>

class Quest
{
private:
    QString imageName;
    QString questionText;
    QString answer_1;
    QString answer_2;
    QString answer_3;
    int correctAnswer;
public:
    Quest(const QString &in = "", const QString &qt = "",const QString &a1 = "",const QString &a2 = "",
            const QString &a3 = "", int ca = 0);
    void setImageName(const QString &in);
    void setQuestionText(const QString &qt);
    void setFirstAnswer(const QString &a1);
    void setSecondAnswer(const QString &a2);
    void setThirdAnswer(const QString &a3);
    void setCorrectAnswer(int ca);
    QString getImageName()const;
    QString getQuestionText()const;
    QString getFirstAnswer()const;
    QString getSecondAnswer()const;
    QString getThirdAnswer()const;
    int getCorrectAnswer()const;
    friend QTextStream &operator>>(QTextStream &stream, Quest &q);
};

#endif // QUEST_H
