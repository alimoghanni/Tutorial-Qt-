#include "Person.h"
#include <QDebug>

Person::Person(QObject *parent) :
    QObject{parent}
{

}

const QString &Person::name() const
{
    return m_name;
}

void Person::setName(const QString &newName)
{
    m_name = newName;
}

void Person::heSpeaks(const QString &words)
{
    emit speak(words);
}

void Person::listen(const QString &words)
{
    qDebug() << m_name << "is spwaking:" << words ;
}
