#include <QCoreApplication>
#include "Person.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *p = new QObject;
    Person *tom = new Person(p);
    Person *jerry = new Person(p);

    tom->setName("Tom");
    jerry->setName("Jerry");

    QObject::connect(tom, &Person::speak, jerry, &Person::listen);

    tom->heSpeaks("Hello, Jerry!");

    delete p;

    return a.exec();
}
