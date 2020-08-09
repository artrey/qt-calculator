#ifndef PROGRAMMER_CALCULATOR_H
#define PROGRAMMER_CALCULATOR_H
#include "base_calculator.h"

namespace Ui {
class ProgrammerCalculator;
}

class ProgrammerCalculator : public BaseCalculator
{
    Q_OBJECT

public:
    explicit ProgrammerCalculator(QWidget *parent = nullptr);
    ~ProgrammerCalculator();



private:
    Ui::ProgrammerCalculator *ui;
};

#endif // PROGRAMMER_CALCULATOR_H
