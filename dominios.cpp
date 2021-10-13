#include "dominios.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>

void Capacidade::validar(string capacidade){
    vector <string> validos;
    validos.push_back("100");
    validos.push_back("200");
    validos.push_back("300");
    validos.push_back("400");
    validos.push_back("500");
    int flagEncontrou = 0;
    int tamanho = validos.size();
    for(int i = 0; i < tamanho; i++){
        if(validos[i] == capacidade){
            flagEncontrou = 1;
        }
    }
    if(flagEncontrou != 1){
        throw invalid_argument("Argumento invalido.");
    }
}

void Capacidade::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Cargo::validar(string cargo){
    vector <string> validos;
    validos.push_back("ator");
    validos.push_back("cenógrafo");
    validos.push_back("figurinista");
    validos.push_back("maquiador");
    validos.push_back("sonoplasta");
    validos.push_back("iluminador");
    int flagEncontrou = 0;
    int tamanho = validos.size();
    for(int i = 0; i < tamanho; i++){
        if(validos[i] == cargo){
            flagEncontrou = 1;
        }
    }
    if(flagEncontrou != 1){
        throw invalid_argument("Argumento invalido.");
    }
}

void Cargo::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Classificacao::validar(string classificacao){
    vector <string> validos;
    validos.push_back("livre");
    validos.push_back("10");
    validos.push_back("12");
    validos.push_back("14");
    validos.push_back("16");
    validos.push_back("18");
    int flagEncontrou = 0;
    int tamanho = validos.size();
    for(int i = 0; i < tamanho; i++){
        if(validos[i] == classificacao){
            flagEncontrou = 1;
        }
    }
    if(flagEncontrou != 1){
        throw invalid_argument("Argumento invalido.");
    }
}

void Classificacao::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Tipo::validar(string tipo){
    vector <string> validos;
    validos.push_back("auto");
    validos.push_back("comédia");
    validos.push_back("drama");
    validos.push_back("farsa");
    validos.push_back("melodrama");
    validos.push_back("monólogo");
    validos.push_back("musical");
    validos.push_back("ópera");
    validos.push_back("revista");
    int flagEncontrou = 0;
    int tamanho = validos.size();
    for(int i = 0; i < tamanho; i++){
        if(validos[i] == tipo){
            flagEncontrou = 1;
        }
    }
    if(flagEncontrou != 1){
        throw invalid_argument("Argumento invalido.");
    }
}

void Tipo::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Codigo::validar(string codigo){
    vector <string> LetrasMaiusculas;
    LetrasMaiusculas.push_back("A");LetrasMaiusculas.push_back("B");LetrasMaiusculas.push_back("C");LetrasMaiusculas.push_back("D");LetrasMaiusculas.push_back("E");LetrasMaiusculas.push_back("F");LetrasMaiusculas.push_back("G");LetrasMaiusculas.push_back("H");LetrasMaiusculas.push_back("I");LetrasMaiusculas.push_back("J");LetrasMaiusculas.push_back("K");LetrasMaiusculas.push_back("L");LetrasMaiusculas.push_back("M");LetrasMaiusculas.push_back("N");LetrasMaiusculas.push_back("O");LetrasMaiusculas.push_back("P");LetrasMaiusculas.push_back("Q");LetrasMaiusculas.push_back("R");LetrasMaiusculas.push_back("S");LetrasMaiusculas.push_back("T");LetrasMaiusculas.push_back("U");LetrasMaiusculas.push_back("V");LetrasMaiusculas.push_back("W");LetrasMaiusculas.push_back("X");LetrasMaiusculas.push_back("Y");LetrasMaiusculas.push_back("Z");
    vector <string> Digitos;
    Digitos.push_back("0");Digitos.push_back("1");Digitos.push_back("2");Digitos.push_back("3");Digitos.push_back("4");Digitos.push_back("5");Digitos.push_back("6");Digitos.push_back("7");Digitos.push_back("8");Digitos.push_back("9");
    string Primeira_Letra;Primeira_Letra = codigo[0];
    string Segunda_Letra;Segunda_Letra = codigo[1];
    string Primeiro_Digito;Primeiro_Digito = codigo[2];
    string Segundo_Digito;Segundo_Digito = codigo[3];
    string Terceiro_Digito;Terceiro_Digito = codigo[4];
    string Quarto_Digito;Quarto_Digito = codigo[5];
    int flag_primeiraLetra = 0;
    int flag_segundaLetra = 0;
    int flag_digitos = 0;
    int tamanho = LetrasMaiusculas.size();
    for(int i=0; i < tamanho;i++){
        if(Primeira_Letra == LetrasMaiusculas[i]){
            flag_primeiraLetra = 1;
        }
        if(Segunda_Letra == LetrasMaiusculas[i]){
            flag_segundaLetra = 1;
        }
        if((flag_primeiraLetra == 1) && (flag_segundaLetra == 1)){
            break;
        }
    }
    if((flag_primeiraLetra != 1) && (flag_segundaLetra != 1)){
        throw invalid_argument("Argumento invalido.");
    }

    for(int i = 0; i < 10; i++){
        if(Primeiro_Digito == Digitos[i]){
            flag_digitos++;
        }
        if(Segundo_Digito == Digitos[i]){
            flag_digitos++;
        }
        if(Terceiro_Digito == Digitos[i]){
            flag_digitos++;
        }
        if(Quarto_Digito == Digitos[i]){
            flag_digitos++;
        }
        if(flag_digitos == 4){
            break;
        }

    }
    if(flag_digitos != 4){
        throw invalid_argument("Argumento invalido.");
    }

}

