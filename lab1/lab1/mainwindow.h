#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QDoubleSpinBox* ConstA;
    QDoubleSpinBox* ConstB;

protected:
    void paintEvent(QPaintEvent*);

private slots:
    void redrawOnValueChange(double);



};


#endif // MAINWINDOW_H
