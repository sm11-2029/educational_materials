#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

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
    void on_CreateMatrix_clicked();

    void on_InputMatrix_clicked();

    void on_SwitchEls_clicked();

    void refresh_table();

    void on_GetMaxCol_clicked();

    void on_GetMinEls_clicked();

private:
    Ui::MainWindow *ui;
    int **matrix;
    int size;
    std::vector <int> arrayB;
    std::vector <int> arrayC;
};
#endif // MAINWINDOW_H
