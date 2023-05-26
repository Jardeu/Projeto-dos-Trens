#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QSemaphore>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int velocidade_trem1 = ui->speed_trem1->value();
    int velocidade_trem2 = ui->speed_trem2->value();
    int velocidade_trem3 = ui->speed_trem3->value();
    int velocidade_trem4 = ui->speed_trem4->value();
    int velocidade_trem5 = ui->speed_trem5->value();

    regiao0 = new QSemaphore(1);
    regiao1 = new QSemaphore(1);
    regiao2 = new QSemaphore(1);
    regiao3 = new QSemaphore(1);
    regiao4 = new QSemaphore(1);
    regiao5 = new QSemaphore(1);
    regiao6 = new QSemaphore(1);

    regioes_criticas.push_back(regiao0);
    regioes_criticas.push_back(regiao1);
    regioes_criticas.push_back(regiao2);
    regioes_criticas.push_back(regiao3);
    regioes_criticas.push_back(regiao4);
    regioes_criticas.push_back(regiao5);
    regioes_criticas.push_back(regiao6);

    //Cria o trem com seu (ID, posição X, posição Y, velocidade, regioes_criticas)
    trem1 = new Trem(1,220,40,velocidade_trem1,regioes_criticas);
    trem2 = new Trem(2,490,40,velocidade_trem2,regioes_criticas);
    trem3 = new Trem(3,80,160,velocidade_trem3,regioes_criticas);
    trem4 = new Trem(4,350,160,velocidade_trem4,regioes_criticas);
    trem5 = new Trem(5,620,160,velocidade_trem5,regioes_criticas);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    //Inicia os Trens
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete regiao0;
    delete regiao1;
    delete regiao2;
    delete regiao3;
    delete regiao4;
    delete regiao5;
    delete regiao6;
}

void MainWindow::on_speed_trem1_valueChanged(int value)
{
    trem1->MudarVelocidade(value);
}

void MainWindow::on_speed_trem2_valueChanged(int value)
{
    trem2->MudarVelocidade(value);
}

void MainWindow::on_speed_trem3_valueChanged(int value)
{
    trem3->MudarVelocidade(value);
}

void MainWindow::on_speed_trem4_valueChanged(int value)
{
    trem4->MudarVelocidade(value);
}

void MainWindow::on_speed_trem5_valueChanged(int value)
{
    trem5->MudarVelocidade(value);
}

