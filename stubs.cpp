#include "stubs.h"

const string StubServicoAutenticacao::INVALIDO = "01123";
const string StubServicoParticipante::INVALIDO = "01123";
const string StubServicoPeca::INVALIDO = "aaBBBB";

bool StubServicoAutenticacao::autenticar(Matricula matricula,Senha senha){
    if(matricula.getValor().compare(INVALIDO) == 0){
        return false;
    }
    return true;
}

bool StubServicoParticipante::cadastrarParticipante(Participante participante){
    if(participante.getMatricula().getValor().compare(INVALIDO) == 0){
        return false;
    }
    return true;
}

bool StubServicoPeca::cadastrarPeca(Peca peca){
    if(peca.getIdentificador().getValor().compare(INVALIDO) == 0){
        return false;
    }
    return true;
}

bool StubServicoPeca::consultarPeca(Peca *peca){
    if(peca->getIdentificador().getValor().compare(INVALIDO) == 0){
        return false;
    }
    return true;
}
