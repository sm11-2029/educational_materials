#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QMessageBox>

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


void MainWindow::on_CreateMatrix_clicked()
{
    QString str;
    size = ui->lineEditMatrixSize->text().toInt();
    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(size);
    matrix = new int*[size];
    for (int i = 0; i<size; i++){
        matrix[i] = new int[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j] = 0;
            QTableWidgetItem *item = new QTableWidgetItem(str.setNum(matrix[i][j]));
            ui->tableWidget->setItem(i,j,item);
        }
    }
}

void MainWindow::refresh_table(){
    QString str;
    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            QTableWidgetItem *item = new QTableWidgetItem(str.setNum(matrix[i][j]));
            ui->tableWidget->setItem(i,j,item);
        }
    }
}

void MainWindow::on_InputMatrix_clicked()
{
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j] = ui->tableWidget->item(i,j)->text().toInt();
        }
    }
}



void MainWindow::on_SwitchEls_clicked()
{
    int max = matrix[0][1];
    int min = matrix[1][0];
    int copy;
    int i_min = 1;
    int i_max = 0;
    int j_min = 0;
    int j_max = 1;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if ((j > i) and (matrix[i][j] > max)){
                max = matrix[i][j];
                i_max = i;
                j_max = j;
            }
            if ((j < i) and (matrix[i][j] < min)){
                min = matrix[i][j];
                i_min = i;
                j_min = j;
            }
        }
    }
    copy = matrix[i_min][j_min];
    matrix[i_min][j_min] = matrix[i_max][j_max];
    matrix[i_max][j_max] = copy;
    refresh_table();
    QString str1, str2;
    QString text = QString("%1 <--> %2").arg(str1.setNum(matrix[i_min][j_min])).arg(str1.setNum(matrix[i_max][j_max]));
    ui->textEdit->setText(text);
}


void MainWindow::on_GetMaxCol_clicked()
{
    QString text, num, str;
    int min = 999;
    int max = matrix[0][0];
    int j_max = 0;
    arrayB.clear();
    for (int i = 0; i < size; i++){
        if (matrix[i][i] > max){
            max = matrix[i][i];
            j_max = i;
        }
    }
    for (int i = 0; i < size; i++){
        arrayB.push_back(matrix[i][j_max]);
        text = ui->lineEditB->text();
        text = text + ' ' + num.setNum(arrayB[i]);
        ui->lineEditB->setText(text);
        if ((arrayB[i] > 0) and (arrayB[i] < min)){
            min = arrayB[i];
        }
        if (min == 999){
            QMessageBox::warning(this, "ERROR", "Not Found Any Positive");
        }
        else{
            ui->lineEditMinB->setText(str.setNum(min));
        }
    }

}


void MainWindow::on_GetMinEls_clicked()
{
    QString text, num, str;
    int multiple = 1;
    int count = 0;
    arrayC.clear();
    ui->label_multiple->setText("");
    ui->label_arrayC->setText("");
    for (int i = 0; i < size; i++){
        int min = matrix[i][0];
        for (int j = 0; j < size; j++){
            if (min > matrix[i][j]){
                min = matrix[i][j];
            }
        }
        arrayC.push_back(min);
        text = ui->label_arrayC->text();
        text += ' ' + num.setNum(arrayC[i]);
        ui->label_arrayC->setText(text);
        if (arrayC[i] >= 0){
            continue;
        }
        else{
            if (arrayC[i] % 2 == 0){
                count += 1;
                multiple *= arrayC[i];
            }
        }
    }
    if (count > 0){
         ui->label_multiple->setText(str.setNum(multiple));
    }
    else{
        ui->label_multiple->setText("Not Found Any Negative Even Numbers");
    }
    refresh_table();


}

