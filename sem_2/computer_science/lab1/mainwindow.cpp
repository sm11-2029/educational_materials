#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::run_oper(double *c)
{
    bool ok;
    QString st_a = ui->label_operand->text();
    QString st_b = ui->lineEdit->text();
    QString st_sign = ui->label_sign->text();
    char sg = 0;
        if (!st_sign.isEmpty())
            sg = st_sign.at(0).toLatin1();
    double a = st_a.toDouble(&ok);
    double b = st_b.toDouble(&ok);
    switch (sg)
    {
        case '+':
            *c = a + b;
            break;

        case '-':
            *c = a - b;
            break;

        case '*':
            *c = a * b;
            break;

        case '/':
            if (b==0)
            {
                QMessageBox::information(this, "ERROR", "You can't divide by 0");
                return -1;
            }
            else
                *c = a / b;
            break;
    default:
                *c = b;
                break;
    }
   return 0;
}
void MainWindow::addNum(QChar c){
    QString st = ui->lineEdit->text();
    ui->lineEdit->setText(st + c);
}
void MainWindow::on_pushButton1_clicked()
{
    addNum('1');
}


void MainWindow::on_pushButton2_clicked()
{
    addNum('2');
}


void MainWindow::on_pushButton3_clicked()
{

   addNum('3');
}


void MainWindow::on_pushButton4_clicked()
{

   addNum('4');
}


void MainWindow::on_pushButton5_clicked()
{

    addNum('5');
}


void MainWindow::on_pushButton6_clicked()
{
    addNum('6');
}


void MainWindow::on_pushButton7_clicked()
{
    addNum('7');
}


void MainWindow::on_pushButton8_clicked()
{
   addNum('8');
}


void MainWindow::on_pushButton9_clicked()
{
   addNum('9');
}


void MainWindow::on_pushButton0_clicked()
{
    addNum('0');
}

void MainWindow::on_pushButton_dot_clicked()
{
    QString st = ui->lineEdit->text();
    if (st.indexOf('.') == -1)
    {
        ui->lineEdit->setText(st+'.');
    }
    else
        QMessageBox::information(this,"ERROR","You have already had dot");
}
void MainWindow::on_pushButton_del_clicked()
{
    QString st = ui->lineEdit->text();
    int sz = st.length();
    st = st.left(sz-1);
    ui->lineEdit->setText(st);
}


void MainWindow::on_pushButton_plus_clicked()
{
   double c;
   int er = run_oper(&c);
   if (er == 0)
   {
       ui->label_operand->setNum(c);
       ui->label_sign->setText("+");
       ui->lineEdit->setText("");
   }
   ui->lineEdit->setFrame(true);
}


void MainWindow::on_pushButton_minus_clicked()
{
    double c;
    int er = run_oper(&c);
    if (er == 0)
    {
        ui->label_operand->setNum(c);
        ui->label_sign->setText("-");
        ui->lineEdit->setText("");
    }
    ui->lineEdit->setFrame(true);
}


void MainWindow::on_pushButton_division_clicked()
{
    double c;
    int er = run_oper(&c);
    if (er == 0)
    {
        ui->label_operand->setNum(c);
        ui->label_sign->setText("/");
        ui->lineEdit->setText("");
    }
    ui->lineEdit->setFrame(true);
}


void MainWindow::on_pushButton_mult_clicked()
{
    double c;
    int er = run_oper(&c);
    if (er == 0)
    {
        ui->label_operand->setNum(c);
        ui->label_sign->setText("*");
        ui->lineEdit->setText("");
    }
    ui->lineEdit->setFrame(true);
}


void MainWindow::on_pushButton_exec_2_clicked()
{
    QString st;
    double c;
    run_oper(&c);
    ui->lineEdit->setText(st.setNum(c));
    ui->label_operand->setText(st.setNum(c));
    ui->label_sign->setText("");
}

