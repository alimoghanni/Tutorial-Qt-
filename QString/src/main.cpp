#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hello Qt!";

    QString string = "Wellcom to Qt World!";
    qDebug() << string;
    qDebug().noquote() << string << "\n";

    int intNum = 20;
    double dNum = 3.1415;
    char letter = 'A';

    QString comb;
    comb = QString("%1, %2 - %3").arg(intNum).arg(dNum).arg(letter);
    qDebug() << comb;

    std::string stdString = "Do you like C++?";
    QString qString = stdString.c_str();
    qDebug() << qString;

    QString qStr = "Maybe I like!";
    std::string stdStr = qStr.toStdString();
    qDebug() << stdStr.c_str();

    QString name = "Hercule Poirot";
    qDebug() << name;
    qDebug() << "contains Poirot?" << name.contains("Poirot");
    qDebug() << "contains Agatha?" << name.contains("Agatha");
    qDebug() << "start with Hercule?" << name.startsWith("Hercule");
    qDebug() << "end with word Poirot?" << name.endsWith("Poirot");
    qDebug() << "end with char t?" << name.endsWith('t');
    qDebug() << "index of P?" << name.indexOf('P');
    qDebug() << "Char at position 0 ?" << name.at(0);
    name.append(" is a Belgian detective.");
    qDebug() << name;

    name.insert(20, "fictional ");
    qDebug() << name;

    qDebug() << "Number of char o ?" << name.count('o');

    qDebug() << "Length : " << name.length();

    qDebug() << "From position 0 to 14: " << name.mid(0,14);

    name.clear();
    qDebug() << "Clear name content!" << name;

    qDebug();

    qDebug() << "convert number to string:" << QString::number(100);

    QString age = "25";
    qDebug() << "convert string to number:" << age.toInt();

    QString weight = "56kg";
    bool flag;
    int weightNum = weight.toInt(&flag);
    if (flag)
        qDebug() << weightNum;
    else
        qDebug() << "Error!";

    return a.exec();
}
