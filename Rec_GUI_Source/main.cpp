#include "pro_rec.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pro_Rec w;
    w.show();

    return a.exec();
}
