#include <QCoreApplication>
#include <QPointer>
#include <QDebug>

class Person : public QObject
{
public:
    Person(const QString name, QObject *parent = nullptr) :
        QObject(parent)

    {
        m_name = name;
    }

    QString name() const
    {
        return m_name;
    }


private:
    QString m_name;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int *ptr = new int(5);

    qDebug() << *ptr;

    delete ptr;

    QPointer<Person> iptr = new Person("Tom",nullptr);
    Person *pt = new Person("Jerry");

    qDebug() << iptr->name();
    qDebug() << pt->name();

    delete iptr;
    delete pt;

    pt = nullptr;

    qDebug() << (iptr == nullptr);
    qDebug() << (pt == nullptr);


    return a.exec();
}
