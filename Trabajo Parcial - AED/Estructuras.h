#pragma once
#include <iostream>
#include <functional>
#include<stdlib.h>
#include <conio.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include<math.h>
#include<fstream>
using namespace std;

template<class T>
class Nodo {
public:
	T dato;
	Nodo<T> *siguiente;

	Nodo(T obj, Nodo<T> *sig = NULL) {
		dato = obj;
		siguiente = sig;
	}
};
template<class T>
class Cola {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;

public:
	Cola() {
		this->inicio = NULL;
		this->fin = NULL;
	}
	void enqueue(T v) {
		Nodo<T>* nodo = new Nodo<T>(v);
		if (esVacia()) {
			inicio = nodo;
			fin = inicio;
		}
		else {

			fin->siguiente = nodo;
			fin = nodo;
		}
		nodo = NULL;
	}
	T dequeue() {
		T dato = inicio->dato;

		if (inicio == fin) {
			inicio = NULL;
			fin = NULL;
		}
		else {
			inicio = inicio->siguiente;
		}
		return dato;
	}
	bool esVacia() { return (inicio == NULL); }

};
template<class T>
class Pila {
private:
	Nodo<T>* tope;
public:
	Pila() { tope = NULL; };
	void push(T v) {
		if (estaVacia()) {
			tope = new Nodo<T>(v);
		}
		else {
			tope = new Nodo<T>(v, tope);
		}
	}
	T pop() {
		if (estaVacia()) {
			return NULL;
		}
		else {
			T elemento = (T)(tope->dato);
			tope = (Nodo<T>*) tope->siguiente;
			return elemento;
		}
	}
	bool estaVacia() {
		return (tope == NULL);
	}
};
class CDatos {
	int mes;
	float cantidad;
	int dia;
	int proyection;
public:
	CDatos(int mes, float cantidad, int dia, int proyection) :mes(mes), cantidad(cantidad), dia(dia), proyection(proyection) {
	}

	~CDatos() {}
	void setmes(int mes) { this->mes = mes; }
	int getmes() { return this->mes; }
	void setcantidad(float cantidad) { this->cantidad = cantidad; }
	float getcantidad() { return cantidad; }
	void setdia() { this->dia = dia; }
	int getdia() { return dia; }
	int getproyec() { return proyection; }
	void datos() {
		cout << "[ " << dia << " ]" << "[ " << mes << " ]" << " : " << "[" << cantidad << " ]" << endl;
	}
};
