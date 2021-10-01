#include "controladorasapresentacao.h"

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

        cout << texto1 << " ";
        cin >> campo1;
        cout << texto2 << " ";
        cin >> campo2;

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
    char texto2[]="1 - Consultar dados pessoais.";
    char texto3[]="2 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;

        campo = getch() - 48;

        switch(campo){
            case 1: consultarDadosPessoais();
                    break;
            case 2: apresentar = false;
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

    char campo1[80], campo2[80], campo3[80], campo4[80];
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
    cin.getline(campo1,sizeof(campo1));

    cout << "Valor lido" << campo1 << " ";

    cout << texto3 << " ";
    cin >> campo2;
    cout << texto4 << " ";
    cin >> campo3;
    cout << texto5 << " ";
    cin >> campo4;
    cout << texto6 << " ";
    cin >> campo5;
    cout << texto7 << " ";
    cin >> campo6;
    cout << texto8 << " ";
    cin >> campo7;

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

void CntrApresentacaoParticipante::consultarDadosPessoais(){

    char texto[]="Servico consultar dados nao implementado. Digite algo.";
    CLR_SCR;
    cout << texto << endl;
    getch();
}

void CntrApresentacaoPeca::executar(){
    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar pecas.";
    char texto3[]="2 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;

        campo = getch() - 48;

        switch(campo){
            case 1: consultarPeca();
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
}

void CntrApresentacaoPeca::executar(Matricula){

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Consultar peca.";
    char texto3[] ="2 - Cadastrar peca.";
    char texto4[] ="3 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar){

        CLR_SCR;

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;

        campo = getch() - 48;

        switch(campo){
            case 1: consultarPeca();
                    break;
            case 2: cadastrarPeca();
                    break;
            case 3: apresentar = false;
                    break;
        }
    }
}

void CntrApresentacaoPeca::consultarPeca(){

    char texto[]="Servico consultar peca nao implementado. Digite algo.";

    CLR_SCR;
    cout << texto << endl;
    getch();
}

void CntrApresentacaoPeca::cadastrarPeca(){
    char texto[]="Servico cadastrar peca nao implementado. Digite algo.";

    CLR_SCR;
    cout << texto << endl;
    getch();
}
