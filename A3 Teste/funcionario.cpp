#include "Funcionario.h"

Funcionario::Funcionario() {}

Funcionario::Funcionario(const string& nome, const string& email, const string& cpf, const string& login, const string& senha, int id_funcionario)
    : Usuario(nome, email, cpf, login, senha), id_funcionario(id_funcionario) {}

int Funcionario::getId_funcionario() const {
    return id_funcionario;
}

void Funcionario::setId_funcionario(int id_funcionario) {
    this->id_funcionario = id_funcionario;
}

bool Funcionario::autenticarUsuario(const string& login, const string& senha) {
    return autenticar(login, senha);
}
