#include "produto.h"

Produto::Produto(int _id,const string& _nome, double _preco, const string& _tamanho, const string& _cor, const string& _marca, int _quantidade, const string& _tipo) : id(_id), nome(_nome), preco(_preco), tamanho(_tamanho), cor(_cor), marca(_marca), quantidade(_quantidade), tipo(_tipo) {
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

string Produto::getTipo() const
{
	return tipo;
}
