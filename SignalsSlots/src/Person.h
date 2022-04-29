#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);

    const QString &name() const;
    void setName(const QString &newName);

    void heSpeaks(const QString &words);

private:
    QString m_name;

signals:
    void speak(QString);

public slots:
    void listen(const QString &words);
};

#endif // PERSON_H
