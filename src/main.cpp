#include "bitcointests.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    setbuf(stderr, 0);
    setbuf(stdout, NULL);

    QApplication a(argc, argv);
    BitcoinTests w;
    w.init("v1.0.1");
    w.show();

    return a.exec();
}
