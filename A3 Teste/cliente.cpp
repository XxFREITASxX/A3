#include "Cliente.h"

Cliente::Cliente() {}

Cliente::Cliente(const string& _nome, const string& _email, const string& _cpf, const string& _login, const string& _senha, const string& _endereco)
    : Usuario(_nome, _email, _cpf, _login, _senha), endereco(_endereco) {}

string Cliente::getEndereco() const {
    return endereco;
}

void Cliente::setEndereco(const string& endereco) {
    this->endereco = endereco;
}
