#ifndef UTILS_H
#define UTILS_H
#include "QTableWidgetItem"
#include "Qt"
#include "qmessagebox.h"
#include "QDesktopWidget"
#include "QFileInfo"
#include "QApplication"
#include "stdio.h"
#include "QTextStream"
#include "DEFINES.h"
#include <unistd.h>
#include "qprocess.h"
#include "qtextedit.h"
#include "stdio.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include "qtextedit.h"
#include "QLineEdit"
#include "debug.h"

#define TEST {fprintf(stderr, "\nprobando TEST");}
class utils
{
public:
    utils();

    static QTableWidgetItem* toItem(float n);
    static QTableWidgetItem* toItem(QString a);
    static QTableWidgetItem* toItem(int n);

    static QString getMacAdress(QString iface);

    static QString getAircrackVersionM4();

    static QString showAircrackVersionM4();

    static QString listToString(QList<QString> list);

    static QString actualTime();

    static bool validMAC (QString B){return B.count(':')==5 && B.size()==17;}

    static QStringList getListInterfaces();

    static QString getInterfaceMonitorMode();

    static bool checkRoot(){return getuid() == 0;}

    static bool programInstalled(QString program);

    static QString findIpDest(QString decryptedPacket);

    //destIP to do advanced attacks
    static QString forgeARP(QString xorFile, QString BSSID, QString MAC, QString IPSource,
                            QString IPDest);

    static void openPage(QString URL){QProcess::execute("xdg-open " + URL);}

    //drop FIRST number that we found in line
    //WE CAN IMPROVE, WE ADD AN ARGUMENT THAT INDICATES WICH NUMBER (IN ORDER) WANT TO DROP
    static int dropNumber(QString line);

    static void killProcess(int PID){system(("kill " + QString::number(PID)).toLatin1().data());}

    static void customClearLog(QTextEdit *t, QString header);

    enum BACKGROUND {RED, YELLOW, GREEN};
    static void setBackgroundColor(QLineEdit *L, BACKGROUND color);

    enum POSICION {CENTRO, ARRIBA};
    static void mostrarWarning(QString err, QString TITLE = "WARNING!") {QMessageBox::warning(NULL, TITLE, err);}
    static void mostrarError(QString err, QString TITLE = "ERROR!")   {QMessageBox::critical(NULL, TITLE, err);}
    static void mostrarMensaje(QString err, QString TITLE = "Message") {QMessageBox::information(NULL, TITLE, err);}

    static void centrarPantalla(QWidget *w, POSICION p);

    //Funcion que devuelve el nombre relativo del fichero (que debe estar en nombre absoluto)
    static QString nombreRelativo(QString absoluteName) {
        return QFileInfo(absoluteName).absoluteFilePath().remove(QFileInfo(absoluteName).absolutePath()+"/");
    }

    static QString htmlRojo(QString texto);
    static QString htmlVerde(QString texto);
    static QString htmlNegrita(QString texto);
};

#endif // UTILS_H
