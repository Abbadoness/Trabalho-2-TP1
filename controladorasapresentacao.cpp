#include "controladorasapresentacao.h"
#include "controladorasservico.h"
#include "containers.h"

void CntrApresentacaoControle::executar(){

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar participante.";
    char texto4[]="3 - Acessar dados sobre pecas.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de participantes.";
    char texto8[]="2 - Selecionar servicos de pecas.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";

    int campo;

    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getch() - 48;

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&matricula)){
                        bool apresentar = true;
                        while(apresentar){
                            CLR_SCR;

                            cout << texto6 << endl;
                            cout << texto7 << endl;
                            cout << texto8 << endl;
                            cout << texto9 << endl;

                            campo = getch() - 48;

                            switch(campo){
                                case 1: cntrApresentacaoParticipante->executar(matricula);
                                        break;
                                case 2: cntrApresentacaoPeca->executar(matricula);
                                        break;
                                case 3: apresentar = false;
                                        break;
                            }
                        }
            }
            else {
                CLR_SCR;
                cout << texto10 << endl;
                getch();
            }
                break;
            case 2: cntrApresentacaoParticipante->cadastrar();
                    break;
            case 3: cntrApresentacaoPeca->executar();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return;
}

bool CntrApresentacaoAutenticacao::autenticar(Matricula *matricula){

    char texto1[]="Digite a matricula : ";
    char texto2[]="Digite a senha : ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

   char campo1[80];
   char campo2[80];

   Senha senha;

   while(true){

        CLR_SCR;
        cin.clear();
        cout << texto1 << " ";
        cin.sync();
        cin.getline(campo1,sizeof(campo1));
        cin.sync();
        cout << texto2 << " ";
        cin.clear();
        cin.sync();
        cin.getline(campo2,sizeof(campo2));
        cin.sync();

        try{
            matricula->setValor(string(campo1));
            senha.setValor(string(campo2));
            break;
        }
        catch(invalid_argument &exp){
            CLR_SCR;
            cout << texto3 << endl;
            getch();
        }
   }
   return (cntr->autenticar(*matricula, senha));
}

void CntrApresentacaoParticipante::executar(Matricula matricula){

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Editar Participante.";
    char textoX[]="2 - Excluir Participante.";
    char textoY[]="3 - Mostrar dados.";
    char texto3[]="4 - Retornar.";

    char campo1[80], campo2[80], campo3[350], campo4[80];
    char campo5[80], campo6[80];
    int campo;
    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << textoX << endl;
        cout << textoY << endl;
        cout << texto3 << endl;

        campo = getch() - 48;

        switch(campo){
            case 1:
            {

                    Nome nome;
                    Nome sobrenome;
                    Email email;
                    Telefone telefone;
                    Senha senha;
                    Cargo cargo;

                    CLR_SCR;
                    char texto4[]="Preencha os seguintes campos com as altercoes desejadas: ";
                    char texto5[]="Nome               :";
                    char texto6[]="Sobrenome          :";
                    char texto7[]="Email              :";
                    char texto8[]="Telefone           :";
                    char texto9[]="Senha              :";
                    char texto10[]="Cargo              :";

                    cout << texto4 << endl;

                    cout << texto5 << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo1,sizeof(campo1));
                    cin.sync();

                    cout << texto6 << " ";
                    cin.clear();
                    cin.getline(campo2,sizeof(campo2));
                    cin.sync();

                    cout << texto7 << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo3,sizeof(campo3));
                    cin.sync();

                    cout << texto8 << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo4,sizeof(campo4));
                    cin.sync();

                    cout << texto9 << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo5,sizeof(campo5));
                    cin.sync();

                    cout << texto10 << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo6,sizeof(campo6));
                    cin.sync();


                    try{
                        nome.setValor(string(campo1));
                        sobrenome.setValor(string(campo2));
                        email.setValor(string(campo3));
                        telefone.setValor(string(campo4));
                        senha.setValor(string(campo5));
                        cargo.setValor(string(campo6));
                    }
                    catch(invalid_argument &exp){
                        cout << "Dados em formato incorreto. Digite algo" << endl;
                        getch();
                        return;
                    }

                    Participante participante;

                    participante.setMatricula(matricula);
                    participante.setNome(nome);
                    participante.setSobrenome(sobrenome);
                    participante.setEmail(email);
                    participante.setTelefone(telefone);
                    participante.setSenha(senha);
                    participante.setCargo(cargo);

                    if(cntrServicoParticipante->editarParticipante(participante)){
                        cout << "Sucesso na edicao." << endl;
                        getch();
                        return;
                    }

                    cout << "Falha na edicao." << endl;
                    getch();
                    break;
            }
            case 2:
                {
                    if(cntrServicoParticipante->excluirParticipanteM(matricula)){
                        cout << "Sucesso na exclusao." << endl;
                        getch();
                        return;
                    }
                    cout << "Falha na exclusao." << endl;
                }
                break;

            case 3:
                {
                    if(cntrServicoParticipante->mostrar(matricula)){
                        cout << "\nDados mostrados com sucesso." << endl;
                        getch();
                        return;
                    }
                    cout << "Falha em exibir dados do participante." << endl;
                }
            case 4:
                apresentar = false;
                break;
        }
    }
}

