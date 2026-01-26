#include "bola.h"
#include <math.h>

int Bola::diametro = 40;
int Bola::vidasIniciales = 10;


Bola::Bola() : Bola(0,0,0,0){


}

Bola::Bola(float x, float y, float vx, float vy): posX(x),posY(y), velX(vx),velY(vy){

        rArriba = rAbajo = rDerecha = rIzquierda = 0;

        vidas = vidasIniciales;
        posX = x;
        color = QColor("black");
}

void Bola::mover(float anchura, float altura){

    anchuraJuego = anchura;
    alturaJuego = altura;

    if (vidas < 0 )
        vidas = 0;

    if ( (posX + diametro) > anchura ){
        velX = - fabs(velX);
        rDerecha++;
    }

    if (posX <= 0){
        velX = fabs(velX);
        rIzquierda++;
    }


    if ((posY+diametro) > altura){
        velY = - fabs(velY);
            rAbajo++;
    }
    if (posY< 0){
        velY = fabs(velY);
        rArriba++;
    }

   posX = posX + velX ;
   posY = posY + velY ;
}

void Bola::pintar(QPainter &pintor) {

	static float angulo;
    pintor.setBrush(color);
   pintor.drawEllipse(posX,posY,diametro,diametro);


	float x_nombre = posX  + 1.5 * diametro * std::cos(angulo);
	float y_nombre = posY + (diametro/2) + 1.1 * diametro * std::sin(angulo);
	angulo = angulo + 0.005;
   pintor.drawText(x_nombre, y_nombre,nombre);
	pintor.drawText(x_nombre, y_nombre + 13 ,apellido_1);
	pintor.drawText(x_nombre, y_nombre + 26 ,apellido_2);

   pintor.drawText(posX+ diametro / 2,
                   posY+diametro / 2,
                   QString::number(vidas));
/********************** barra VERDA *********************************/
    pintor.setBrush(QColor("Green"));

    int anchoBarra = Bola::diametro;
    float division = (float) vidas / (float) Bola::vidasIniciales;

    anchoBarra = anchoBarra * division;
    pintor.drawRect(posX,posY - 20,
                    anchoBarra,5);
    float acabaVerda = posX  + anchoBarra ;

/********************** barra ROJA **********************************/
    int mortes = Bola::vidasIniciales  -  vidas;
    division = (float)mortes / (float)Bola::vidasIniciales ;
    anchoBarra = Bola::diametro * division;

    pintor.setBrush(QColor("red"));
    pintor.drawRect(acabaVerda,posY - 20,anchoBarra,  5);

   if (esImagen)
       pintor.drawImage(posX,posY,imagen);

}

float Bola::distancia(Bola *otra){
    float dist;
    dist = sqrtf( powf(this->posX - otra->posX,2) +
            powf(this->posY - otra->posY,2) );

    return dist;

}

bool Bola::choca(Bola * otra){

    bool choque = false;
    if ( this == otra)
        return false;

    if (distancia (otra) > diametro  )
        return false;

    Bola * derecha ;
    Bola * izquierda ;


    if ( this->posX > otra->posX) {
        derecha = this;
        izquierda = otra;
    } else {
        derecha = otra;
        izquierda = this;
    }


    if ( izquierda->velX > derecha->velX ) {
        float aux = izquierda->velX;
        izquierda->velX = derecha->velX;
        derecha->velX = aux;
        choque = true;
    }


    Bola * arriba ;
    Bola * abajo ;


    if ( this->posY > otra->posY) {
        abajo = this;
        arriba = otra;
    } else {
        abajo = otra;
        arriba = this;
    }


    if ( arriba->velY > abajo->velY ) {
        float aux = arriba->velY;
        arriba->velY = abajo->velY;
        abajo->velY = aux;
        choque = true;
    }

    return choque;
}




















