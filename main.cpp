#include <string.h>
#include <stdexcept>
#include <iostream>

#include "dominios.h"
#include "intefaces.h"
#include "controladorasapresentacao.h"
#include "stubs.h"

using namespace std;

int main()
{
    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoParticipante *cntrApresentacaoParticipante;
    IApresentacaoPeca *cntrApresentacaoPeca;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoParticipante = new CntrApresentacaoParticipante();
    cntrApresentacaoPeca = new CntrApresentacaoPeca();

    IServicoAutenticacao *stubServicoAutenticacao;
    IServicoParticipante *stubServicoParticipante;
    IServicoPeca *stubServicoPeca;

    stubServicoAutenticacao = new StubServicoAutenticacao();
    stubServicoParticipante = new StubServicoParticipante();
    stubServicoPeca = new StubServicoPeca();

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoParticipante(cntrApresentacaoParticipante);
    cntrApresentacaoControle->setCntrApresentacaoPeca(cntrApresentacaoPeca);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

    cntrApresentacaoParticipante->setCntrServicoParticipante(stubServicoParticipante);


    cntrApresentacaoPeca->setCntrServicoPeca(stubServicoPeca);

    cntrApresentacaoControle->executar();

    return 0;
}
