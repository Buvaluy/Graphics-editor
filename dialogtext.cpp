#include "dialogtext.h"
#include "ui_dialogtext.h"

DialogText::DialogText(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogText)
{
    ui->setupUi(this);
    this->setWindowTitle("Text");
}

DialogText::~DialogText()
{
    delete ui;
}

QString DialogText::getText()
{
    return ui->lineEdit->text();
}
