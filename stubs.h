#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "intefaces.h"

using namespace std;

class StubServicoAutenticacao:public IServicoAutenticacao {
private:
    static const string INVALIDO;
public:
    bool autenticar(Matricula, Senha);
};

class StubServicoParticipante:public IServicoParticipante {
private:
    static const string INVALIDO;
public:
    bool cadastrarParticipante(Participante);
};

class StubServicoPeca:public IServicoPeca{
private:
    static const string INVALIDO;
public:
    bool cadastrarPeca(Peca);
    bool consultarPeca(Peca*);
};

#endif // STUBS_H_INCLUDED
