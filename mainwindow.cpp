#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "basic.h"

#include <cmath>

#include <QDebug>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_result{0}
{
    ui->setupUi(this);
    ui->userInput->setValidator(new QDoubleValidator);
    ui->labelResult->setText(QString::number(m_result));
    auto basic = new Basic(this);
    ui->centralwidget->layout()->addWidget(basic);
    QObject::connect(basic, &Basic::calcRequested, this, &MainWindow::makeAction);

    qDebug() << "MainWindow constructor";
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug() << "MainWindow destructor";
}

void MainWindow::makeAction(const QString &action)
{
    if (action == "+")
    {
        m_result += ui->userInput->text().toDouble();
    }
    updateState();
}

void MainWindow::updateState()
{
    ui->labelResult->setText(QString::number(m_result));
    ui->userInput->clear();
    ui->userInput->setFocus();
}

//void MainWindow::on_btnPlus_clicked()
//{
//}

//void MainWindow::on_btnMinus_clicked()
//{
//    m_result -= ui->userInput->text().toDouble();
//    updateState();
//}

//void MainWindow::on_btnMult_clicked()
//{
//    m_result *= ui->userInput->text().toDouble();
//    updateState();
//}

//void MainWindow::on_btnDiv_clicked()
//{
//    if (std::abs(ui->userInput->text().toDouble()) < 10e-6)
//    {
//        ui->labelResult->setText("Error: dividing by zero");
//        return;
//    }
//    m_result /= ui->userInput->text().toDouble();
//    updateState();
//}

//void MainWindow::on_btnSqr_clicked()
//{
//    m_result *= m_result;
//    updateState();
//}

//void MainWindow::on_btnSqrt_clicked()
//{
//    if (m_result < 0)
//    {
//        ui->labelResult->setText("Error: current value is negative");
//        return;
//    }
//    m_result = std::sqrt(m_result);
//    updateState();
//}

//void MainWindow::on_btnClear_clicked()
//{
//    m_result = 0;
//    updateState();
//}

//void MainWindow::on_btnCalc_clicked()
//{

//}
