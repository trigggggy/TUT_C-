#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QActionGroup;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void male();
    void female();
    void click_reset();
    void click_close();
    void createActions();
    void createMenus();

private slots:
    void on_Weight_Slider_valueChanged(int value);

    void on_Height_Slider_valueChanged(int value);

    void on_Weight_Spin_valueChanged(int arg1);

    void on_Height_Spin_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QActionGroup *group;
    QAction *actionM;
    QAction *actionF;
    QAction *actReset;
    QAction *actClose;
    QMenu *Gen;
    QMenu *Act;
    void calc();
    bool ismale;
    bool renew;
    int m = 0;
    int h = 0;
};

#endif // MAINWINDOW_H
