#include "produto.h"

Produto::Produto(const string& _nome, float _preco, const string& _tamanho, const string& _cor, const string& _marca, int _quantidade) : nome(_nome), preco(_preco), tamanho(_tamanho), cor(_cor), marca(_marca), quantidade(_quantidade) {
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