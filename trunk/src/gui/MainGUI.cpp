#include <QApplication>

#include "GUI.h"

#define VNS

#ifdef VNS
#include "../util/FileParser.h"
#endif //VNS

int main(int argc, char *argv[])
{
#ifdef GUI
    QApplication app(argc, argv);
    GUI *dialog = new GUI;

    dialog->show();
    return app.exec();
#endif //GUI

#ifdef VNS
    char* file = argv[0];
    float rho = QString(argv[1]).toFloat();
    FileParser::parseDetModel(file, NULL);
#endif //VNS
}

