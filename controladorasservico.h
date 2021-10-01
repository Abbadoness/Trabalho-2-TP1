#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "intefaces.h"

class CntrServicoAutenticacao:public IServicoAutenticacao{
public:
    virtual bool autenticar(Matricula, Senha);
};

class CntrServicoParticipante:public IServicoParticipante{
};

class CntrServicoPeca:public IServicoPeca{
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
