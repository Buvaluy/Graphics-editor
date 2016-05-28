#include "dialogsize.h"
#include "ui_dialogsize.h"

DialogSize::DialogSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSize)
{
    ui->setupUi(this);
    this->setWindowTitle("Size");
}

DialogSize::~DialogSize()
{
    delete ui;
}

qreal DialogSize::getW(){
    return ui->lineEdit->text().toInt();
}

qreal DialogSize::getH()
{
    return ui->lineEdit_2->text().toInt();
}
