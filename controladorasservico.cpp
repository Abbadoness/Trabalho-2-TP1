#include "controladorasservico.h"
#include "dominios.h"
#include "entidades.h"
#include "containers.h"

bool CntrServicoAutenticacao::autenticar(Matricula matricula,Senha senha){

    bool autenticado = false;
    ContainerParticipante *container;
    container = ContainerParticipante::getInstancia();
    autenticado = container->autenticar(matricula,senha);
    return autenticado;
}

bool CntrServicoParticipante::cadastrarParticipante(Participante participante){
    bool jaExiste = false;
    ContainerParticipante *container;
    container = ContainerParticipante::getInstancia();
    jaExiste = container->pesquisar(&participante);
    if(jaExiste == true){
        return false;
    }

    jaExiste = container->cadastrar(participante);
    if(jaExiste){
        return true;
    }else{
        return false;
    }
}

bool CntrServicoParticipante::editarParticipante(Participante participante){
    ContainerParticipante *container;
    container = ContainerParticipante::getInstancia();
    bool existe = false;
    existe = container->pesquisar(&participante);
    if(!existe){
        return false;
    }
    existe = false;
    existe = container->editar(participante);
    if(existe){
        return true;
    }
    return false;
}

bool CntrServicoParticipante::excluirParticipante(Participante participante){
    ContainerParticipante *container;
    container = ContainerParticipante::getInstancia();
    bool existe = false;
    existe = container->pesquisar(&participante);
    if(!existe){
        return false;
    }
    existe = false;
    existe = container->remover(participante.getMatricula());
    if(existe){
        return true;
    }else{
        return false;
    }
}

bool CntrServicoParticipante::excluirParticipanteM(Matricula matricula){
    ContainerParticipante *container;
    container = ContainerParticipante::getInstancia();
    bool existe = false;
    existe = container->pesquisar(matricula);
    if(!existe){
        return false;
    }
    existe = false;
    existe = container->remover(matricula);
    if(existe){
        return true;
    }else{
        return false;
    }
}

bool CntrServicoParticipante::mostrar(Matricula matricula){
    ContainerParticipante *container;
    container = ContainerParticipante::getInstancia();
    bool existe = false;
    existe = container->pesquisar(matricula);
    if(!existe){
        return false;
    }
    existe = false;
    existe = container->mostrar(matricula);

    if(existe){
        return true;
    }else{
        return false;
    }

}
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
bool CntrServicoPeca::listarPeca(){
    ContainerPeca *container;
    container = ContainerPeca::getInstancia();
    container->listar();
    return true;
}

bool CntrServicoPeca::cadastrarPeca(Peca peca){
    bool jaExiste = false;
    ContainerPeca *container;
    container = ContainerPeca::getInstancia();
    jaExiste = container->pesquisar(&peca);
    if(jaExiste == true){
        return false;
    }

    jaExiste = container->cadastrar(peca);
    if(jaExiste){
        return true;
    }else{
        return false;
    }
}

bool CntrServicoPeca::editarPeca(Peca peca){
    ContainerPeca *container;
    container = ContainerPeca::getInstancia();
    bool existe = false;
    existe = container->pesquisar(&peca);
    if(!existe){
        return false;
    }
    existe = false;
    existe = container->editar(peca);
    if(existe){
        return true;
    }
    return false;
}

Peca CntrServicoPeca::consultarPeca(Peca peca){
    ContainerPeca *container;
    container = ContainerPeca::getInstancia();
    bool existe = false;
    existe = container->pesquisar(&peca);
    Peca pecaFalse;
    if(!existe){
        return pecaFalse;
    }
    existe = false;
    return peca;
}

 bool CntrServicoPeca::excluirPeca(Codigo identificador){
    ContainerPeca *container;
    container = ContainerPeca::getInstancia();
    bool existe = false;
    existe = container->remover(identificador);
    if(existe){
        return true;
    }else{
        return false;
    }
 }

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
bool CntrServicoPeca::listarSala(){
    ContainerSala *container;
    container = ContainerSala::getInstancia();
    container->listar();
    return true;
}

bool CntrServicoPeca::cadastrarSala(Sala sala){
    bool jaExiste = false;
    ContainerSala *container;
    container = ContainerSala::getInstancia();
    jaExiste = container->pesquisar(&sala);
    if(jaExiste == true){
        return false;
    }

    jaExiste = container->cadastrar(sala);
    if(jaExiste){
        return true;
    }else{
        return false;
    }
}

bool CntrServicoPeca::editarSala(Sala sala){
    ContainerSala *container;
    container = ContainerSala::getInstancia();
    bool existe = false;
    existe = container->pesquisar(&sala);
    if(!existe){
        return false;
    }
    existe = false;
    existe = container->editar(sala);
    if(existe){
        return true;
    }
    return false;
}

Sala CntrServicoPeca::consultarSala(Sala sala){
    ContainerSala *container;
    container = ContainerSala::getInstancia();
    bool existe = false;
    existe = container->pesquisar(&sala);
    Sala salaFalse;
    if(!existe){
        return salaFalse;
    }
    existe = false;
    return sala;
}

 bool CntrServicoPeca::excluirSala(Codigo identificador){
    ContainerSala *container;
    container = ContainerSala::getInstancia();
    bool existe = false;
    existe = container->remover(identificador);
    if(existe){
        return true;
    }else{
        return false;
    }
 }
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
bool CntrServicoPeca::listarSessao(){
    ContainerSessao *container;
    container = ContainerSessao::getInstancia();
    container->listar();
    return true;
}

bool CntrServicoPeca::cadastrarSessao(Sessao sessao){
    bool jaExiste = false;
    ContainerSessao *container;
    container = ContainerSessao::getInstancia();
    jaExiste = container->pesquisar(&sessao);
    if(jaExiste == true){
        return false;
    }

    jaExiste = container->cadastrar(sessao);
    if(jaExiste){
        return true;
    }else{
        return false;
    }
}

bool CntrServicoPeca::editarSessao(Sessao sessao){
    ContainerSessao *container;
    container = ContainerSessao::getInstancia();
    bool existe = false;
    existe = container->pesquisar(&sessao);
    if(!existe){
        return false;
    }
    existe = false;
    existe = container->editar(sessao);
    if(existe){
        return true;
    }
    return false;
}

Sessao CntrServicoPeca::consultarSessao(Sessao sessao){
    ContainerSessao *container;
    container = ContainerSessao::getInstancia();
    bool existe = false;
    existe = container->pesquisar(&sessao);
    Sessao sessaoFalse;
    if(!existe){
        return sessaoFalse;
    }
    existe = false;
    return sessao;
}

 bool CntrServicoPeca::excluirSessao(Codigo identificador){
    ContainerSessao *container;
    container = ContainerSessao::getInstancia();
    bool existe = false;
    existe = container->remover(identificador);
    if(existe){
        return true;
    }else{
        return false;
    }
 }
