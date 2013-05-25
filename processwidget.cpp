#include "processwidget.h"
#include "ui_processwidget.h"

ProcessWidget::ProcessWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessWidget)
{
    ui->setupUi(this);
}

ProcessWidget::~ProcessWidget()
{
    delete ui;
}
