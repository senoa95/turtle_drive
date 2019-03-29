#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

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


void MainWindow::on_teleOp_clicked()
{
//    QMessageBox myBox1;
//    myBox1.setText("Now in Teleop Mode");
//    myBox1.exec();
    QMessageBox::information(this,"TitleHere","Now in TeleOp mode");
}

void MainWindow::on_Autonomous_clicked()
{
//    QMessageBox myBox2;
//    myBox2.setText("Now in Autonomous mode");
//    myBox2.exec();
    QMessageBox::information(this,"Message","Now in Autonomous mode");
}
