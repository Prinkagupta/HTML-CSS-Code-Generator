#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"menu.h"
#include<qmessagebox.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_goButton_clicked()
{
    menu m;
    m.setModal(true);

    m.exec();

}

void MainWindow::on_aboutButton_clicked()
{
    QMessageBox::information(this,tr("ABOUT"),tr("This project helps the user to generate a HTML-CSS code according to the specifications provided by the user."));
}
