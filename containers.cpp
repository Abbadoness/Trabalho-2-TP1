#include "containers.h"
#include "entidades.h"
#include "dominios.h"

#include <conio.h>
#include <iostream>
#include <string.h>

ContainerParticipante* ContainerParticipante::instancia = nullptr;

ContainerParticipante* ContainerParticipante::getInstancia(){
    if(instancia == nullptr){
        instancia = new ContainerParticipante();
    }
    return instancia;
}
bool ContainerParticipante::cadastrar(Participante participante){
    for(list<Participante>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getMatricula().getValor() == participante.getMatricula().getValor()){
            return false;
        }
    }
    container.push_back(participante);
    return true;
}
bool ContainerParticipante::remover(Matricula matricula){
    for(list<Participante>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if(elemento->getMatricula().getValor() == matricula.getValor()){
            container.erase(elemento);
            return true;
        }
    }
    return false;
}
bool ContainerParticipante::pesquisar(Participante* participante){
    for(list<Participante>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getMatricula().getValor() == participante->getMatricula().getValor()){
            participante->setCargo(elemento->getCargo());
            participante->setEmail(elemento->getEmail());
            participante->setNome(elemento->getNome());
            participante->setSenha(elemento->getSenha());
            participante->setSobrenome(elemento->getSobrenome());
            participante->setTelefone(elemento->getTelefone());

            return true;
        }
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ContainerParticipante::pesquisar(Matricula matricula){
    for(list<Participante>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getMatricula().getValor() == matricula.getValor()){
            return true;
        }
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ContainerParticipante::mostrar(Matricula matricula){
    for(list<Participante>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getMatricula().getValor() == matricula.getValor()){
            cout << "\nParticipante: " << endl;
            cout << "Matricula: " << elemento->getMatricula().getValor() << endl;
            cout << "Nome: " << elemento->getNome().getValor() << endl;
            cout << "Sobrenome: " << elemento->getSobrenome().getValor() << endl;
            cout << "E-mail: " << elemento->getEmail().getValor() << endl;
            cout << "Telefone: " << elemento->getTelefone().getValor() << endl;
            cout << "Senha: " << elemento->getSenha().getValor() << endl;
            cout << "Cargo: " << elemento->getCargo().getValor() << endl;

            return true;
        }
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ContainerParticipante::editar(Participante participante){
    for(list<Participante>::iterator elemento = container.begin();elemento != container.end(); elemento++){
        if(elemento->getMatricula().getValor() == participante.getMatricula().getValor()){
            elemento->setCargo(participante.getCargo());
            elemento->setEmail(participante.getEmail());
            elemento->setNome(participante.getNome());
            elemento->setSenha(participante.getSenha());
            elemento->setSobrenome(participante.getSobrenome());
            elemento->setTelefone(participante.getTelefone());
            return true;
        }
    }
    return false;
}

bool ContainerParticipante::autenticar(Matricula matricula,Senha senha){
    for(list<Participante>::iterator elemento = container.begin();elemento != container.end(); elemento++){
        if(elemento->getMatricula().getValor() == matricula.getValor()){
            if(elemento->getSenha().getValor() == senha.getValor()){
                return true;
            }
            return false;
        }
    }
    return false;
}

//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
ContainerPeca* ContainerPeca::instancia = nullptr;

ContainerPeca* ContainerPeca::getInstancia(){
    if(instancia == nullptr){
        instancia = new ContainerPeca();
    }
    return instancia;
}

bool ContainerPeca::listar(){
    for(list<Peca>::iterator elemento = container.begin();elemento != container.end();elemento++){
        cout << "\n" << endl;
        cout << elemento->getIdentificador().getValor() << endl;
        cout << elemento->getNome().getValor() << endl;
        cout << elemento->getTipo().getValor() << endl;
        cout << elemento->getClassificacao().getValor() <<endl;
    }
    return true;
}

bool ContainerPeca::cadastrar(Peca peca){
    for(list<Peca>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getIdentificador().getValor() == peca.getIdentificador().getValor()){
            return false;
        }
    }
    container.push_back(peca);
    return true;
}

bool ContainerPeca::pesquisar(Peca* peca){
    for(list<Peca>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getIdentificador().getValor() == peca->getIdentificador().getValor()){
            peca->setNome(elemento->getNome());
            peca->setTipo(elemento->getTipo());
            peca->setClassificacao(elemento->getClassificacao());

            return true;
        }
    }
    return false;
}

bool ContainerPeca::remover(Codigo codigo){
    for(list<Peca>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if(elemento->getIdentificador().getValor() == codigo.getValor()){
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerPeca::editar(Peca peca){
    for(list<Peca>::iterator elemento = container.begin();elemento != container.end(); elemento++){
        if(elemento->getIdentificador().getValor() == peca.getIdentificador().getValor()){
            elemento->setTipo(peca.getTipo());
            elemento->setClassificacao(peca.getClassificacao());
            elemento->setNome(peca.getNome());

            return true;
        }
    }
    return false;
}

//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
ContainerSessao* ContainerSessao::instancia = nullptr;

ContainerSessao* ContainerSessao::getInstancia(){
    if(instancia == nullptr){
        instancia = new ContainerSessao();
    }
    return instancia;
}

bool ContainerSessao::listar(){
    for(list<Sessao>::iterator elemento = container.begin();elemento != container.end();elemento++){
        cout << "\n" << endl;
        cout << elemento->getIdentificador().getValor() << endl;
        cout << elemento->getData().getValor() << endl;
        cout << elemento->getHorario().getValor() << endl;
    }
    return true;
}

bool ContainerSessao::cadastrar(Sessao sessao){
    for(list<Sessao>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getIdentificador().getValor() == sessao.getIdentificador().getValor()){
            return false;
        }
    }
    container.push_back(sessao);
    return true;
}

bool ContainerSessao::pesquisar(Sessao* sessao){
    for(list<Sessao>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getIdentificador().getValor() == sessao->getIdentificador().getValor()){
            sessao->setData(elemento->getData());
            sessao->setHorario(elemento->getHorario());

            return true;
        }
    }
    return false;
}

bool ContainerSessao::remover(Codigo codigo){
    for(list<Sessao>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if(elemento->getIdentificador().getValor() == codigo.getValor()){
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerSessao::editar(Sessao sessao){
    for(list<Sessao>::iterator elemento = container.begin();elemento != container.end(); elemento++){
        if(elemento->getIdentificador().getValor() == sessao.getIdentificador().getValor()){
            elemento->setData(sessao.getData());
            elemento->setHorario(sessao.getHorario());

            return true;
        }
    }
    return false;
}


//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
ContainerSala* ContainerSala::instancia = nullptr;

ContainerSala* ContainerSala::getInstancia(){
    if(instancia == nullptr){
        instancia = new ContainerSala();
    }
    return instancia;
}

bool ContainerSala::listar(){
    for(list<Sala>::iterator elemento = container.begin();elemento != container.end();elemento++){
        cout << "\n" << endl;
        cout << elemento->getIdentificador().getValor() << endl;
        cout << elemento->getNome().getValor() << endl;
        cout << elemento->getCapacidade().getValor() << endl;
    }
    return true;
}

bool ContainerSala::cadastrar(Sala sala){
    for(list<Sala>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getIdentificador().getValor() == sala.getIdentificador().getValor()){
            return false;
        }
    }
    container.push_back(sala);
    return true;
}

bool ContainerSala::pesquisar(Sala* sala){
    for(list<Sala>::iterator elemento = container.begin();elemento != container.end();elemento++){
        if(elemento->getIdentificador().getValor() == sala->getIdentificador().getValor()){
            sala->setNome(elemento->getNome());
            sala->setCapacidade(elemento->getCapacidade());

            return true;
        }
    }
    return false;
}

bool ContainerSala::remover(Codigo codigo){
    for(list<Sala>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if(elemento->getIdentificador().getValor() == codigo.getValor()){
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerSala::editar(Sala sala){
    for(list<Sala>::iterator elemento = container.begin();elemento != container.end(); elemento++){
        if(elemento->getIdentificador().getValor() == sala.getIdentificador().getValor()){
            elemento->setNome(sala.getNome());
            elemento->setCapacidade(sala.getCapacidade());

            return true;
        }
    }
    return false;
}
