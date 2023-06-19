#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Usuario.h"

using namespace std;

class Cliente : public Usuario {

private:

    string endereco;

public:

    Cliente();
    Cliente(const string& _nome, const string& _email, const string& _cpf, const string& _login, const string& _senha, const string& _endereco);

    string getEndereco() const;
    void setEndereco(const string& endereco);

};

#endif
