#include <QCoreApplication>

#include "Calc.hh"

int main(int ac, char **av)
{
    QCoreApplication a(ac, av);

    Calc c(&a);

    return a.exec();
}