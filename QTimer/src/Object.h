#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

class QTimer;

class Object : public QObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent = nullptr);

    void start();

private:
    QTimer *m_timer;

public slots:
    void onTimeOut();

};

#endif // OBJECT_H
