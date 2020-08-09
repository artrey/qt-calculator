#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "basic_calculator.h"
#include "advanced_calculator.h"
#include "programmer_calculator.h"

#include <cmath>

#include <QDebug>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_result{0}
{
    ui->setupUi(this);
    ui->userInput->setValidator(new QDoubleValidator);
    ui->labelResult->setText(QString::number(m_result));

    updateCalculator(new BasicCalculator(this));

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
    else if (action == "-")
    {
        m_result -= ui->userInput->text().toDouble();
    }
    else if (action == "*")
    {
        m_result *= ui->userInput->text().toDouble();
    }
    else if (action == "/")
    {
        m_result /= ui->userInput->text().toDouble();
    }
    else if (action == "sqr")
    {
        m_result *= m_result;
    }
    else if (action == "sqrt")
    {
        m_result = std::sqrt(m_result);
    }
    else if (action == "!")
    {
        for (int i = m_result - 1; i > 1; i--)
        {
            m_result *= i;
        }
    }
    else if (action == "%")
    {
        m_result = static_cast<int>(m_result) % (static_cast<int>((ui->userInput->text().toDouble())));
    }
    else if (action == "log")
    {
        m_result = std::log2(m_result);
    }

    else if (action == "1/x")
    {
        m_result = 1 / m_result;
    }

    else if (action == "^")
    {
        m_result = static_cast<int>(m_result) ^ static_cast<int>(ui->userInput->text().toDouble());
    }

    else if (action == ">>")
    {
        m_result = static_cast<int>(m_result) >> static_cast<int>(ui->userInput->text().toDouble());
    }

    else if (action == "<<")
    {
        m_result = static_cast<int>(m_result) << static_cast<int>(ui->userInput->text().toDouble());
    }

    else if (action == "|")
    {
        m_result = static_cast<int>(m_result) | static_cast<int>(ui->userInput->text().toDouble());
    }

    else if (action == "&&")
    {
        m_result = static_cast<int>(m_result) & static_cast<int>(ui->userInput->text().toDouble());
    }

    else if (action == "~")
    {
        m_result = ~(static_cast<int>(m_result));
    }

    else if (action == "C")
    {
        m_result = 0;
    }

    updateState();
}

void MainWindow::updateState()
{
    ui->labelResult->setText(QString::number(m_result));
    ui->userInput->clear();
    ui->userInput->setFocus();
}

void MainWindow::updateCalculator(BaseCalculator *calc)
{
    QObject::disconnect(m_calc.get(), &BaseCalculator::calcRequested, this, &MainWindow::makeAction);
    m_calc.reset(calc);
    ui->centralwidget->layout()->addWidget(m_calc.get());
    QObject::connect(m_calc.get(), &BaseCalculator::calcRequested, this, &MainWindow::makeAction);
}

void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionBasic_triggered()
{
    updateCalculator(new BasicCalculator(this));
}

void MainWindow::on_actionAdvanced_triggered()
{
    updateCalculator(new AdvancedCalculator(this));
}

void MainWindow::on_actionProgram_triggered()
{
    updateCalculator(new ProgrammerCalculator(this));
}
