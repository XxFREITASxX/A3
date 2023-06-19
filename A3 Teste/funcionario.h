#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Usuario.h"

class Funcionario : public Usuario {

private:

    int id_funcionario;

public:

    Funcionario();
    Funcionario(const string& nome, const string& email, const string& cpf, const string& login, const string& senha, int id_funcionario);

    int getId_funcionario() const;
    void setId_funcionario(int id_funcionario);

    bool autenticarUsuario(const string& login, const string& senha);
};

#endif
