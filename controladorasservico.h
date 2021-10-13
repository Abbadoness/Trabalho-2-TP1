#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "intefaces.h"

#include <list>

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>


class CntrServicoAutenticacao:public IServicoAutenticacao{
public:
    virtual bool autenticar(Matricula, Senha);
};

class CntrServicoParticipante:public IServicoParticipante{
    bool cadastrarParticipante(Participante);
    bool editarParticipante(Participante);
    bool excluirParticipante(Participante);
    bool excluirParticipanteM(Matricula);
    bool mostrar(Matricula);
};

class CntrServicoPeca:public IServicoPeca{

    public:bool listarPeca();
    bool cadastrarPeca(Peca);
    bool editarPeca(Peca);
    Peca consultarPeca(Peca);
    bool excluirPeca(Codigo);

    bool listarSala();
    bool cadastrarSala(Sala);
    bool editarSala(Sala);
    Sala consultarSala(Sala);
    bool excluirSala(Codigo);

    bool listarSessao();
    bool cadastrarSessao(Sessao);
    bool editarSessao(Sessao);
    Sessao consultarSessao(Sessao);
    bool excluirSessao(Codigo);

};



#endif // CONTROLADORASSERVICO_H_INCLUDED
