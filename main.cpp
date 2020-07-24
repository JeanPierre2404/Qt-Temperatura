#include "temperatura.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Temperatura w;
    w.show();
    return a.exec();
}
