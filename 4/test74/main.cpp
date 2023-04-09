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
