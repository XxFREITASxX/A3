#include "produto.h"

Produto::Produto(int _id,const string& _nome, double _preco, const string& _tamanho, const string& _cor, const string& _marca, int _quantidade, const string& _categoria) : id(_id), nome(_nome), preco(_preco), tamanho(_tamanho), cor(_cor), marca(_marca), quantidade(_quantidade), categoria(_categoria) {
}

int Produto::getId() const
{
	return id;
}

string Produto::getNome() const {
	return nome;
}

double Produto::getPreco() const {
	return preco;
}

string Produto::getTamanho() const {
	return tamanho;
}

string Produto::getCor() const {
	return cor;
}

string Produto::getMarca() const {
	return marca;
}

int Produto::getQuantidade() const {
	return quantidade;
}

string Produto::getCategoria() const
{
	return categoria;
}

void Produto::exibirInfo() const {
	cout << "\nNome: " << nome << endl;
	cout << "Preco: R$" << preco << endl;
	cout << "Tamanho: " << tamanho << endl;
	cout << "Cor: " << cor << endl;
	cout << "Marca: " << marca << endl;
	cout << "Quantidade: " << quantidade << endl;
}
