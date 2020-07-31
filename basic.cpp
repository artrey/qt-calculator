#include "basic.h"
#include "mainwindow.h"
#include "ui_basic.h"

Basic::Basic(QWidget *parent) :
    QWidget(parent), ui(new Ui::Basic)
{
    ui->setupUi(this);

    for (QPushButton* btn : {ui->btnPlus, ui->btnMinus, ui->btnMult,
         ui->btnDiv, ui->btnSqr, ui->btnSqrt, ui->btnClear, ui->btnCalc})
    {
        QObject::connect(btn, &QPushButton::clicked, this, &Basic::on_btn_clicked);
    }
}

Basic::~Basic()
{
    delete ui;
}

void Basic::doAction(const QString &action)
{
    emit calcRequested(action);
}

void Basic::on_btn_clicked()
{
    doAction(static_cast<QPushButton*>(sender())->text());
}
