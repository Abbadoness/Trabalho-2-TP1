#include <string.h>
#include <stdexcept>
#include <iostream>

#include "dominios.h"
#include "intefaces.h"
#include "controladorasapresentacao.h"
#include "controladorasservico.h"
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

    IServicoAutenticacao *cntrServicoAutenticacao;
    IServicoParticipante *cntrServicoParticipante;
    IServicoPeca *cntrServicoPeca;

    cntrServicoAutenticacao = new CntrServicoAutenticacao();
    cntrServicoParticipante = new CntrServicoParticipante();
    cntrServicoPeca = new CntrServicoPeca();

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoParticipante(cntrApresentacaoParticipante);
    cntrApresentacaoControle->setCntrApresentacaoPeca(cntrApresentacaoPeca);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoParticipante->setCntrServicoParticipante(cntrServicoParticipante);
    cntrApresentacaoPeca->setCntrServicoPeca(cntrServicoPeca);

    cntrApresentacaoControle->executar();

    return 0;
}
