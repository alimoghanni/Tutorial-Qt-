#include <QCoreApplication>
#include <QDebug>

class Person
{
public:
    Person(const QString &name, int age) :
        m_name(name),
        m_age(age)
    {

    }
    friend inline QDebug operator<<(QDebug qd, const Person &p);
private:
    QString m_name;
    int m_age;
};


inline QDebug operator<<(QDebug qd, const Person &p)
{
    return qd << p.m_name << " " << p.m_age;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person tom("Tom", 29);
    qDebug() << tom;

    return a.exec();
}
