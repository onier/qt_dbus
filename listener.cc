#include <QtCore>
#include <QtDBus>

#include "Listen.hh"

int main(int ac, char **av)
{
    QCoreApplication a(ac, av);

    if(!QDBusConnection::sessionBus().isConnected()) {
        qCritical() << "Cannot connect to the D-Bus session bus!";
        return EXIT_FAILURE;
    }

    Listen l;

    QDBusConnection::sessionBus().connect(QString(), QString(), "my.test.ICalculator", "newProduct",
                                          &l, SLOT(reportNewProduct(double)));
    QDBusConnection::sessionBus().connect(QString(), QString(), "my.test.ICalculator", "newQuotient",
                                          &l, SLOT(reportNewQuotient(double)));

    return a.exec();
}