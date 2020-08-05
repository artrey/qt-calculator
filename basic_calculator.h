#ifndef BASIC_H
#define BASIC_H

#include "base_calculator.h"

namespace Ui {
class BasicCalculator;
}

class BasicCalculator : public BaseCalculator
{
    Q_OBJECT

public:
    explicit BasicCalculator(QWidget *parent = nullptr);
    ~BasicCalculator();

private:
    Ui::BasicCalculator *ui;
};

#endif // BASIC_H
