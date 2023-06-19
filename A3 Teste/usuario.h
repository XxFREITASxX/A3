#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

using namespace std;

class Usuario {

private:

    string nome;
    string email;
    string cpf;
    string login;
    string senha;

public:

    Usuario();
    Usuario(const string& nome, const string& email, const string& cpf, const string& login, const string& senha);

    string getNome() const;
    string getEmail() const;
    string getCpf() const;
    string getLogin() const;
    string getSenha() const;

    void setNome(const string& nome);
    void setEmail(const string& email);
    void setCpf(const string& cpf);
    void setLogin(const string& login);
    void setSenha(const string& senha);

    bool autenticar(const string& login, const string& senha);
};

#endif
