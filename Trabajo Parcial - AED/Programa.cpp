#include "Estructuras.h"
void leer() {
	ifstream leer("archivo.txt");
	string a;
	while (!leer.eof()) // es para que lea todo el archivo
	{
		getline(leer, a);
		cout << a << endl;// estas leyendo linea por linea
	}
}
int main() {
	Cola<CDatos*>* cola;
	Pila<CDatos*>*pila;
	Pila<CDatos*>* pilaAUX;
	ofstream archivo;
	string texto;
	int dia;
	int mes;
	int cantidad;
	int n;
	int option;
	int retroceder = 0;
	int avanzar = 0;
	int i = 0;
	char respuesta;
	cola = new Cola<CDatos*>();
	pila = new Pila<CDatos*>();
	pilaAUX = new Pila<CDatos*>();
	CDatos* elem;
	do {
		if (i == 0) {
			do {
				cout << "\t PROYECCION DE INFECTADOS" << endl;
				cout << " " << endl;
				cout << "[1]INSERTAR DATOS" << endl;
				cout << "[2]REHACER" << endl;
				cout << "[3]DESHACER" << endl;
				cout << "[4]ABRIR" << endl;
				cout << "[5]SALIR" << endl;
				cin >> option;
			} while (option < 0 || option>6);
			i = 1;
			system("cls");
		}
		else {
			do {
				cout << "[1]INSERTAR DATOS     [2]REHACER     [3]DESHACER    [4] [MOSTRAR TXT]     [5]SALIR ";
				cin >> option;
			} while (option < 0 || option>5);
			system("cls");
		}
		switch (option)
		{
		case 1: {
			cout << "\t PROYECCION DE INFECTADOS" << endl;
			do {
				cout << "Ingrese dia:   ";
				cin >> dia;
			} while (dia > 31);
			do {
				cout << "Ingrese mes(numero):   ";
				cin >> mes;
			} while (mes < 1 || mes>12);
			do {
				cout << "Ingrese cantidad de infectados:   ";
				cin >> cantidad;
			} while (cantidad < 1);
			do {
				cout << "Cantidad de dias a proyectar:   ";
				cin >> n;
			} while (n < 0);
			do {
				cout << "Quisiera guardar los datos en su disco duro? (s/n): "; cin >> respuesta;
			} while (respuesta == 's'&&respuesta == 'S');
			cola->enqueue(new CDatos(mes, cantidad, dia, n));
			pila->push(new CDatos(mes, cantidad, dia, n));
			elem = cola->dequeue();
			cantidad = elem->getcantidad();
			dia = elem->getdia();
			archivo.open("archivo.txt", ios::out);
			archivo << "[ " << dia << " ]" << "[ " << mes << " ]" << " : " << "[" << cantidad << " ]" << endl;
			for (int i = 1; i < n; i++) {
				if (dia == 31) { dia = 1; mes++; }
				else { dia++; }
				cantidad = cantidad * 1.0867;
				cola->enqueue(new CDatos(mes, cantidad, dia, n));

				archivo << "[ " << dia << " ]" << "[ " << mes << " ]" << " : " << "[" << cantidad << " ]" << endl;

			}



			system("cls");
			elem->datos();
			do {
				elem = cola->dequeue();
				elem->datos();


			} while (!cola->esVacia()); retroceder++; cout << retroceder; }; break;
		case 2: {
			if (retroceder != 0) {
				elem = pila->pop();//este sera el primero
				pilaAUX->push(new CDatos(elem->getmes(), elem->getcantidad(), elem->getdia(), elem->getproyec()));
				cola->enqueue(new CDatos(elem->getmes(), elem->getcantidad(), elem->getdia(), elem->getproyec()));
				elem = cola->dequeue();
				cantidad = elem->getcantidad();
				dia = elem->getdia();
				mes = elem->getmes();
				n = elem->getproyec();

				for (int i = 1; i < n; i++) {
					if (dia == 31) { dia = 1; }
					else { dia++; }
					cantidad = cantidad * 1.0867;
					cola->enqueue(new CDatos(mes, cantidad, dia, n));


				}

				system("cls");
				cout << "\t PROYECCION DE INFECTADOS" << endl;
				elem->datos();
				do {
					elem = cola->dequeue();
					elem->datos();

				} while (!cola->esVacia());
				retroceder--;
				avanzar++;
			};
		}; break;
		case 3: {
			if (avanzar != 0) {
				elem = pilaAUX->pop();
				pila->push(new CDatos(elem->getmes(), elem->getcantidad(), elem->getdia(), elem->getproyec()));
				cola->enqueue(new CDatos(elem->getmes(), elem->getcantidad(), elem->getdia(), elem->getproyec()));
				elem = cola->dequeue();
				cantidad = elem->getcantidad();
				dia = elem->getdia();
				mes = elem->getmes();
				n = elem->getproyec();
				for (int i = 1; i < n; i++) {
					if (dia == 31) { dia = 1; }
					else { dia++; }
					cantidad = cantidad * 1.087;
					cola->enqueue(new CDatos(mes, cantidad, dia, n));



				}
				system("cls");
				cout << "\t PROYECCION DE INFECTADOS" << endl;
				elem->datos();
				do {
					elem = cola->dequeue();
					elem->datos();

				} while (!cola->esVacia());
				avanzar--; retroceder++;
			};
		}; break;

		case 4:
			leer();
			break;
		case 5:
			option = 0;
			archivo.close();
			system("cls");
		}

	} while (option != 0);
	_getch();
	return 0;
}