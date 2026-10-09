#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector"
#include "QString"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class USER{

    QString name;
    QString surname;

public:

    void set_user (QString new_name, QString new_surname){
        name = new_name;
        surname = new_surname;
    }

    void getName(QString &string){
        string = name;
    }
    void getSurname(QString &string){
        string = surname;
    }


};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_DeleteUser_clicked();

    void on_AddUser_clicked();

    void on_NameSort_clicked();

    void on_SurnameSort_clicked();

    void refresh();

private:
    Ui::MainWindow *ui;
    std::vector<USER> list;


};


#endif // MAINWINDOW_H
