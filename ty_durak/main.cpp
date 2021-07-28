#include "ty_durak.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ty_durak w;
    w.show();

    return a.exec();
}