void CntrApresentacaoParticipante::cadastrar(){

    char texto1[]="Preencha os seguintes campos: ";
    char texto2[]="Matricula          :";
    char texto3[]="Nome               :";
    char texto4[]="Sobrenome          :";
    char texto5[]="Email              :";
    char texto6[]="Telefone           :";
    char texto7[]="Senha              :";
    char texto8[]="Cargo              :";
    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite Algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[350];
    char campo5[80], campo6[80], campo7[80];

    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo1,sizeof(campo1));
    cin.sync();

    cout << "Valor lido: " << campo1 << endl;

    cout << texto3 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo2,sizeof(campo2));
    cin.sync();

    cout << "" <<endl;

    cout << texto4 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo3,sizeof(campo3));
    cin.sync();

    cout << texto5 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo4,sizeof(campo4));
    cin.sync();

    cout << texto6 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo5,sizeof(campo5));
    cin.sync();

    cout << texto7 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo6,sizeof(campo6));
    cin.sync();

    cout << texto8 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo7,sizeof(campo7));
    cin.sync();


    try{
        matricula.setValor(string(campo1));
        nome.setValor(string(campo2));
        sobrenome.setValor(string(campo3));
        email.setValor(string(campo4));
        telefone.setValor(string(campo5));
        senha.setValor(string(campo6));
        cargo.setValor(string(campo7));
    }
    catch(invalid_argument &exp){
        cout << texto10 << endl;
        getch();
        return;
    }

    Participante participante;

    participante.setMatricula(matricula);
    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    participante.setCargo(cargo);

    if(cntrServicoParticipante->cadastrarParticipante(participante)){
        cout << texto11 << endl;
        getch();
        return;
    }

    cout << texto12 << endl;
    getch();

    return;
}

void CntrApresentacaoPeca::executar(){
    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar pecas.";
    char texto3[]="2 - Consultar sessao.";
    char texto4[]="3 - Consultar salas.";
    char texto5[]="4 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getch() - 48;

        switch(campo){
            case 1:
                {
                    bool consultarPeca();
                    break;
                }
            case 2:
                {
                    bool consultarSessao();
                    break;
                }
            case 3:
                {
                    bool consultarSala();
                    break;
                }
            case 4: apresentar = false;
                    break;
        }
    }
}

