#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>

using namespace std;

///
/// Padrao para representacao da capacidade.
///
/// Regras de formato:
///
/// -Capacidades validas: 100, 200, 300, 400, 500.
///


class Capacidade {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:
        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Capacidade.
        ///
        ///@return

        void setValor(string);


        ///Metodo retorna string armazenada.
        ///
        ///@return Capacidade.

        string getValor() const;
};

inline string Capacidade::getValor() const{//Método inline.
    return valor;
}

///
///Padrao para representacao de cargo.
///
///Regras de formato:
///
/// - Cargos validos: ator, cenógrafo, figurinista, maquiador, sonoplasta, iluminador.
///

class Cargo {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Cargo.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna cargo em formato de string.
        ///
        ///@return Cargo.

        string getValor() const;           // Método para recuperar valor.
};

inline string Cargo::getValor() const{
    return valor;
}

///
///Padrao para representacao de classificacao.
///
///Regras de formato:
///
/// - Classificacoes validas: livre, 10, 12, 14, 16, 18.
///

class Classificacao {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Classificacao.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna classificacao em formato de string.
        ///
        ///@return Classificacao.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Classificacao::getValor() const{
    return valor;
}

///
///Padrao para representacao de codigo.
///
///Regras de formato:
///
/// - Formato LLDDDD
///   Cada L eh letra maiuscula(A-Z).
///   Cada D eh digito(0-9).
///

class Codigo {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Codigo.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna codigo em formato de string.
        ///
        ///@return Codigo.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Codigo::getValor() const{
    return valor;
}

///
///Padrao representacao de data.
///
///Regras de formato:
///
/// - Fomato DD/MM/AAAA
///   DD entre 01 e 31.
///   MM entre 01 e 12.
///   AAAA entre 2000 e 9999.
///   Obs:Data considera a ocorrencia de anos bissextos.
///

class Data {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Data.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna data em formato de string.
        ///
        ///@return Data.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Data::getValor() const{
    return valor;
}

///
///Padrao representacao de email.
///
///Regras de formato:
///
/// - Formato <i>parte-local</i>@<i>dominio</i>
///   <i>parte-local</i> é composta por ate 64 caracteres.
///   <i>dominio</i> é composto por ate 255 caracteres.
///   Caractere pode ser letra maiuscula (A-Z) ou letra minuscula(a-z).
///   Caractere pode ser digito (0-9).
///   Caractere pode ser !#$%&'*+-/=?^_`{|}~.
///   Caractere pode ser ponto (.) desde que nao seja o primeiro ou ultimo caractere de <i>parte-local</i> ou <i>dominio</i> e que nao ocorra em sequencia.
///

class Email {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Email.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna email em formato de string.
        ///
        ///@return Email.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Email::getValor() const{
    return valor;
}

///
///Padrao representacao de horario.
///
///Regras de formato:
///
/// -Formato HH:MM
///  Em HH tem-se indicacao de horario : 00 a 23.
///  EM MM tem-se indicacao de minuto  : 00, 15, 30, 45
///

class Horario {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Horario.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna horario em formato de string.
        ///
        ///@return Horario.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Horario::getValor() const{
    return valor;
}

///
///Padrao representacao de matricula.
///
///Regras de formato:
///
/// -Formato XXXXX
///  Cada X eh digito (0-9)
///  Nao podem existir digitos duplicados.
///

class Matricula {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Matricula.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna matricula em formato de string.
        ///
        ///@return Matricula.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Matricula::getValor() const{
    return valor;
}

///
///Padrao representacao de nome.
///
///Regras de formato:
///
///  De 5 a 20 caracteres.
///  Cada caracter eh letra (A-Z ou a-z),ponto (.) ou espaço em branco.
///  Ponto (.) é precedido por letra.
///  Nao ha espacos em branco em sequencia.
///  Primeira letra de cada termo eh letra maiuscula (A-Z).
///

class Nome {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Nome.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna nome em formato de string.
        ///
        ///@return Nome.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Nome::getValor() const{
    return valor;
}

///
///Padrao representacao de senha.
///
///Regras de formato:
///
/// -Formato XXXXXXXX
///  Cada caractere X eh letra (A-Z ou a-z),digito (0-9) ou caractere especial.
///  Sao possiveis caracteres especiais !'@'#$%&?
///  Nao existe caracter repetido.
///  Existe pelo menos uma letra (maiuscula ou minuscula), um digito e um caractere especial.
///


class Senha {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Senha.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna senha em formato de string.
        ///
        ///@return Senha.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Senha::getValor() const{
    return valor;
}

///
///Padrao representacao de telefone.
///
///Regras de formato:
///
/// -Formato (XX)-YYYYYYYYY
///  XX eh um dos seguintes codigos 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33, 34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 94, 95, 96, 97, 98, 99.
///  Cada Y eh digito (0-9).
///  Nao existe numero de telefone 000000000.
///

class Telefone {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Telefone.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna telefone em formato de string.
        ///
        ///@return Telefone.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Telefone::getValor() const{
    return valor;
}

///
///Padrao representacao de tipo.
///
///Regras de formato:
///
/// -Tipo validos: auto, comédia, drama, farsa, melodrama, monólogo, musical, ópera, revista.
///

class Tipo {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // Método para validar valor.
    public:

        ///Armazena string caso seja valida.
        ///
        ///Lanca excecão caso valor seja invalido.
        ///
        ///@param valor Tipo.
        ///
        ///@throw invalid_argument

        void setValor(string);             // Método para atribuir valor.

        ///
        ///Retorna tipo em formato de string.
        ///
        ///@return Tipo.
        ///

        string getValor() const;           // Método para recuperar valor.
};

inline string Tipo::getValor() const{
    return valor;
}

#endif // DOMINIOS_H_INCLUDED
