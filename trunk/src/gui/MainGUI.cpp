#include <QApplication>

#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GUI *dialog = new GUI;

    dialog->show();
    return app.exec();
}

