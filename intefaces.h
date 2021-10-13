#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

class IServicoAutenticacao;
class IServicoParticipante;
class IServicoPeca;

class IApresentacaoAutenticacao {
public:
    virtual bool autenticar(Matricula*) = 0;
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
    virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoParticipante {
public:
    virtual void executar(Matricula) = 0;
    virtual void cadastrar() = 0;
    virtual void setCntrServicoParticipante(IServicoParticipante*) = 0;
    virtual ~IApresentacaoParticipante(){}
};

class IApresentacaoPeca{
public:
    virtual void executar() = 0;
    virtual void executar(Matricula) = 0;
    virtual void setCntrServicoPeca(IServicoPeca*) = 0;
    virtual ~IApresentacaoPeca(){}
};

class IServicoAutenticacao {
public:
    virtual bool autenticar(Matricula,Senha) = 0;
    virtual ~IServicoAutenticacao(){}
};

class IServicoParticipante{
public:
    virtual bool cadastrarParticipante(Participante) = 0;
    virtual bool editarParticipante(Participante) = 0;
    virtual bool excluirParticipante(Participante) = 0;
    virtual bool excluirParticipanteM(Matricula) = 0;
    virtual bool mostrar(Matricula) = 0;
    virtual ~IServicoParticipante(){}
};

class IServicoPeca{
public:

    //virtual bool listarPeca() = 0;
    virtual bool cadastrarPeca(Peca) = 0;
    virtual bool editarPeca(Peca) = 0;
    virtual Peca consultarPeca(Peca) = 0;
    virtual bool excluirPeca(Codigo) = 0;

    virtual bool listarSala() = 0;
    virtual bool cadastrarSala(Sala) = 0;
    virtual bool editarSala(Sala) = 0;
    virtual Sala consultarSala(Sala) = 0;
    virtual bool excluirSala(Codigo) = 0;

    virtual bool listarSessao() = 0;
    virtual bool cadastrarSessao(Sessao) = 0;
    virtual bool editarSessao(Sessao) = 0;
    virtual Sessao consultarSessao(Sessao) = 0;
    virtual bool excluirSessao(Codigo) = 0;

    virtual ~IServicoPeca(){}
};

#endif // INTERFACES_H_INCLUDED
