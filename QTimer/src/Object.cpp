#include "Object.h"
#include <QTimer>
#include <QDebug>

Object::Object(QObject *parent) :
    QObject{parent},
    m_timer(new QTimer(this))
{
    connect(m_timer, &QTimer::timeout, this, &Object::onTimeOut);
}

void Object::start()
{
    m_timer->start(50);
}

void Object::onTimeOut()
{
    qDebug() << "Time terminates ....";
}
