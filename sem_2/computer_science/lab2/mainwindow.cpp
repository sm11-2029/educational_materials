#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector"
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


void MainWindow::refresh(){
    QString str1,str2;
    ui->listWidget->clear();
    for (size_t i=0; i<list.size();i++){
        list[i].getName(str1);
        list[i].getSurname(str2);
        QString text = QString("%1 %2").arg(str2).arg(str1);
        ui->listWidget->addItem(text);
    }
}
void MainWindow::on_DeleteUser_clicked()
{
    QString index_string = ui->lineEditDelIndex->text();
    bool ok;
    int index = index_string.toInt(&ok,10);

    if (!list.empty()){
        for (int i = index; i < (int)list.size()-1; i++){
           list[i] = list[i+1];
        }
        list.pop_back();
        refresh();
        ui->lineEditDelIndex->setText("");
    }
    else
        QMessageBox::warning(this, "ERROR", "You haven't users");
}


void MainWindow::on_AddUser_clicked()
{
    QString new_name = ui->lineEditName->text();
    QString new_surname = ui->lineEditSurname->text();
    USER new_user;
    new_user.set_user(new_name, new_surname);
    list.push_back(new_user);
    ui->lineEditName->setText("");
    ui->lineEditSurname->setText("");
    refresh();
}


void MainWindow::on_NameSort_clicked()
{
    QString str1, str2;
    USER copy;
    for (size_t i=0; i<list.size()-1;i++){
        for (size_t k=0; k<list.size()-i-1;k++){
            list[k].getName(str1);
            list[k+1].getName(str2);
            if (str1>str2){
                copy = list[k+1];
                list[k+1] = list[k];
                list[k]=copy;
                //break;
            }
        }
    }
    refresh();
}


void MainWindow::on_SurnameSort_clicked()
{
    QString str1, str2;
    USER copy;
    for (size_t i=0; i<list.size()-1;i++){
        for (size_t k=0; k<list.size()-i-1;k++){
            list[k].getSurname(str1);
            list[k+1].getSurname(str2);
            if (str1>str2){
                copy = list[k+1];
                list[k+1] = list[k];
                list[k]=copy;
                //break;
            }
        }
    }
    refresh();
}



