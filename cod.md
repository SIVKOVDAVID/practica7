Библиотека Qt. Обработчик событий кнопки

Для каждой программы, состоящей из нескольких файлов, 
создавайте отдельную папку проекта, например project07-1, 
project07-2 и т.д., где "07" - номер практического 
занятия, 1, 2 и т.д. - номер задания.
Каждую программу, состоящую из одного файла, сохранять 
в отдельном файле для каждого упражнения, 
например, prog07-1, prog07-2 и т.д., где "07" - номер практического 
занятия, 1, 2 и т.д. - номер задания.

1. По примеру 9 из лекции создайте простейшее приложение, 
содержащее кнопки, с графическим интерфейсом с применением 
библиотеки Qt.
Исходный код:
#include <QtWidgets>
class MainWindow : public QMainWindow
{
	public:
		MainWindow();
		void onStartClick();
		void onStopClick();
	private:
		QLabel 		*textLabel;
		QPushButton *startButton;
		QPushButton *stopButton;
};

MainWindow::MainWindow()
{
	setFixedSize(900,500);
	setWindowTitle("Test QPushButton");
	textLabel = new QLabel("Test QLabel",this);
	textLabel->setGeometry(50,100,120,30);
	textLabel->setFont(QFont("Courier",12,QFont::Bold));
	QFont buttonFont("Times",18,QFont::Normal);
	
	startButton = new QPushButton("Start",this);
	startButton->setGeometry(50,150,70,50);
	startButton->setFont(buttonFont);
	
	stopButton = new QPushButton("Stop",this);
	stopButton->setGeometry(140,150,70,50);
	stopButton->setFont(buttonFont);
	
	connect(startButton, &QPushButton::clicked,this,&MainWindow::onStartClick);
	
	connect(stopButton, &QPushButton::clicked,this,&MainWindow::onStopClick);
	
}

void MainWindow::onStartClick()
{
	textLabel->setText("Start");
}
void MainWindow::onStopClick()
{
	textLabel->setText("Stop");
}

int main(int argc, char *argv[]) 
{
	QApplication app(argc, argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
}
Скриншот:

Вывод: По примеру 9 из лекции создал простейшее приложение, 
содержащее кнопки, с графическим интерфейсом с применением 
библиотеки Qt.


2. Создайте приложение на основе проекта из задания 1,
подключите библиотеку с классом Дорога. 
Значения свойств класса выводятся при нажатии на кнопку.
Скриншот:




Исходный код:
//main.cpp
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


//test18.pro
CONFIG+= console
QT+=widgets
SOURCES += \
    main.cpp \
    road.cpp

HEADERS += \
    road.h


// road.h
#ifndef ROAD_H
#define ROAD_H

class Road 
{
	public:
	Road();
	 double Length;
	 int    Width;
	 
};

#endif
//road.cpp
#include "road.h"
Road::Road() : Length(777), Width(7) {}





3. Создайте приложение на основе проекта из задания 1,
подключите библиотеку с классом Автомобиль. 
Создайте 3 кнопки для вывода каждого из трех свойств 
класса Автомобиль x, v, p.
Скриншот:





Исходный код:
//main.cpp
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

//machine.cpp
#include "machine.h"
Machine::Machine() : X(777), P(77), V(7000) {}



//machine.h
#ifndef MACHINE_H
#define MACHINE_H

class Machine {
public:
    int X;
    int P;
    int V;
    Machine();
};

#endif



4. Подключите к программе из задания 1 библиотеку TBook. 
Создайте 3 кнопки с надписями: Show Author, Show Name, 
Show Count, при нажатии на кнопку выводится соответствующее 
значение свойства класса TBook, каждое - в отдельный компонент QLabel: 
authorLabel, nameLabel, countLabel.
Скриншот:



Исходный код:
//main.cpp
#include <QtWidgets>
#include <iostream>
#include <string>
#include <QString>
#include <QObject>
#include <QPushButton>
#include "tbook.h"
using namespace std;

void Author(QLabel *label) {
    label->setVisible(!(label->isVisible()));
}
void Name(QLabel *label) {
    label->setVisible(!(label->isVisible()));
}
void Count(QLabel *label) {
    label->setVisible(!(label->isVisible()));
}

int main(int args, char *argv[]) {
    cout << "Test v7.4: OK." << endl;
    TBook book;

    QApplication app(args, argv);
    QMainWindow mainWin;

    QPushButton *SAuthor = new QPushButton(&mainWin);
    SAuthor->setText("Author");
    QPushButton *SName = new QPushButton(&mainWin);
    SName->setText("Name");
    QPushButton *SCount = new QPushButton(&mainWin);
    SCount->setText("Count");

    SAuthor->setGeometry(5,10,120,30);
    SName->setGeometry(5,50,120,30);
    SCount->setGeometry(5,90,120,30);


    QLabel *newAuthorLabel = new QLabel(&mainWin);
    newAuthorLabel->setText(QString::fromStdString(book.author));
    newAuthorLabel->setVisible(false);
    QLabel *newNameLabel = new QLabel(&mainWin);
    newNameLabel->setText(QString::fromStdString(book.name));
    newNameLabel->setVisible(false);
    QLabel *newCountLabel = new QLabel(&mainWin);
    newCountLabel->setNum(book.count);
    newCountLabel->setVisible(false);

    newAuthorLabel->setGeometry(150,10,100,30);
    newNameLabel->setGeometry(150,50,100,30);
    newCountLabel->setGeometry(150,90,100,30);


    QObject::connect(SAuthor, &QPushButton::clicked, [=]() { Author(newAuthorLabel); });
    QObject::connect(SName, &QPushButton::clicked, [=]() { Name(newNameLabel); });
    QObject::connect(SCount, &QPushButton::clicked, [=]() { Count(newCountLabel); });

    mainWin.show();
    return app.exec();
}
//tbook.cpp
#include "tbook.h"
TBook::TBook() : author("Joanne Rowling"), name("Harry Potter"), count(100) {}
//tbook.h
#ifndef TBOOK_H
#define TBOOK_H
#include<QString>
using namespace std;
class TBook {
public:
    string author;
    string name;
    int count;
    TBook();
};
#endif
//test74.pro
CONFIG+=console
QT+=widgets
SOURCES += \
    main.cpp \
    tbook.cpp

HEADERS += \
    tbook.h

# practica7
