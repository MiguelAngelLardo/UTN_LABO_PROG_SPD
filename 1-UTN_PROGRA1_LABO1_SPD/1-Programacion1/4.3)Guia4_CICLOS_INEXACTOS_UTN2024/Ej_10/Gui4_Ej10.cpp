/*
10-Hacer un programa para ingresar una lista de n�meros que finaliza cuando se ingresa un cero,
luego informar el m�ximo y el m�nimo.

Ejemplo A: 10, 20, -5, 30,-15, 5, 42, 2, 22, -13, 0. Se listar� M�ximo 42 M�nimo -15.
Ejemplo B: 10, 20, 5, 30, 15, 5, 42, 8, 22, 13, 0. Se listar� M�ximo 42 M�nimo 5.
Ejemplo C: -10, -20, -5, -30, -15, -12, -42, -8, -22, -13, 0. Se listar� M�ximo -5 M�nimo -42.

Observe que los ejemplos B y C dejan en claro que la suposici�n de que el m�ximo �seguramente�
es un positivo y el m�nimo �seguramente� es un negativo, es incorrecta.
*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");

	int numero, maximo, minimo;

	 cout << "Ingrese un n�mero " ;
	 cin >> numero;
	 maximo = numero;
	 minimo = numero;

	 while (numero!=0){
		if(numero>maximo){
			maximo = numero;

		}else if(numero < minimo){
			minimo = numero;
		}

		cout << "Ingrese otro n�mero (para finalizar ingrese 0) " ;
		cin >> numero;
	 }

	cout << "---------------------------------"<< endl;
	cout << "El maximo n�mero ingresado es: " << maximo<< endl;
	cout << "El minimo n�mero ingresado es: " << minimo<< endl;


return 0;
}
