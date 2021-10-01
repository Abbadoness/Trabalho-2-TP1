#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "intefaces.h"

#define CLR_SCR system("cls");

class CntrApresentacaoControle{
private:
    Matricula matricula;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoParticipante *cntrApresentacaoParticipante;
    IApresentacaoPeca *cntrApresentacaoPeca;
public:
    void executar();
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
    void setCntrApresentacaoParticipante(IApresentacaoParticipante*);
    void setCntrApresentacaoPeca(IApresentacaoPeca*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoParticipante(IApresentacaoParticipante *cntr){
    cntrApresentacaoParticipante = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPeca(IApresentacaoPeca *cntr){
    cntrApresentacaoPeca = cntr;
}


class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
private:
    IServicoAutenticacao *cntr;
public:
    bool autenticar(Matricula*);
    void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}


class CntrApresentacaoParticipante:public IApresentacaoParticipante{
private:
    IServicoParticipante *cntrServicoParticipante;
    void consultarDadosPessoais();
public:
    void executar(Matricula);
    void cadastrar();
    void setCntrServicoParticipante(IServicoParticipante*);
};

inline void CntrApresentacaoParticipante::setCntrServicoParticipante(IServicoParticipante *cntr){
    cntrServicoParticipante = cntr;
}


class CntrApresentacaoPeca:public IApresentacaoPeca{
private:
    IServicoPeca *cntr;
    void consultarPeca();
    void cadastrarPeca();
public:
    void executar();
    void executar(Matricula);
    void setCntrServicoPeca(IServicoPeca*);
};

inline void CntrApresentacaoPeca::setCntrServicoPeca(IServicoPeca *cntr){
    this->cntr = cntr;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
