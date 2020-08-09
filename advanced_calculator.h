#ifndef ADVANCED_CALCULATOR_H
#define ADVANCED_CALCULATOR_H

#include <base_calculator.h>

namespace Ui {
class AdvancedCalculator;
}

class AdvancedCalculator : public BaseCalculator
{
    Q_OBJECT

public:
    explicit AdvancedCalculator(QWidget *parent = nullptr);
    ~AdvancedCalculator();


private:
    Ui::AdvancedCalculator *ui;
};

#endif // ADVANCED_CALCULATOR_H