void CntrApresentacaoPeca::executar(Matricula){

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Consultar pecas.";
    char texto3[] ="2 - Cadastrar peca.";
    char texto4[] ="3 - Editar peca.";
    char texto5[] ="4 - Excluir peca.";
    char texto6[] ="5 - Consultar sessoes.";
    char texto7[] ="6 - Cadastrar sessao.";
    char texto8[] ="7 - Editar sessao.";
    char texto9[] ="8 - Excluir sessao.";
    char texto10[] ="9 - Consultar salas.";
    char texto11[] ="10 - Cadastrar sala.";
    char texto12[] ="11 - Editar sala.";
    char texto13[] ="12 - Excluir sala.";
    char texto14[] ="13 - Retornar.";

    char campo1[80], campo2[80], campo3[80], campo4[80];


    int campo;
    CntrServicoPeca *cntr;

    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;
        cout << texto7 << endl;
        cout << texto8 << endl;
        cout << texto9 << endl;
        cout << texto10 << endl;
        cout << texto11 << endl;
        cout << texto12 << endl;
        cout << texto13 << endl;
        cout << texto14 << endl;
        cout << "Digite o numero da sua escolha: ";
        cin.clear();
        cin.sync();
        cin >> campo;
        cin.clear();
        cin.sync();

        switch(campo){
            case 1: consultarPeca();
                    break;
            case 2: cadastrarPeca();
                    break;
            case 3:
                {

                    Codigo identificador;
                    Nome nome;
                    Tipo tipo;
                    Classificacao classificacao;

                    CLR_SCR;
                    char textoA[]="Preencha os seguintes campos com as altercoes desejadas: ";
                    char textoB[]="Identificador      :";
                    char textoC[]="Nome               :";
                    char textoD[]="Tipo               :";
                    char textoE[]="Classificacao      :";

                    cout << textoA << endl;
                    cout << textoB << " ";

                    cin.clear();
                    cin.getline(campo1,sizeof(campo1));
                    cin.sync();

                    cout << textoC << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo2,sizeof(campo2));
                    cin.sync();

                    cout << textoD << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo3,sizeof(campo3));
                    cin.sync();


                    cout << textoE << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo4,sizeof(campo4));
                    cin.sync();

                    try{
                        identificador.setValor(string(campo1));
                        nome.setValor(string(campo2));
                        tipo.setValor(string(campo3));
                        classificacao.setValor(string(campo4));
                    }
                    catch(invalid_argument &exp){
                        cout << "Dados em formato incorreto. Digite algo" << endl;
                        getch();
                        return;
                    }

                    Peca peca;

                    peca.setIdentificador(identificador);
                    peca.setNome(nome);
                    peca.setTipo(tipo);
                    peca.setClassificacao(classificacao);

                    if(cntr->editarPeca(peca)){
                        cout << "Sucesso na edicao." << endl;
                        getch();
                        return;
                    }

                    cout << "Falha na edicao." << endl;
                    getch();
                    break;

                }
            case 4:
                {
                    cout << "Digite o identificador da peca: ";


                    cin.clear();
                    cin.sync();
                    cin.getline(campo1,sizeof(campo1));
                    cin.sync();

                    Codigo codigo;
                    codigo.setValor(campo1);
                    if(cntr->excluirPeca(codigo)){
                        cout << "Sucesso na exclusao." << endl;
                        getch();
                        return;
                    }
                    cout << "Falha na exclusao." << endl;
                    break;
                }
            case 5: consultarSessao();
                    break;
            case 6: cadastrarSessao();
                    break;
            case 7:
                {

                    Codigo identificador;
                    Data data;
                    Horario horario;

                    CLR_SCR;
                    char textoA1[]="Preencha os seguintes campos com as altercoes desejadas: ";
                    char textoB2[]="Identificador      :";
                    char textoC3[]="Data               :";
                    char textoD4[]="Horario            :";

                    cout << textoA1 << endl;
                    cout << textoB2 << " ";

                    cin.clear();
                    cin.sync();
                    cin.getline(campo1,sizeof(campo1));
                    cin.sync();

                    cout << textoC3 << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo2,sizeof(campo2));
                    cin.sync();

                    cout << textoD4 << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo3,sizeof(campo3));
                    cin.sync();


                    try{
                        identificador.setValor(string(campo1));
                        data.setValor(string(campo2));
                        horario.setValor(string(campo3));
                    }
                    catch(invalid_argument &exp){
                        cout << "Dados em formato incorreto. Digite algo" << endl;
                        getch();
                        return;
                    }

                    Sessao sessao;

                    sessao.setIdentificador(identificador);
                    sessao.setData(data);
                    sessao.setHorario(horario);

                    if(cntr->editarSessao(sessao)){
                        cout << "Sucesso na edicao." << endl;
                        getch();
                        return;
                    }

                    cout << "Falha na edicao." << endl;
                    getch();
                    break;

                }
            case 8:
                 {
                    cout << "Digite o identificador da sessao: ";

                    cin.clear();
                    cin.sync();
                    cin.getline(campo1,sizeof(campo1));
                    cin.sync();

                    Codigo codigo;
                    codigo.setValor(campo1);
                    if(cntr->excluirSessao(codigo)){
                        cout << "Sucesso na exclusao." << endl;
                        getch();
                        return;
                    }
                    cout << "Falha na exclusao." << endl;
                    break;
                }
            case 9: consultarSala();
                    break;
            case 10: cadastrarSala();
                    break;
            case 11:
                   {

                    Codigo identificador;
                    Nome nome;
                    Capacidade capacidade;

                    CLR_SCR;
                    char textoA1[]="Preencha os seguintes campos com as altercoes desejadas: ";
                    char textoB2[]="Identificador      :";
                    char textoC3[]="Nome               :";
                    char textoD4[]="Capacidade         :";

                    cout << textoA1 << endl;
                    cout << textoB2 << " ";

                    cin.clear();
                    cin.sync();
                    cin.getline(campo1,sizeof(campo1));
                    cin.sync();

                    cout << textoC3 << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo2,sizeof(campo2));
                    cin.sync();

                    cout << textoD4 << " ";
                    cin.clear();
                    cin.sync();
                    cin.getline(campo3,sizeof(campo3));
                    cin.sync();




                    try{
                        identificador.setValor(string(campo1));
                        nome.setValor(string(campo2));
                        capacidade.setValor(string(campo3));
                    }
                    catch(invalid_argument &exp){
                        cout << "Dados em formato incorreto. Digite algo" << endl;
                        getch();
                        return;
                    }

                    Sala sala;

                    sala.setIdentificador(identificador);
                    sala.setNome(nome);
                    sala.setCapacidade(capacidade);

                    if(cntr->editarSala(sala)){
                        cout << "Sucesso na edicao." << endl;
                        getch();
                        return;
                    }

                    cout << "Falha na edicao." << endl;
                    getch();
                    break;
                }
            case 12:
                 {
                    cout << "Digite o identificador da sala: ";

                    cin.clear();
                    cin.sync();
                    cin.getline(campo1,sizeof(campo1));
                    cin.sync();

                    Codigo codigo;
                    codigo.setValor(campo1);
                    if(cntr->excluirSala(codigo)){
                        cout << "Sucesso na exclusao." << endl;
                        getch();
                        return;
                    }
                    cout << "Falha na exclusao." << endl;
                    break;
                }
            case 13: apresentar = false;
                    break;
        }
    }
}

