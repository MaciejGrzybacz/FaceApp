#include "FaceApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FaceApp w;
    w.show();
    //w.start_video();
    return a.exec();
}