void Codigo::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Horario::validar(string horario){
    string aux;
    aux = horario;
    aux.erase(2,3);
    int hora = std::stoi(aux);
    aux = horario;
    aux.erase(0,3);
    int minutos = std::stoi(aux);

    if(!((0 <= hora) && (hora <= 23))){
        throw invalid_argument("Argumento invalido.");
    }

    switch(minutos){
    case(0):
        break;
    case(15):
        break;
    case(30):
        break;
    case(45):
        break;
    default:
        throw invalid_argument("Argumento invalido.");
    }
}

void Horario::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Matricula::validar(string matricula){
    for(int i = 0; i < 5;i++){
        if(!((matricula[i] == '0')||(matricula[i] == '1')||(matricula[i] == '2')||(matricula[i] == '3')||(matricula[i] == '4')||(matricula[i] == '5')||(matricula[i] == '6')||(matricula[i] == '7')||(matricula[i] == '8')||(matricula[i] == '9'))){
            throw invalid_argument("Argumento invalido.");
        }
    }

    for(int i = 0; i < 5;i++){
        for(int j = i+1; j < 5;j++){
            if(matricula[i] == matricula[j]){
                throw invalid_argument("Argumento invalido.");
            }
        }
    }
}

void Matricula::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Nome::validar(string nome){
    int tamanho = nome.size();
    if((tamanho <= 5)||(20 <= tamanho)){
        throw invalid_argument("Argumento invalido.");
    }

    vector <char> Caracteres_validos;
    Caracteres_validos.push_back('a');
    Caracteres_validos.push_back('b');
    Caracteres_validos.push_back('c');
    Caracteres_validos.push_back('d');
    Caracteres_validos.push_back('e');
    Caracteres_validos.push_back('f');
    Caracteres_validos.push_back('g');
    Caracteres_validos.push_back('h');
    Caracteres_validos.push_back('i');
    Caracteres_validos.push_back('j');
    Caracteres_validos.push_back('k');
    Caracteres_validos.push_back('l');
    Caracteres_validos.push_back('m');
    Caracteres_validos.push_back('n');
    Caracteres_validos.push_back('o');
    Caracteres_validos.push_back('p');
    Caracteres_validos.push_back('q');
    Caracteres_validos.push_back('r');
    Caracteres_validos.push_back('s');
    Caracteres_validos.push_back('t');
    Caracteres_validos.push_back('u');
    Caracteres_validos.push_back('v');
    Caracteres_validos.push_back('w');
    Caracteres_validos.push_back('x');
    Caracteres_validos.push_back('y');
    Caracteres_validos.push_back('z');
    Caracteres_validos.push_back('A');
    Caracteres_validos.push_back('B');
    Caracteres_validos.push_back('C');
    Caracteres_validos.push_back('D');
    Caracteres_validos.push_back('E');
    Caracteres_validos.push_back('F');
    Caracteres_validos.push_back('G');
    Caracteres_validos.push_back('H');
    Caracteres_validos.push_back('I');
    Caracteres_validos.push_back('J');
    Caracteres_validos.push_back('K');
    Caracteres_validos.push_back('L');
    Caracteres_validos.push_back('M');
    Caracteres_validos.push_back('N');
    Caracteres_validos.push_back('O');
    Caracteres_validos.push_back('P');
    Caracteres_validos.push_back('Q');
    Caracteres_validos.push_back('R');
    Caracteres_validos.push_back('S');
    Caracteres_validos.push_back('T');
    Caracteres_validos.push_back('U');
    Caracteres_validos.push_back('V');
    Caracteres_validos.push_back('W');
    Caracteres_validos.push_back('X');
    Caracteres_validos.push_back('Y');
    Caracteres_validos.push_back('Z');

    vector <char> Caracteres_M;
    Caracteres_M.push_back('A');
    Caracteres_M.push_back('B');
    Caracteres_M.push_back('C');
    Caracteres_M.push_back('D');
    Caracteres_M.push_back('E');
    Caracteres_M.push_back('F');
    Caracteres_M.push_back('G');
    Caracteres_M.push_back('H');
    Caracteres_M.push_back('I');
    Caracteres_M.push_back('J');
    Caracteres_M.push_back('K');
    Caracteres_M.push_back('L');
    Caracteres_M.push_back('M');
    Caracteres_M.push_back('N');
    Caracteres_M.push_back('O');
    Caracteres_M.push_back('P');
    Caracteres_M.push_back('Q');
    Caracteres_M.push_back('R');
    Caracteres_M.push_back('S');
    Caracteres_M.push_back('T');
    Caracteres_M.push_back('U');
    Caracteres_M.push_back('V');
    Caracteres_M.push_back('W');
    Caracteres_M.push_back('X');
    Caracteres_M.push_back('Y');
    Caracteres_M.push_back('Z');

    int tamanhoM = Caracteres_M.size();

    for(int i = 0; i < tamanho; i++){
        if(nome[i] == '.'){
            if(i == 0){
                throw invalid_argument("Argumento invalido.");
            }else{
                int flag_letra = 0;
                for(int j = 0; j < tamanho; j++){
                    if((nome[i-1] == Caracteres_validos[j])){
                        flag_letra++;
                    }
                }
                if(flag_letra == 0){
                    throw invalid_argument("Argumento invalido.");
                }
            }
        }

        if(nome[i] == ' '){
            if((i != 0)&&(i != tamanho-1)){
                if((nome[i+1] == ' ')||(nome[i-1] == ' ')){
                    throw invalid_argument("Argumento invalido.");
                }

                int flag_LETRA = 0;
                for(int j = 0; j < tamanhoM; j++){
                    if((nome[i+1] == Caracteres_M[j])){
                        flag_LETRA++;
                    }
                }
                if(flag_LETRA == 0){
                    throw invalid_argument("Argumento invalido.");
                }
            }
        }
    }
}

