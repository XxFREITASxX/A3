#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>

using namespace std;

class Produto {

	private:

	int id;
	string nome;
	double preco;
	string tamanho;
	string cor;
	string marca;
	int quantidade;
	string categoria;

	public:

	Produto(int id,const string& _nome, double _preco, const string& _tamanho, const string& _cor, const string& _marca, int quantidade, const string& categoria);

	int getId() const;
	string getNome() const;
	double getPreco() const;
	string getTamanho() const;
	string getCor() const;
	string getMarca() const;
	int getQuantidade() const;
	string getCategoria() const;

};

#endif