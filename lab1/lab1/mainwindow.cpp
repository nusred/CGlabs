#include <QDoubleSpinBox>
#include "mainwindow.h"
#include <QPainter>
#include <QLabel>
#include <QGraphicsScene>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel* lblFunction(new QLabel("y = ax^(3/2)", this)); //создаем надписи в окне
    lblFunction->move(15, 20);

    QLabel* lblFunction1(new QLabel("0 <= x <= B", this)); //создаем надписи в окне
    lblFunction1->move(15, 35);

    QLabel* lblConstA(new QLabel("a:", this));
    lblConstA->move(15, 60);

    ConstA = new QDoubleSpinBox(this); //создаем объект класса QDoubleSpinBox (изменяем параметр а)
    ConstA->setRange(0.01, 1000);
    ConstA->setSingleStep(0.1);
    ConstA->setValue(1);
    ConstA->move(15, 90);

    QLabel* lblConstB(new QLabel("B:", this));
    lblConstB->move(15, 130);

    ConstB = new QDoubleSpinBox(this); //создаем объект класса QDoubleSpinBox (изменяем параметр B)
    ConstB->setRange(0, 1000);
    ConstB->setSingleStep(0.1);
    ConstB->setValue(150);
    ConstB->move(15, 160);

    connect(ConstA, SIGNAL(valueChanged(double)),
            this, SLOT(redrawOnValueChange(double)));

    connect(ConstB, SIGNAL(valueChanged(double)),
            this, SLOT(redrawOnValueChange(double)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent*)
{
    const double a(ConstA->value()*(std::min((double)width(), (double)height())/450)); //определение константы а
    const double B(ConstB->value());

    QPointF p1(0, 0);

    double x = 15;

    QPainter ptr(this);
    ptr.setPen(Qt::blue);


    QPainter axes(this);
    axes.setPen(Qt::black);         //Просто выбираем цвет для карандашика

    axes.drawLine(20, height()/2, width() - 20, height()/2); //рисуем ось x
    axes.drawLine(width() - 40, height()/2 - 10, width() - 20, height()/2);
    axes.drawLine(width() - 40, height()/2 + 10, width() - 20, height()/2);

    axes.drawLine(width()/2, 20, width()/2, height()-20);    //рисуем ось y
    axes.drawLine(width()/2 - 10, 40, width()/2, 20);
    axes.drawLine(width()/2 + 10, 40, width()/2, 20);

    axes.drawText(width() - 15, height()/2, "X");
    axes.drawText(width()/2 + 10, 20, "Y");

    axes.drawText(width() / 2.0 - 10 , height() / 2.0 + 10, "0");

    for (int i = 1; i <= 9; i++)
    {
        axes.drawLine(width()/2 + i * 15, height()/2 - 2.5, width()/2 + i * 15, height()/2 + 2.5);
        axes.drawText(width()/2 + i * 15 - 2, height()/2 + 15, QString(i+48) );

        axes.drawLine(width()/2 - 2.5, height()/2 - i * 15, width()/2 + 2.5, height()/2 - i * 15);
        axes.drawText(width()/2 - 12, height()/2 -i * 15 + 4, QString(i+48) );
    }

    const QPointF center(width() / 2.0, height() / 2.0);

    for (double t(0.1); t < B / 10; t += 0.1)
    {
        QPointF p2(t * 150, -sqrt(pow(t, 3.0)) * a * 150);
        ptr.drawLine(p1 + center, p2 + center);

        p1 = p2;
    }
}

void MainWindow::redrawOnValueChange(double)
{
    update();
}