void CntrApresentacaoPeca::consultarPeca(){

    CLR_SCR;
    ContainerPeca *cntrServicoPeca;
    cntrServicoPeca = ContainerPeca::getInstancia();
    cntrServicoPeca->listar();
    getch();

}

void CntrApresentacaoPeca::cadastrarPeca(){
    char texto1[]="Preencha os seguintes campos: ";
    char texto2[]="Identificador      :";
    char texto3[]="Nome               :";
    char texto4[]="Tipo               :";
    char texto5[]="Classificacao      :";

    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite Algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];

    Codigo identificador;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;

    CLR_SCR;

    cout << texto1 << "\n";
    cout << texto2;

    cin.clear();
    cin.sync();
    cin.getline(campo1,sizeof(campo1));
    cin.sync();

    cout << texto3;

    cin.clear();
    cin.sync();
    cin.getline(campo2,sizeof(campo2));
    cin.sync();

    cout << texto4;
    cin.clear();
    cin.sync();
    cin.getline(campo3,sizeof(campo3));
    cin.sync();

    cout << texto5;
    cin.clear();
    cin.sync();
    cin.getline(campo4,sizeof(campo4));
    cin.sync();


    try{
        identificador.setValor(string(campo1));
        nome.setValor(string(campo2));
        tipo.setValor(string(campo3));
        classificacao.setValor(string(campo4));
    }
    catch(invalid_argument &exp){
        cout << texto10 << endl;
        getch();
        return;
    }

    Peca peca;

    peca.setIdentificador(identificador);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);

    ContainerPeca *cntrServicoPeca;
    cntrServicoPeca = ContainerPeca::getInstancia();
    if(cntrServicoPeca->cadastrar(peca)){
        cout << texto11 << endl;
        getch();
        return;
    }

    cout << texto12 << endl;
    getch();
}

