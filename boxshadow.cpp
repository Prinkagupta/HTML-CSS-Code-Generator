#include "boxshadow.h"
#include "ui_boxshadow.h"

boxShadow::boxShadow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::boxShadow)
{
    ui->setupUi(this);
}

boxShadow::~boxShadow()
{
    delete ui;
}

void boxShadow::on_backButton_clicked()
{
    this->close();
}
