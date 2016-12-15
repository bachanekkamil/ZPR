#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <database.h>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <QDebug>

// Change to any path you wish
static const QString path = "people.db";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
	DbManager db(path);

    if (db.isOpen())
    {
        db.createTable();   // Creates a table if it doens't exist. Otherwise, it will use existing table.
        db.addPerson("A");
        db.addPerson("B");
        db.addPerson("C");
        db.printAllPersons();
        db.removePerson("C");
        db.printAllPersons();
        db.removeAllPersons();
        qDebug() << "End";
    }
    else
    {
        qDebug() << "Database is not open!";
    }

	
	using namespace boost::gregorian;
	date d(2000, Jan, 20);
	
	
}

MainWindow::~MainWindow()
{
    delete ui;
}
