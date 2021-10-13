#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

using namespace std;

class ContainerParticipante{
private:
    list<Participante> container;
    static ContainerParticipante *instancia;
public:
    static ContainerParticipante* getInstancia();
    bool cadastrar(Participante);
    bool remover(Matricula);
    bool pesquisar(Participante*);
    bool pesquisar(Matricula);
    bool editar(Participante);
    bool autenticar(Matricula,Senha);
    bool mostrar(Matricula);
};

class ContainerPeca{
private:
    list<Peca> container;
    static ContainerPeca *instancia;
public:
    static ContainerPeca* getInstancia();
    bool cadastrar(Peca);
    bool remover(Codigo);
    bool pesquisar(Peca*);
    bool editar(Peca);
    bool listar();
};

class ContainerSessao{
private:
    list<Sessao> container;
    static ContainerSessao *instancia;
public:
    static ContainerSessao* getInstancia();
    bool cadastrar(Sessao);
    bool remover(Codigo);
    bool pesquisar(Sessao*);
    bool editar(Sessao);
    bool listar();
};

class ContainerSala{
private:
    list<Sala> container;
    static ContainerSala *instancia;
public:
    static ContainerSala* getInstancia();
    bool cadastrar(Sala);
    bool remover(Codigo);
    bool pesquisar(Sala*);
    bool editar(Sala);
    bool listar();
};
#endif // CONTROLADORAS_H_INCLUDED
