#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    procWidget = new ProcessWidget();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ShowProcWidget() {
    setCentralWidget(procWidget);
}
