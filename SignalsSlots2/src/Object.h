#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

class Object : public QObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent = nullptr);

    void emitAllSignals();

signals:
    void signal();
    void signal(int);
    void signal(char);
    void signal(QString);

public slots:
    void onSignal();
    void onSignal(int e);
    void onSignal(char c);
    void onSignal(const QString &s);

};

#endif // OBJECT_H
