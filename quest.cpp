#include "quest.h"

Quest::Quest(const QString &in, const QString &qt,const QString &a1,const QString &a2,
        const QString &a3, int ca):imageName(in),questionText(qt),answer_1(a1),answer_2(a2),
                                   answer_3(a3),correctAnswer(ca)
{

}

void Quest::setImageName(const QString &in)
{
    imageName = in;
}


void Quest::setQuestionText(const QString &qt)
{
    questionText = qt;
}

void Quest::setFirstAnswer(const QString &a1)
{
    answer_1 = a1;
}

void Quest::setSecondAnswer(const QString &a2)
{
    answer_2 = a2;
}

void Quest::setThirdAnswer(const QString &a3)
{
    answer_3 = a3;
}

void Quest::setCorrectAnswer(int ca)
{
    correctAnswer = ca;
}

QString Quest::getImageName()const
{
    return imageName;
}

QString Quest::getQuestionText()const
{
    return questionText;
}

QString Quest::getFirstAnswer()const
{
    return answer_1;
}

QString Quest::getSecondAnswer()const
{
    return answer_2;
}

QString Quest::getThirdAnswer()const
{
    return answer_3;
}

int Quest::getCorrectAnswer()const
{
    return correctAnswer;
}

QTextStream &operator>>(QTextStream &stream, Quest &q)
{
    q.imageName = stream.readLine();
    q.questionText = stream.readLine();
    q.answer_1 = stream.readLine();
    q.answer_2 = stream.readLine();
    q.answer_3 = stream.readLine();
    q.correctAnswer = stream.readLine().toInt();
    return stream;
}
