#include "produto.h"

Produto::Produto(int _id,const string& _nome, float _preco, const string& _tamanho, const string& _cor, const string& _marca, int _quantidade) : id(_id), nome(_nome), preco(_preco), tamanho(_tamanho), cor(_cor), marca(_marca), quantidade(_quantidade) {
}

int Produto::getId() const
{
	return id;
}

string Produto::getNome() const {
	return nome;
}

float Produto::getPreco() const {
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