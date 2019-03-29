#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
  void on_teleOp_clicked();

  void on_Autonomous_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
