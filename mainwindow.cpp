#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hidePuncPushButton_clicked()
{
    _originalTxt = ui->txtBody->toPlainText();
    _originalTxtPtr = &_originalTxt;

    _noPuncTxt = _originalTxt;
    _noPuncTxtPtr = & _noPuncTxt;

    _removePunc(_noPuncTxtPtr);
    ui->txtBody->setPlainText(_noPuncTxt);
}
void MainWindow::_removePunc(QString* txtPtr)
{

    for (int index = 0 ; index < txtPtr->size() ; index++)
    {

        if (txtPtr->at(index) == ',' || txtPtr->at(index) == '.' ||
                txtPtr->at(index) == ';'  )
        {

            //convert upper case letter to loew case letter
            //after the '.'
            if (txtPtr->at(index) == '.')
            {
                txtPtr->replace((index+2), 1, txtPtr->at(index+2).toLower());
            }
            //replace other punc with a star
            txtPtr->replace(index,1,'*');
        }
    }
}

void MainWindow::on_submitPushButton_clicked()
{
    _answerTxt = ui->txtBody->toPlainText();
    _answerTxtPtr = &_answerTxt;
    _compareInput(_answerTxtPtr, _originalTxtPtr);

}
void MainWindow::_compareInput(QString* answerTxt, QString* originalTxt)
{
    int size=0;
    if     (answerTxt->size() < originalTxt->size()){size =answerTxt->size(); }
    else {size =originalTxt->size();}
    for (int index = 0 ; index < size ; index++)
    {

        if (originalTxt->at(index) != answerTxt->at(index))
        {
            int steps = 10;
            int wrdStrt = 0;
            QString missMatch ="";// originalTxt->at(index);


            for (wrdStrt = 0; wrdStrt > -steps ; wrdStrt--)
            {
                if (originalTxt->at(index + wrdStrt) == ' ' )
                {break;}
            }

            qDebug()<< "wrdStrt " << wrdStrt;

            for (int i = wrdStrt; i < steps ; i++)
            {
                missMatch += originalTxt->at(index + i);
            }

            QMessageBox* msg = new QMessageBox();
            msg->setIcon(QMessageBox::Warning);
            msg->setWindowTitle("Punc Error");
            QString msgbody;
            msgbody  = "The punc does not match original text \n"
                       " The punc is close to  ( " + missMatch +" )" ;

            msg->setText(msgbody);
            msg->show();

        }

    }






}
