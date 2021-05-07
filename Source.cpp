#include "Header.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void imprimir(int e) {
	cout << " " << e;
}

int main() {
	//srand(time(0));
	ArbolBB<int>* arbol = new ArbolBB<int>(imprimir);
	/*
	for (int i = 0; i < 30; ++i) {
	arbol->insertar(rand() % 100);
	}*/

	//***Pruebas***
	//Ingreso manual
	//Caso 1:
	//arbol->insertar(6);
	//arbol->insertar(16);
	//arbol->insertar(26);

	//Caso 2:
	arbol->insertar(10);
	arbol->insertar(6);
	arbol->insertar(26);
	arbol->insertar(4);
	arbol->insertar(8);
	arbol->insertar(7);
	arbol->insertar(9);


	cout << "EnOrden";
	arbol->enOrden();
	cout << endl;

	cout << "PreOrden";
	arbol->preOrden();
	cout << endl;

	cout << "PostOrden";
	arbol->postOrden();
	cout << endl;

	cout << "Altura: " << arbol->altura() << endl;
	cout << "Cantidad: " << arbol->cantidad() << endl;

	cout << "Encontrar 26: " << arbol->Buscar(26) << endl;
	cout << "Encontrar 100: " << arbol->Buscar(100) << endl;



	cout << "Minimo: " << arbol->Minimo() << endl;
	cout << "Maximo: " << arbol->Maximo() << endl;

	arbol->Eliminar(6);

	cout << "EnOrden:";
	arbol->enOrden();
	cout << endl;

	cout << "EnPreOrden:";
	arbol->preOrden();
	cout << endl;

	cin.get();

	return 0;
}