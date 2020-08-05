#include "basic_calculator.h"
#include "ui_basic_calculator.h"

BasicCalculator::BasicCalculator(QWidget *parent)
    : BaseCalculator(parent), ui(new Ui::BasicCalculator)
{
    ui->setupUi(this);
    connectButtons(ui->gridLayout_2->parent()->findChildren<QPushButton*>());
}

BasicCalculator::~BasicCalculator()
{
    delete ui;
}
