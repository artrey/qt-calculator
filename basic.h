#ifndef BASIC_H
#define BASIC_H

#include <QWidget>

namespace Ui {
class Basic;
}

class Basic : public QWidget
{
    Q_OBJECT

public:
    explicit Basic(QWidget *parent = nullptr);
    ~Basic();

signals:
    void calcRequested(QString const& operation);

private:
    void doAction(QString const& action);

private slots:
    void on_btn_clicked();

private:
    Ui::Basic *ui;
};

#endif // BASIC_H
