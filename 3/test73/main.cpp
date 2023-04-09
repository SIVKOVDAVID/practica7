#include <QtWidgets>
#include <iostream>
#include <string>
#include <QString>
#include <QObject>
#include <QPushButton>
#include "machine.h"
using namespace std;

void CarX(Machine car) {
    QMessageBox msgX;
    msgX.setStyleSheet("QLabel{min-width:200 px; min-height:75 px; font-size: 30px; text-align: center;}");
    msgX.setText("X: " + QString::fromStdString((to_string(car.X))));
    msgX.exec();
}
void CarP(Machine car) {
    QMessageBox msgP;
    msgP.setStyleSheet("QLabel{min-width:200 px; min-height:75 px; font-size: 30px; text-align: center;}");
    msgP.setText("P: " + QString::fromStdString((to_string(car.P))));
    msgP.exec();
}
void CarV(Machine car) {
    QMessageBox msgV;
    msgV.setStyleSheet("QLabel{min-width:200 px; min-height:75 px; font-size: 30px; text-align: center;}");
    msgV.setText("V: " + QString::fromStdString((to_string(car.V))));
    msgV.exec();
}

int main(int args, char *argv[]) {
    cout << "Test N7.3: OK." << endl;
    Machine car;

    QApplication app(args, argv);
    QMainWindow mainWin;

    QPushButton *newX = new QPushButton(&mainWin);
    newX->setText("X");
    QPushButton *newP = new QPushButton(&mainWin);
    newP->setText("P");
    QPushButton *newV = new QPushButton(&mainWin);
    newV->setText("V");

    newX->setGeometry(5,10,120,30);
    newP->setGeometry(5,50,120,30);
    newV->setGeometry(5,90,120,30);

    QObject::connect(newX, &QPushButton::clicked, [&]() { CarX(car); });
    QObject::connect(newP, &QPushButton::clicked, [&]() { CarP(car); });
    QObject::connect(newV, &QPushButton::clicked, [&]() { CarV(car); });

    mainWin.show();
    return app.exec();
}

