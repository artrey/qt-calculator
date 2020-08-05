#ifndef BASECALCULATOR_H
#define BASECALCULATOR_H

#include <QWidget>
#include <QList>
#include <QPushButton>

class BaseCalculator : public QWidget
{
    Q_OBJECT
public:
    explicit BaseCalculator(QWidget *parent = nullptr);

signals:
    void calcRequested(QString const& operation);

public slots:
    void onBtnClicked();

protected:
    void connectButtons(QList<QPushButton*> const& buttons) const;
};

#endif // BASECALCULATOR_H
