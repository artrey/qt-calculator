#include "programmer_calculator.h"
#include "ui_programmer_calculator.h"

ProgrammerCalculator::ProgrammerCalculator(QWidget *parent) :
    BaseCalculator(parent),
    ui(new Ui::ProgrammerCalculator)
{
    ui->setupUi(this);
    connectButtons(ui->gridLayout_2->parent()->findChildren<QPushButton*>());
}

ProgrammerCalculator::~ProgrammerCalculator()
{
    delete ui;
}
