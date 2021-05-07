#pragma once

#include "Block.h"

class Blockchain
{
private:
	vector<Block> cadenaBloques; // cadena de bloques

public:
	Blockchain() {
		Block block_genesis = CreadorGenesisBlock();
		cadenaBloques.push_back(block_genesis); //Agrega el block genesis a la cadena de bloques
	}

	vector<Block> getBlockchain() {
		return cadenaBloques;
	}

	Block* getUltimoBlock() { //Manipular falsamento los datos -> Validacion - Solo ejemplo
		return &cadenaBloques.back(); //Devuelve el ultimo block 
	}

	bool cadenaValida() {
		vector<Block>::iterator it;

		for (it = cadenaBloques.begin(); it != cadenaBloques.end(); it)
		{
			Block block_actual = *it;
			if (!block_actual.hashValido()) //Si el hash del block actual NO es valido
				return false;

			if (it != cadenaBloques.begin()) //Si NO es el primer block de la cadena
			{
				Block block_anterior = *(it - 1);
				if (block_actual.getHashAnterior() != block_anterior.getHash()) // Valida los hashes de dos bloques(actual-anterior)
					return false;
			}
		}
		return true;
	}
	void agregarBlock(TransaccionData data) {
		int index = (int)cadenaBloques.size(); //Ultimo indice
		size_t ultimoHash = (int)cadenaBloques.size() > 0 ? getUltimoBlock()->getHash() : 0;
		Block nuevoBlock(index, data, ultimoHash);//Crear un bloque a partir del ultimo indice
		cadenaBloques.push_back(nuevoBlock);
	}


	Block CreadorGenesisBlock() {
		//Block genesis -> Primer block de la cadena de bloques
		string hora_actual;
		TransaccionData data;
		data.monto_transaccion = "0";
		data.timestamp = "221300";
		long nonce = 0;

		string toHashS = data.monto_transaccion + to_string(data.clave_receptor) + to_string(data.clave_emisor) + to_string(nonce) + data.timestamp;

		hash<string> tDataHash;// Hash de la cadena de los datos de la transaccion
		hash<string> prevHash;// Hash anterior del bloque anterior

							  //Combina los 2 hashes anteriores y obtiene size_t para el hash del bloque actual 
		size_t hash = tDataHash(toHashS) ^ (prevHash(to_string(0)) << 1); //Funcion combinada de la biblioteca - biblioteca criptográfica

		Block blockGenesis(0, data, hash);
		return blockGenesis;
	}
};