#include "advanced_calculator.h"
#include "ui_advanced_calculator.h"

AdvancedCalculator::AdvancedCalculator(QWidget *parent)
    : BaseCalculator(parent), ui(new Ui::AdvancedCalculator)
{
    ui->setupUi(this);
    connectButtons(ui->gridLayout_2->parent()->findChildren<QPushButton*>());
}

AdvancedCalculator::~AdvancedCalculator()
{
    delete ui;
}
