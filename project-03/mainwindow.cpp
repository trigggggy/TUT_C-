#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ismale=false;
    ui->Weight_Spin->setSuffix(" kg");
    ui->Height_Spin->setSuffix(" cm");
    ui->Height_Spin->setRange(0, 300);
    ui->Height_Slider->setRange(0, 300);
    ui->Weight_Spin->setRange(0, 300);
    ui->Weight_Slider->setRange(0, 300);
    createActions();
    createMenus();

}

void MainWindow::createActions(){

    actReset = new QAction(tr("Reset"), this);
        connect(actReset, SIGNAL(triggered()), this, SLOT(click_reset()));
    actClose = new QAction(tr("Close"), this);
        connect(actClose, SIGNAL(triggered()), this, SLOT(click_close()));
        actionF = new QAction(tr("Female"), this);
            actionF->setCheckable(true);
            connect(actionF, SIGNAL(triggered()), this, SLOT(female()));

            actionM = new QAction(tr("Male"), this);
        actionM->setCheckable(true);
        connect(actionM, SIGNAL(triggered()), this, SLOT(male()));



    group = new QActionGroup(this);
    group->addAction(actionF);
    group->addAction(actionM);
    actionF->setChecked(true);
}

void MainWindow::createMenus()
{

    Act = menuBar()->addMenu(tr("Action"));
    Act->addAction(actReset);
    Act->addAction(actClose);
    Gen = menuBar()->addMenu(tr("Gender"));
        Gen->addAction(actionF);
    Gen->addAction(actionM);


}


void MainWindow::female(){

    ui->GenderLabel->setText(tr("Female"));
    ismale=false;
    calc();

}

void MainWindow::male(){

    ui->GenderLabel->setText("Male");
    ismale=true;
    calc();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::click_reset(){
ui->Weight_Spin->setValue(0);
ui->Height_Spin->setValue(0);
ui->Weight_Slider->setValue(0);
ui->Height_Slider->setValue(0);
ismale=false;
ui->GenderLabel->setText("Female");
calc();
}
void MainWindow::click_close(){
    close();
}

void MainWindow::on_Weight_Slider_valueChanged(int value)
{
    ui->Weight_Spin->setValue(value);
}

void MainWindow::on_Height_Slider_valueChanged(int value)
{
    ui->Height_Spin->setValue(value);
}

void MainWindow::on_Weight_Spin_valueChanged(int arg1)
{
    m = ui->Weight_Spin->value();
    ui->Weight_Slider->setValue(arg1);
    calc();
}

void MainWindow::on_Height_Spin_valueChanged(int arg1)
{
    h=ui->Height_Spin->value();
    ui->Height_Slider->setValue(arg1);
    calc();
}
void MainWindow::calc(){
    //ui->BMI_Label->setText(QString::number(m, 'i', 1));
    if(m==0 || h==0){
        ui->BMI_Label->setText("-");
        ui->Itpr_Label->setText("-");
    }else{
        float mh=(float)h/100;
        float i = (float)m/(mh*mh);
        ui->BMI_Label->setText(QString::number(i, 'f', 3));
        if(ismale){
            if(i<=20.7){
                //underweight
                ui->Itpr_Label->setText("Underweight");
            }else if(20.7<i && i<=26.4){
                //normal
                ui->Itpr_Label->setText("Normal");
            }else if(26.4<i && i<=27.8){
                //slight overweight
                ui->Itpr_Label->setText("Slight overweight");
            }else if(27.8<i && i<=31.1){
                //overweight
                ui->Itpr_Label->setText("Overweight");
            }else if(i>31.1){
                //much overweight
                ui->Itpr_Label->setText("Much overweight");
            }
        }else{
            if(i<=19.1){
                //underweight
                ui->Itpr_Label->setText("Underweight");
            }else if(19.1<i && i<=25.8){
                //normal
                ui->Itpr_Label->setText("Normal");
            }else if(25.8<i && i<=27.3){
                //overweight
                ui->Itpr_Label->setText("Slight overweight");
            }else if(27.3<i && i<=32.2){
                //overweight
                ui->Itpr_Label->setText("Overweight");
            }else if(i>32.2){
                //much overweight
                ui->Itpr_Label->setText("Much overweight");
            }
        }

    }
}


