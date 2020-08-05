#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "base_calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void makeAction(QString const& action);

    void on_actionExit_triggered();
    void on_actionBasic_triggered();
    void on_actionAdvanced_triggered();

private:
    void updateState();
    void updateCalculator(BaseCalculator* calc);

private:
    Ui::MainWindow *ui;
    double m_result;
    QScopedPointer<BaseCalculator, QScopedPointerDeleteLater> m_calc;
};
#endif // MAINWINDOW_H
