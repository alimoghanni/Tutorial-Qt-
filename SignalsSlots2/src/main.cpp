#include <QCoreApplication>
#include "Object.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Object obj;
    obj.emitAllSignals();

    return a.exec();
}