void Nome::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Senha::validar(string senha){

    int tamanho_senha = senha.size();
    if(tamanho_senha != 8){
        throw invalid_argument("Argumento invalido.");
    }


    vector <char> Letras;
    Letras.push_back('a');
    Letras.push_back('b');
    Letras.push_back('c');
    Letras.push_back('d');
    Letras.push_back('e');
    Letras.push_back('f');
    Letras.push_back('g');
    Letras.push_back('h');
    Letras.push_back('i');
    Letras.push_back('j');
    Letras.push_back('k');
    Letras.push_back('l');
    Letras.push_back('m');
    Letras.push_back('n');
    Letras.push_back('o');
    Letras.push_back('p');
    Letras.push_back('q');
    Letras.push_back('r');
    Letras.push_back('s');
    Letras.push_back('t');
    Letras.push_back('u');
    Letras.push_back('v');
    Letras.push_back('w');
    Letras.push_back('x');
    Letras.push_back('y');
    Letras.push_back('z');
    Letras.push_back('A');
    Letras.push_back('B');
    Letras.push_back('C');
    Letras.push_back('D');
    Letras.push_back('E');
    Letras.push_back('F');
    Letras.push_back('G');
    Letras.push_back('H');
    Letras.push_back('I');
    Letras.push_back('J');
    Letras.push_back('K');
    Letras.push_back('L');
    Letras.push_back('M');
    Letras.push_back('N');
    Letras.push_back('O');
    Letras.push_back('P');
    Letras.push_back('Q');
    Letras.push_back('R');
    Letras.push_back('S');
    Letras.push_back('T');
    Letras.push_back('U');
    Letras.push_back('V');
    Letras.push_back('W');
    Letras.push_back('X');
    Letras.push_back('Y');
    Letras.push_back('Z');

    int tamanho_Letras = Letras.size();

    vector <char> Digitos;
    Digitos.push_back('0');
    Digitos.push_back('1');
    Digitos.push_back('2');
    Digitos.push_back('3');
    Digitos.push_back('4');
    Digitos.push_back('5');
    Digitos.push_back('6');
    Digitos.push_back('7');
    Digitos.push_back('8');
    Digitos.push_back('9');

    int tamanho_Digitos = Digitos.size();

    vector <char> Especiais;
    Especiais.push_back('!');
    Especiais.push_back('@');
    Especiais.push_back('#');
    Especiais.push_back('$');
    Especiais.push_back('%');
    Especiais.push_back('&');
    Especiais.push_back('?');

    int tamanho_Especiais = Especiais.size();

    int flag_letra = 0;
    int flag_digito = 0;
    int flag_especiais = 0;
    for(int i = 0; i < tamanho_senha; i++){
        for(int j = 0; j < tamanho_Letras; j++){
            if(senha[i]==Letras[j]){
                flag_letra++;
            }
        }

        for(int j = 0; j < tamanho_Digitos; j++){
            if(senha[i]==Digitos[j]){
                flag_digito++;
            }
        }

        for(int j = 0; j < tamanho_Especiais; j++){
            if(senha[i]==Especiais[j]){
                flag_especiais++;
            }
        }
    }

    if((flag_digito==0)||(flag_especiais==0)||(flag_letra==0)){
        throw invalid_argument("Argumento invalido.");
    }

    int flag_repetido = 0;
    for(int i = 0; i < tamanho_senha; i++){
        for(int j = 0; j < tamanho_senha; j++){
            if(i != j){
                if (senha[j] == senha[i]){
                    flag_repetido++;
                }
            }
        }
    }
    if(flag_repetido != 0){
        throw invalid_argument("Argumento invalido.");
    }

}

