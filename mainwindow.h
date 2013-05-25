#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "processwidget.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ProcessWidget* procWidget;

public slots:
    void ShowProcWidget();
};

#endif // MAINWINDOW_H
