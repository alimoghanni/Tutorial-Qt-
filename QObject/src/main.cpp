#include <QCoreApplication>
#include <QDebug>

class Person : public QObject
{
public:
    Person(QObject *person = nullptr)
        : QObject(person)
    {

    }
    const QString &name() const;
    void setName(const QString &newName);

    int age() const;
    void setAge(int newAge);

    double height() const;
    void setHeight(double newHeight);

    ~Person()
    {
        qDebug() << m_name << " was gone!";
    }

    void print() const
    {
        qDebug() << m_name << " " << m_age << " / " << m_height;
    }

private:
    QString m_name;
    int m_age;
    double m_height;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person *tom = new Person;
    Person *jim = new Person(tom);
    Person *kim = new Person(tom);

    tom->setName("Tom");
    tom->setAge(40);
    tom->setHeight(175.5);

    jim->setName("Jim");
    jim->setAge(25);
    jim->setHeight(180);

    kim->setName("Kim");
    kim->setAge(55);
    kim->setHeight(140.8);

    tom->print();
    jim->print();
    kim->print();

    delete tom;




    return a.exec();
}


const QString &Person::name() const
{
    return m_name;
}

void Person::setName(const QString &newName)
{
    m_name = newName;
}

int Person::age() const
{
    return m_age;
}

void Person::setAge(int newAge)
{
    m_age = newAge;
}

double Person::height() const
{
    return m_height;
}

void Person::setHeight(double newHeight)
{
    m_height = newHeight;
}
