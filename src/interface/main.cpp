#include <QApplication>
#include <QMessageBox>
#include "FenetrePrincipale.hpp"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    FenetrePrincipale mw;
    mw.show();
    return app.exec();
}
