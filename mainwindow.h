#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_hidePuncPushButton_clicked();

    void on_submitPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString _originalTxt;
    QString* _originalTxtPtr;

    QString _noPuncTxt;
    QString* _noPuncTxtPtr;

    QString _answerTxt;
    QString* _answerTxtPtr;

    void _removePunc(QString *);
    void _compareInput(QString * , QString *);

};

#endif // MAINWINDOW_H
