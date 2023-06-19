#include "Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(const string& nome, const string& email, const string& cpf, const string& login, const string& senha)
    : nome(nome), email(email), cpf(cpf), login(login), senha(senha) {}

string Usuario::getNome() const {
    return nome;
}

string Usuario::getEmail() const {
    return email;
}

string Usuario::getCpf() const {
    return cpf;
}

string Usuario::getLogin() const {
    return login;
}

string Usuario::getSenha() const {
    return senha;
}

void Usuario::setNome(const string& nome) {
    this->nome = nome;
}

void Usuario::setEmail(const string& email) {
    this->email = email;
}

void Usuario::setCpf(const string& cpf) {
    this->cpf = cpf;
}

void Usuario::setLogin(const string& login) {
    this->login = login;
}

void Usuario::setSenha(const string& senha) {
    this->senha = senha;
}

bool Usuario::autenticar(const string& login, const string& senha) {
    return (this->login == login && this->senha == senha);
}
