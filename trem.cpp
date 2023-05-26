#include "trem.h"
#include <QtCore>
#include <QList>
#include <QSemaphore>
#include <QDebug>

//Construtor
Trem::Trem(int ID, int x, int y, int velocidade, std::vector<QSemaphore*> regioes_criticas){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;
    this->regioes_criticas = regioes_criticas;
}

void Trem::MudarVelocidade(int velocidade) {
    this->velocidade = velocidade;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            //indo para a direita
            if (y == 40 && x <490){
                if(x == 470 ) {
                    if(regioes_criticas[0]->available()){
                        regioes_criticas[0]->acquire(1); //tenta entrar na regiao 0
                        x+=10;
                    }
                }
                else
                    x+=10;
            }
            //indo para baixo
            else if (x == 490 && y < 160){
                if(y == 140) {
                    if (regioes_criticas[1]->available()) {
                        regioes_criticas[1]->acquire(1); //tenta entrar na regiao 1
                        y+=10;
                    }
                }
                else
                    y+=10;
            }
            //indo para a esquerda
            else if (x > 220 && y == 160){
                if(x == 470) {
                    if (!regioes_criticas[0]->available()){
                        regioes_criticas[0]->release(1); //libera a regiao 0
                    }
                    x-=10;
                }
                else if(x == 370) {
                    if (regioes_criticas[2]->available()) {
                        regioes_criticas[2]->acquire(1); //tenta entrar na regiao 2
                        x-=10;
                    }
                }
                else if(x == 330) {
                    if (!regioes_criticas[1]->available()){
                        regioes_criticas[1]->release(1); //libera a regiao 1
                    }
                    x-=10;
                }
                else
                    x-=10;
            }
            //indo para cima
            else{
                if(y == 140){
                    if (!regioes_criticas[2]->available()) {
                        regioes_criticas[2]->release(1); //libera a regiao 2
                    }
                    y-=10;
                }
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            //indo para a direita
            if (y == 40 && x <760){
                if(x == 510){
                    if(!regioes_criticas[0]->available()){
                        regioes_criticas[0]->release(1); //libera a regiao 0
                    }
                    x+=10;
                }
                else
                    x+=10;
            }
            //indo para baixo
            else if (x == 760 && y < 160){
                if(y == 140) {
                    if(regioes_criticas[4]->available()){
                        regioes_criticas[4]->acquire(1); //tenta entrar na regiao 4
                        y+=10;
                    }
                }
                else
                    y+=10;
            }
            //indo para a esquerda
            else if (x > 490 && y == 160){
                if(x == 640) {
                    if(regioes_criticas[3]->available()){
                        regioes_criticas[3]->acquire(1); //tenta entrar na regiao 3
                        x-=10;
                    }
                }
                else if(x == 600){
                    if (!regioes_criticas[4]->available()){
                        regioes_criticas[4]->release(1); //libera a regiao 4
                    }
                    x-=10;
                }
                else if(x == 510) {
                    if(regioes_criticas[0]->available()){
                        regioes_criticas[0]->acquire(1); //tenta entrar na regiao 0
                        x-=10;
                    }
                }
                else
                    x-=10;
            }
            //indo para a cima
            else{
                if(y == 140){
                    if (!regioes_criticas[3]->available()){
                        regioes_criticas[3]->release(1); //libera a regiao 3
                    }
                    y-=10;
                } else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            //indo para a direita
            if (y == 160 && x < 350){
                if(x == 200) {
                    if(regioes_criticas[2]->available()){
                        regioes_criticas[2]->acquire(1); //tenta entrar na regiao 2
                        x+=10;
                    }
                }
                else if(x == 330) {
                    if(regioes_criticas[5]->available()){
                        regioes_criticas[5]->acquire(1); //tenta entrar na regiao 5
                        x+=10;
                    }
                }
                else
                    x+=10;
            }
            //indo para baixo
            else if (x == 350 && y < 280){
                if(y == 180){
                    if (!regioes_criticas[2]->available()){
                        regioes_criticas[2]->release(1); //libera a regiao 2
                    }
                    y+=10;
                }
                else
                    y+=10;
            }
            //indo para a esquerda
            else if (x > 80 && y == 280){
                if(x == 330){
                    if(!regioes_criticas[5]->available()){
                        regioes_criticas[5]->release(1); //libera a regiao 5
                    }
                    x-=10;
                }
                else
                    x-=10;
            }
            //indo para cima
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            //indo para a direita
            if (y == 160 && x <620){
                if(x == 370){
                    if(!regioes_criticas[5]->available()){
                        regioes_criticas[5]->release(1); //libera a regiao 5
                    }
                    x+=10;
                }
                else if(x == 470) {
                    if(regioes_criticas[3]->available()){
                        regioes_criticas[3]->acquire(1); //tenta entrar na regiao 3
                        x+=10;
                    }
                }
                else if(x == 510) {
                    if(!regioes_criticas[1]->available()){
                        regioes_criticas[1]->release(1); //libera a regiao 1
                    }
                    x+=10;
                }
                else if(x == 600) {
                    if(regioes_criticas[6]->available()){
                        regioes_criticas[6]->acquire(1); //tenta entrar na regiao 6
                        x+=10;
                    }
                }
                else
                    x+=10;
            }
            //indo para baixo
            else if (x == 620 && y < 280){
                if(y == 180){
                    if(!regioes_criticas[3]->available()){
                        regioes_criticas[3]->release(1); //libera a regiao 3
                    }
                    y+=10;
                }
                else
                    y+=10;
            }
            //indo para a esquerda
            else if (x > 350 && y == 280){
                if(x == 600){
                    if(!regioes_criticas[6]->available()){
                        regioes_criticas[6]->release(1); //libera a regiao 6
                    }
                    x-=10;
                }
                else if(x == 370){
                    if(regioes_criticas[5]->available()){
                        regioes_criticas[5]->acquire(1); //tenta entrar na regiao 5
                        x-=10;
                    }
                }
                else
                    x-=10;
            }
            //indo para cima
            else{
                if(y == 180) {
                    if(regioes_criticas[1]->available()){
                        regioes_criticas[1]->acquire(1); //tenta entrar na regiao 1
                        y-=10;
                    }
                }
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            //indo para a direita
            if (y == 160 && x <890){
                if(x == 640) {
                    if(!regioes_criticas[6]->available()){
                        regioes_criticas[6]->release(1); //libera a regiao 6
                    }
                    x+=10;
                }
                else if(x == 780) {
                    if(!regioes_criticas[4]->available()){
                        regioes_criticas[4]->release(1); //libera a regiao 4
                    }
                    x+=10;
                }
                else
                    x+=10;
            }
            //indo para baixo
            else if (x == 890 && y < 280)
                y+=10;
            //indo para a esquerda
            else if (x > 620 && y == 280){
                if(x == 640){
                    if(regioes_criticas[6]->available()){
                        regioes_criticas[6]->acquire(1); //tenta entrar na regiao 6
                        x-=10;
                    }
                }
                else
                    x-=10;
            }
            //indo para a cima
            else{
                if(y == 180) {
                    if(regioes_criticas[4]->available()){
                        regioes_criticas[4]->acquire(1); //tenta entrar na regiao 4
                        y-=10;
                    }
                }
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}




