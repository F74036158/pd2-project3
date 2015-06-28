#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);
    void showcandy();
    void noclear();
    int check();
    bool choose;
    void clearcandy();
    QLabel *b[11][11];
    void delay();
    void deletecandy();
    bool canmove;
    bool start;
    int sco;
    int step;
    void gameover();
    ~MainWindow();

private slots:
    void on_restart_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
