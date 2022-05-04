#include "Object.h"
#include <QDebug>

Object::Object(QObject *parent) :
    QObject{parent}
{
    connect(this, SIGNAL(signal()), this, SLOT(onSignal()));
    connect(this, SIGNAL(signal(int)), this, SLOT(onSignal(int)));
    connect(this, SIGNAL(signal(char)), this, SLOT(onSignal(char)));
    connect(this, SIGNAL(signal(QString)), this, SLOT(onSignal(QString)));
}

void Object::emitAllSignals()
{
    emit signal();
    emit signal(-5);
    emit signal('#');
    emit signal("Hello World!");
}

void Object::onSignal()
{
    qDebug() << "onSignal()";
}

void Object::onSignal(int e)
{
    qDebug() << "onSignal(int e)" << e;
}

void Object::onSignal(char c)
{
    qDebug() << "onSignal(char c)" << c;
}

void Object::onSignal(const QString &s)
{
    qDebug() << "onSignal(QString &s)" << s;
}
