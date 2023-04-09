#include <QtWidgets>
#include <iostream>
#include <string>
#include <QString>
#include <QObject>
#include <QPushButton>
#include "road.h"
using namespace std;


void RoadW(Road road) {
    QMessageBox msgW;
    msgW.setStyleSheet("QLabel{min-width:200 px; min-height:75 px; font-size: 20px; text-align: center;}");
    msgW.setText("Width: " + QString::fromStdString((to_string(road.Width))));
    msgW.exec();
}
void RoadL(Road road) {
    QMessageBox msgL;
    msgL.setStyleSheet("QLabel{min-width:200 px; min-height:75 px; font-size: 20px; text-align: center;}");
    msgL.setText("Length: " + QString::fromStdString((to_string(road.Length))));
    msgL.exec();
}

int main(int args, char *argv[]) {
    cout << "Test N7.2: OK." << endl;
    Road road;

    QApplication app(args, argv);
    QMainWindow mainWin;

    QPushButton *width = new QPushButton(&mainWin);
    width->setText("Width");
    QPushButton *length = new QPushButton(&mainWin);
    length->setText("Length");

    width->setGeometry(5,10,120,30);
    length->setGeometry(5,50,120,30);

    QObject::connect(width, &QPushButton::clicked, [&]() { RoadW(road); });
    QObject::connect(length, &QPushButton::clicked, [&]() { RoadL(road); });

    mainWin.show();
    return app.exec();
}

