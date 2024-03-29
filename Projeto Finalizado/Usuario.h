#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <iostream>
#include <iomanip>//Para a utilizašao do setfill e setw no .cpp
#include <stdlib.h>//Para a utilizašao do exit() e do system no .cpp
#include "Gerencia.h"

class Usuario{
private:
    vector<Gerencia> lista_gerente;

public:
    Usuario();
    bool verificarLogin();
    bool inserirGerente(Gerencia);
    void salvarCadastro();
    void carregarUsuarios();
};

#endif