void Senha::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Telefone::validar(string telefone){

    string preFixo;
    preFixo = telefone;
    preFixo.erase(3,11);
    preFixo.erase(0,1);
    //int Pre_fixo = std::stoi(preFixo);
    string Pos_fixo;
    Pos_fixo = telefone;
    Pos_fixo.erase(0,5);
    int tamanho_posFixo = Pos_fixo.size();
    vector <string> codigo;
    codigo.push_back("11");
    codigo.push_back("12");
    codigo.push_back("13");
    codigo.push_back("14");
    codigo.push_back("15");
    codigo.push_back("16");
    codigo.push_back("17");
    codigo.push_back("18");
    codigo.push_back("19");
    codigo.push_back("21");
    codigo.push_back("22");
    codigo.push_back("24");
    codigo.push_back("27");
    codigo.push_back("28");
    codigo.push_back("32");
    codigo.push_back("33");
    codigo.push_back("34");
    codigo.push_back("35");
    codigo.push_back("37");
    codigo.push_back("38");
    codigo.push_back("41");
    codigo.push_back("42");
    codigo.push_back("43");
    codigo.push_back("44");
    codigo.push_back("45");
    codigo.push_back("46");
    codigo.push_back("47");
    codigo.push_back("48");
    codigo.push_back("49");
    codigo.push_back("51");
    codigo.push_back("53");
    codigo.push_back("54");
    codigo.push_back("55");
    codigo.push_back("61");
    codigo.push_back("62");
    codigo.push_back("63");
    codigo.push_back("64");
    codigo.push_back("65");
    codigo.push_back("66");
    codigo.push_back("67");
    codigo.push_back("68");
    codigo.push_back("69");
    codigo.push_back("71");
    codigo.push_back("73");
    codigo.push_back("74");
    codigo.push_back("75");
    codigo.push_back("77");
    codigo.push_back("79");
    codigo.push_back("81");
    codigo.push_back("82");
    codigo.push_back("83");
    codigo.push_back("84");
    codigo.push_back("85");
    codigo.push_back("86");
    codigo.push_back("87");
    codigo.push_back("88");
    codigo.push_back("89");
    codigo.push_back("91");
    codigo.push_back("92");
    codigo.push_back("93");
    codigo.push_back("94");
    codigo.push_back("95");
    codigo.push_back("96");
    codigo.push_back("97");
    codigo.push_back("98");
    codigo.push_back("99");

    if(Pos_fixo == "000000000"){
        throw invalid_argument("Argumento invalido.");
    }
    vector<char>Digitos= {'0','1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i < tamanho_posFixo; i++){
        int flag_digitos = 0;
        for(int j = 0; j <10; j++){
            if(Pos_fixo[i] == Digitos[j]){
                flag_digitos++;
            }
        }
        if(flag_digitos == 0){
            throw invalid_argument("Argumento invalido.");
        }
    }
    int tamanho_codigo = codigo.size();

    int flag_codigo = 0;
    for(int i = 0; i < tamanho_codigo; i++){
        if(preFixo == codigo[i]){
            flag_codigo++;
        }
    }
    if(flag_codigo == 0){
        throw invalid_argument("Argumento invalido.");
    }

}