void CntrApresentacaoPeca::consultarSessao(){

    CLR_SCR;
    ContainerSessao *cntrServicoSessao;
    cntrServicoSessao = ContainerSessao::getInstancia();
    cntrServicoSessao->listar();
    getch();

}

void CntrApresentacaoPeca::cadastrarSessao(){

    char texto1[]="Preencha os seguintes campos: ";
    char texto2[]="Identificador      :";
    char texto3[]="Data               :";
    char texto4[]="Horario            :";

    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite Algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80];

    Codigo identificador;
    Data data;
    Horario horario;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo1,sizeof(campo1));
    cin.sync();

    cout << "Valor lido" << campo1 << " ";

    cout << texto3 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo2,sizeof(campo2));
    cin.sync();

    cout << texto4 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo3,sizeof(campo3));
    cin.sync();

    try{
        identificador.setValor(string(campo1));
        data.setValor(string(campo2));
        horario.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        cout << texto10 << endl;
        getch();
        return;
    }

    Sessao sessao;

    sessao.setIdentificador(identificador);
    sessao.setData(data);
    sessao.setHorario(horario);

    ContainerSessao *cntrServicoSessao;
    cntrServicoSessao = ContainerSessao::getInstancia();
    if(cntrServicoSessao->cadastrar(sessao)){
        cout << texto11 << endl;
        getch();
        return;
    }

    cout << texto12 << endl;
    getch();
}

void CntrApresentacaoPeca::consultarSala(){

    ContainerSala *cntrServicoSala;
    cntrServicoSala = ContainerSala::getInstancia();
    CLR_SCR;
    cntrServicoSala->listar();
    getch();
}

void CntrApresentacaoPeca::cadastrarSala(){

    char texto1[]="Preencha os seguintes campos: ";
    char texto2[]="Identificador      :";
    char texto3[]="Nome               :";
    char texto4[]="Capacidade         :";

    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite Algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80];

    Codigo identificador;
    Nome nome;
    Capacidade capacidade;

    CLR_SCR;

    cout << texto1 << endl;
    cout << texto2 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo1,sizeof(campo1));
    cin.sync();

    cout << "Valor lido" << campo1 << " ";

    cout << texto3 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo2,sizeof(campo2));
    cin.sync();

    cout << texto4 << " ";

    cin.clear();
    cin.sync();
    cin.getline(campo3,sizeof(campo3));
    cin.sync();


    try{
        identificador.setValor(string(campo1));
        nome.setValor(string(campo2));
        capacidade.setValor(string(campo3));
    }
    catch(invalid_argument &exp){
        cout << texto10 << endl;
        getch();
        return;
    }

    Sala sala;

    sala.setIdentificador(identificador);
    sala.setNome(nome);
    sala.setCapacidade(capacidade);

    ContainerSala *cntrServicoSala;
    cntrServicoSala = ContainerSala::getInstancia();
    if(cntrServicoSala->cadastrar(sala)){
        cout << texto11 << endl;
        getch();
        return;
    }

    cout << texto12 << endl;
    getch();
}
