#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->clear_button, SIGNAL(clicked()), this, SLOT(clear_button_clicked()));
    connect(ui->quit_button, SIGNAL(clicked()), this, SLOT(quit_button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quit_button_clicked()
{
    close();
}

void MainWindow::clear_button_clicked()
{
    ui->kmh_spinbox->setValue(0);

    ui->mph_lcd->display(0.0);  // Not really neccessary after the program is finished.
}

void MainWindow::on_kmh_spinbox_valueChanged(double arg1)
{
    double a =arg1;
    ui->mph_lcd->display(a/1.609);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->kmh_spinbox->setValue(value);
}