void Telefone::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Data::validar(string data){
    string Dia;
    string Mes;
    string Ano;

    Dia = data;
    Dia.erase(2,8);

    Mes = data;
    Mes.erase(0,3);
    Mes.erase(2,5);

    Ano = data;
    Ano.erase(0,6);

    int dia = std::stoi(Dia);
    int mes = std::stoi(Mes);
    int ano = std::stoi(Ano);

    if((ano < 2000)||(9999 < ano)){
        throw invalid_argument("Argumento invalido.");
    }

    switch(mes){
        case(1):
            if((dia < 1)||(31 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(2):
            if(((ano % 4 == 0) && (ano % 100 != 0))||(ano % 400 == 0)){
                if((dia < 1)||(29 < dia)){
                    throw invalid_argument("Argumento invalido.");
                }
            }else{
                if((dia < 1)||(28 < dia)){
                    throw invalid_argument("Argumento invalido.");
                }
            }
            break;
        case(3):
            if((dia < 1)||(31 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(4):
            if((dia < 1)||(30 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(5):
            if((dia < 1)||(31 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(6):
            if((dia < 1)||(30 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(7):
            if((dia < 1)||(31 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(8):
            if((dia < 1)||(31 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(9):
            if((dia < 1)||(30 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(10):
            if((dia < 1)||(31 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(11):
            if((dia < 1)||(30 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        case(12):
            if((dia < 1)||(31 < dia)){
                throw invalid_argument("Argumento invalido.");
            }
            break;
        default:
            throw invalid_argument("Argumento invalido.");
        }
}

void Data::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

void Email::validar(string email){

    int posicao = 0;
    int tamanho_email = email.size();

    for(int i = 0; i < tamanho_email; i++){
        if(email[i] == '@'){
            posicao = i;
        }
    }

    if(64 < posicao+1){
        throw invalid_argument("Argumento invalido.");
    }

    string parte_local;
    string dominio;
    parte_local = email;
    dominio = email;
    dominio.erase(0,posicao+1);
    int tamanho_dominio = dominio.size();
    if(255 < tamanho_dominio){
        throw invalid_argument("Argumento invalido.");
    }
    parte_local.erase(posicao,tamanho_dominio+1);
    int tamanho_parteLocal = parte_local.size();
    if(64 < tamanho_parteLocal){
        throw invalid_argument("Argumento invalido.");
    }

    vector <char> Caracteres_validos;
    Caracteres_validos.push_back('a');Caracteres_validos.push_back('b');Caracteres_validos.push_back('c');Caracteres_validos.push_back('d');Caracteres_validos.push_back('e');Caracteres_validos.push_back('f');Caracteres_validos.push_back('g');Caracteres_validos.push_back('h');Caracteres_validos.push_back('i');Caracteres_validos.push_back('j');Caracteres_validos.push_back('k');Caracteres_validos.push_back('l');Caracteres_validos.push_back('m');Caracteres_validos.push_back('n');Caracteres_validos.push_back('o');Caracteres_validos.push_back('p');Caracteres_validos.push_back('q');Caracteres_validos.push_back('r');Caracteres_validos.push_back('s');Caracteres_validos.push_back('t');Caracteres_validos.push_back('u');Caracteres_validos.push_back('v');Caracteres_validos.push_back('w');Caracteres_validos.push_back('x');Caracteres_validos.push_back('y');Caracteres_validos.push_back('z');Caracteres_validos.push_back('A');Caracteres_validos.push_back('B');Caracteres_validos.push_back('C');Caracteres_validos.push_back('D');Caracteres_validos.push_back('E');Caracteres_validos.push_back('F');Caracteres_validos.push_back('G');Caracteres_validos.push_back('H');Caracteres_validos.push_back('I');Caracteres_validos.push_back('J');Caracteres_validos.push_back('K');Caracteres_validos.push_back('L');Caracteres_validos.push_back('M');Caracteres_validos.push_back('N');Caracteres_validos.push_back('O');Caracteres_validos.push_back('P');Caracteres_validos.push_back('Q');Caracteres_validos.push_back('R');Caracteres_validos.push_back('S');Caracteres_validos.push_back('T');Caracteres_validos.push_back('U');Caracteres_validos.push_back('V');Caracteres_validos.push_back('W');Caracteres_validos.push_back('X');Caracteres_validos.push_back('Y');Caracteres_validos.push_back('Z');Caracteres_validos.push_back('0');Caracteres_validos.push_back('1');Caracteres_validos.push_back('2');Caracteres_validos.push_back('3');Caracteres_validos.push_back('4');Caracteres_validos.push_back('5');Caracteres_validos.push_back('6');Caracteres_validos.push_back('7');Caracteres_validos.push_back('8');Caracteres_validos.push_back('9');Caracteres_validos.push_back('!');Caracteres_validos.push_back('#');Caracteres_validos.push_back('$');Caracteres_validos.push_back('%');Caracteres_validos.push_back('&');Caracteres_validos.push_back('\'');Caracteres_validos.push_back('*');Caracteres_validos.push_back('+');Caracteres_validos.push_back('-');Caracteres_validos.push_back('/');Caracteres_validos.push_back('=');Caracteres_validos.push_back('?');Caracteres_validos.push_back('^');Caracteres_validos.push_back('_');Caracteres_validos.push_back('`');Caracteres_validos.push_back('{');Caracteres_validos.push_back('|');Caracteres_validos.push_back('}');Caracteres_validos.push_back('~');
    int tamanho_caracteres = Caracteres_validos.size();

    if((parte_local[0] == '.')||(parte_local[tamanho_parteLocal-1] == '.')){
        throw invalid_argument("Argumento invalido.");
    }
    if((dominio[0] == '.')||(dominio[tamanho_dominio-1] == '.')){
        throw invalid_argument("Argumento invalido.");
    }

    int flag_caractere = 0;

    for(int i = 0; i < tamanho_parteLocal; i++){
        if((parte_local[i] == '.')&&(i < tamanho_parteLocal-1)&&(0 < i)){
            if(parte_local[i+1] == '.'){
                throw invalid_argument("Argumento invalido.");
            }
            if(parte_local[i-1] == '.'){
                throw invalid_argument("Argumento invalido.");
            }
        }

        for(int j = 0; j < tamanho_caracteres; j++){
            if((parte_local[i] == Caracteres_validos[j])||(parte_local[i] == '.')){
                flag_caractere++;
            }
        }
    }
    if(flag_caractere != tamanho_parteLocal){
        throw invalid_argument("Argumento invalido.");
    }

    flag_caractere = 0;

    for(int i = 0; i < tamanho_dominio; i++){
        if((dominio[i] == '.')&&(i < tamanho_dominio - 1)&&(0 < i)){
            if(dominio[i+1] == '.'){
                throw invalid_argument("Argumento invalido.");
            }
            if(dominio[i-1] == '.'){
                throw invalid_argument("Argumento invalido.");
            }
        }

        for(int j = 0; j < tamanho_caracteres; j++){
            if((dominio[i] == Caracteres_validos[j])||(dominio[i] == '.')){
                flag_caractere++;
            }
        }
    }

    if(flag_caractere != tamanho_dominio){
        throw invalid_argument("Argumento invalido.");
    }

}

void Email::setValor(string valor){
    validar(valor);
    this->valor = valor;
}
