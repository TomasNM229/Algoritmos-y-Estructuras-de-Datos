#pragma once
#include "Transaccion.h"
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class Block
{
private:
	int index; //Indice del bloque 
	size_t blockHash; //size_t: Tamaño del objeto en bytes
	size_t hashAnterior;
	long nonce;
public:
	// Constuctor
	Block(int _index, TransaccionData _data, size_t _hashAnterior) {
		this->index = _index;
		this->data = _data;
		this->hashAnterior = _hashAnterior;
		this->nonce = rand() % 90002 + 100000;
		this->blockHash = GeneradorHash();
	}
	int getIndex() { return this->index; } //Encontrar el indice
	size_t getHash() { return this->blockHash; } //Encontrar el original hash
	size_t getHashAnterior() { return this->hashAnterior; } //Encontrar el anterior hash
	TransaccionData data; // Informacion de la transacción
	bool hashValido() { return GeneradorHash() == getHash(); } //Valida el hash -> Si alguien manipuló los datos e intenta generar el hash nuevamente entonces no será igual al hash del bloque 
	long getNonce() { return this->nonce; }
	void setNonce(long _nonce) { this->nonce = _nonce; }
	int get_index() { return index; }
	void set_index(int _index) { this->index = _index; }
	TransaccionData get_data() { return data; }
	void set_data(TransaccionData _data) { this->data = _data; }

	void set_HashAnterior(size_t _hash_anterior) { this->hashAnterior = _hash_anterior; }

private:
	size_t GeneradorHash() { //Funcion que devuelve el tamaño del hash generado sin signo
							 // hash: Encripta la data de la transaccion - convierte el hash en un string 
		string toHashS = data.monto_transaccion + to_string(nonce) + to_string(data.clave_emisor) + to_string(data.clave_receptor) + data.timestamp;

		//Combina estos dos hashes, para crear un único hash para este bloque -  Si alguien modifica a los datos de la transaccion
		//o los datos del bloque de este bloque o del bloque anterior, invalidará este bloque
		//Estan unidas criptográficamente 
		hash<string> tDataHash; // hash de la cadena de la transaccion de datos   -hash2
		hash<string> prevHash; // hash anterior del bloque anterior               -hash1

							   // hash1 (^)XOR hash2 , obtiene size_t 
		return tDataHash(toHashS) ^ (prevHash(to_string(hashAnterior)) << 1);
	}

};

