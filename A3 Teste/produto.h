#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>

using namespace std;

class Produto {

	private:

	string nome;
	float preco;
	string tamanho;
	string cor;
	string marca;
	int quantidade;

	public:

	Produto(const string& _nome, float _preco, const string& _tamanho, const string& _cor, const string& _marca, int quantidade);

	string getNome() const;
	float getPreco() const;
	string getTamanho() const;
	string getCor() const;
	string getMarca() const;
	int getQuantidade() const;

};

#endif