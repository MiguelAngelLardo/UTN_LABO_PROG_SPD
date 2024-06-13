#include <iostream>
#include "rlutil.h"

using namespace std;

void tiradaDeCartas();
void dibujarRectangulo(int posX, int posY, int ancho, int alto, char fondo = 219);
void dibujarReversoCarta(int posX, int posY);
void dibujarCarta(std::string num, char palo, int posX, int posY);  // Cambi� el tipo de palo a int para el ejemplo
std::string obtenerNumeroCarta(int numero);


int main()
{
    ///3 funciones basicas del main
    //srand(time(0));
    rlutil::hidecursor();
    rlutil::saveDefaultColor();;

    tiradaDeCartas();
    rlutil::locate(1,25);
    return 0;
}

void dibujarRectangulo(int posX, int posY, int ancho, int alto, char fondo){
  for(int x = posX; x < posX+ancho; x++){
    for(int y = posY; y < posY+alto; y++){
      rlutil::locate(x, y);
      cout << fondo;
    }
  }
}

void dibujarNumero(string num, int posX, int posY){
  rlutil::locate(posX, posY);
  cout << num;

  rlutil::locate(posX+5-num.size(), posY+2);
  cout << num;
}

void dibujarReversoCarta(int posX, int posY){
  rlutil::setColor(rlutil::WHITE);
  rlutil::setBackgroundColor(rlutil::LIGHTRED);
  dibujarRectangulo(posX,posY,5,3, 176);
}

///usar el rectangulo y el numero
void dibujarCarta(string num, char palo, int posX, int posY){
  rlutil::setColor(rlutil::WHITE);
  dibujarRectangulo(posX,posY,5,3);

  rlutil::setColor((palo == 3 || palo == 4) ? rlutil::BLUE : rlutil::BLACK);

  rlutil::setBackgroundColor(rlutil::WHITE); // Establecer color de fondo blanco
  dibujarNumero(num, posX, posY);
  rlutil::locate(posX+2, posY+1);
  cout << palo;

}

string obtenerNumeroCarta(int numero){

   string cartas[] = {
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
    };

  return cartas[numero-1];

  // switch(numero)
  // {
  //   case 1:
  //     return "A";
  //     break;
  //   case 11:
  //     return "J";
  //     break;
  //   case 12:
  //     return "Q";
  //     break;
  //   case 13:
  //     return "K";
  //     break;

  //   default:
  //     return to_string(numero);
  // }
}

void tiradaDeCartas(){//4 diamante, 6 pica, 3 corazon, 5 trebol
  int palos[] = {3,4,5,6};

  for(int k = 1; k <=2; k++){//dibuja la carta dada vuelta y la gira
     for(int i = 5; i <=20; i +=5){ //i es la fila
      for(int j=1; j <=13; j++){ //j es la col
        if(k == 1){
          dibujarReversoCarta(j*8, i);
        }else{
          dibujarCarta(obtenerNumeroCarta(j), (char)palos[(i/5)-1], j*8,i);
          rlutil::msleep(25);
        }
      }
    }
  }

}