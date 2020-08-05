#include "base_calculator.h"
#include <QPushButton>
#include <QDebug>

BaseCalculator::BaseCalculator(QWidget *parent)
    : QWidget(parent)
{
}

void BaseCalculator::onBtnClicked()
{
    QPushButton* btn = dynamic_cast<QPushButton*>(sender());
    if (btn == nullptr)
    {
        qWarning() << "onBtnClicked called on non button";
        return;
    }
    emit calcRequested(btn->text());
}

void BaseCalculator::connectButtons(QList<QPushButton*> const& buttons) const
{
    for (QPushButton* btn : buttons)
    {
        QObject::connect(btn, &QPushButton::clicked, this, &BaseCalculator::onBtnClicked);
    }
}
