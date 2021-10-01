#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>

using namespace std;

///
///Padrao para representa&ccedil;ao de participante.
///

class Participante{
private:
    Matricula matricula;  //cria objeto matricula.
    Nome nome;            //cria objeto nome.
    Nome sobrenome;       //cria objeto sobrenome.
    Email email;          //cria objeto email.
    Telefone telefone;    //cria objeto telefone.
    Senha senha;          //cria objeto senha.
    Cargo cargo;          //cria objeto cargo.
public:

    ///
    ///Armazena valor em matricula.
    ///
    ///@param Matricula.
    ///
    ///@return

    void setMatricula(const Matricula&);

    ///
    ///Metodo retorna matricula armazenada.
    ///
    ///@return Matricula.

    Matricula getMatricula() const;


    ///
    ///Armazena valor em nome.
    ///
    ///@param Nome.
    ///
    ///@return

    void setNome(const Nome&);

    ///
    ///Metodo retorna nome armazenado.
    ///
    ///@return Nome.

    Nome getNome() const;


    ///
    ///Armazena valor em sobrenome.
    ///
    ///@param Sobrenome.
    ///
    ///@return

    void setSobrenome(const Nome&);

    ///
    ///Metodo retorna sobrenome armazenado.
    ///
    ///@return Sobrenome.

    Nome getSobrenome() const;


    ///
    ///Armazena valor em email.
    ///
    ///@param Email.
    ///
    ///@return

    void setEmail(const Email&);

    ///
    ///Metodo retorna email armazenado.
    ///
    ///@return Email.

    Email getEmail() const;


    ///
    ///Armazena valor em telefone.
    ///
    ///@param Telefone.
    ///
    ///@return

    void setTelefone(const Telefone&);

    ///
    ///Metodo retorna telefone armazenado.
    ///
    ///@return Telefone.

    Telefone getTelefone() const;


    ///
    ///Armazena valor em senha.
    ///
    ///@param Senha.
    ///
    ///@return

    void setSenha(const Senha&);

    ///
    ///Metodo retorna senha armazenado.
    ///
    ///@return Senha.

    Senha getSenha() const;


    ///
    ///Armazena valor em cargo.
    ///
    ///@param Cargo.
    ///
    ///@return

    void setCargo(const Cargo&);

    ///
    ///Metodo retorna cargo armazenado.
    ///
    ///@return Cargo.

    Cargo getCargo() const;
};

inline void Participante::setMatricula(const Matricula &matricula){
    this->matricula = matricula;
}

inline Matricula Participante::getMatricula() const{
    return matricula;
}

inline void Participante::setNome(const Nome &nome){
    this->nome = nome;
}

inline Nome Participante::getNome() const{
    return nome;
}

inline void Participante::setSobrenome(const Nome &sobrenome){
    this->sobrenome = sobrenome;
}

inline Nome Participante::getSobrenome() const{
    return sobrenome;
}

inline void Participante::setEmail(const Email &email){
    this->email = email;
}

inline Email Participante::getEmail() const{
    return email;
}

inline void Participante::setTelefone(const Telefone &telefone){
    this->telefone = telefone;
}

inline Telefone Participante::getTelefone() const{
    return telefone;
}

inline void Participante::setSenha(const Senha &senha){
    this->senha = senha;
}

inline Senha Participante::getSenha() const{
    return senha;
}

inline void Participante::setCargo(const Cargo &cargo){
    this->cargo = cargo;
}

inline Cargo Participante::getCargo() const{
    return cargo;
}

///
///Padrao para representa&ccedil;ao de pe&ccedil;a.
///

class Peca{
private:
    Codigo identificador;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;
public:

    ///
    ///Armazena valor em identificador.
    ///
    ///@param Codigo.
    ///
    ///@return

    void setIdentificador(const Codigo&);

    ///
    ///Metodo retorna identificador armazenado.
    ///
    ///@return Codigo.

    Codigo getIdentificador() const;

    ///
    ///Armazena valor em nome.
    ///
    ///@param Nome.
    ///
    ///@return

    void setNome(const Nome&);

    ///
    ///Metodo retorna nome armazenado.
    ///
    ///@return Nome.

    Nome getNome() const;


    ///
    ///Armazena valor em tipo.
    ///
    ///@param Tipo.
    ///
    ///@return

    void setTipo(const Tipo&);

    ///
    ///Metodo retorna tipo armazenado.
    ///
    ///@return Tipo.

    Tipo getTipo() const;

    ///
    ///Armazena valor em classificacao.
    ///
    ///@param Classificacao.
    ///
    ///@return

    void setClassificacao(const Classificacao&);

    ///
    ///Metodo retorna classificacao armazenada.
    ///
    ///@return Classificacao.

    Classificacao getClassificacao() const;
};

inline void Peca::setIdentificador(const Codigo &identificador){
    this->identificador = identificador;
}

inline Codigo Peca::getIdentificador() const{
    return identificador;
}

inline void Peca::setNome(const Nome &nome){
    this->nome = nome;
}

inline Nome Peca::getNome() const{
    return nome;
}

inline void Peca::setTipo(const Tipo &tipo){
    this->tipo = tipo;
}

inline Tipo Peca::getTipo() const{
    return tipo;
}

inline void Peca::setClassificacao(const Classificacao &classificacao){
    this->classificacao = classificacao;
}

inline Classificacao Peca::getClassificacao() const{
    return classificacao;
}


///
///Padrao para representa&ccedil;ao de sessao.
///

class Sessao{
private:
    Codigo identificador;
    Data data;
    Horario horario;
public:
    ///
    ///Armazena valor em identificador.
    ///
    ///@param Identificador.
    ///
    ///@return

    void setIdentificador(const Codigo&);

    ///
    ///Metodo retorna identificador armazenado.
    ///
    ///@return Codigo.

    Codigo getIdentificador() const;

    ///
    ///Armazena valor em data.
    ///
    ///@param Data.
    ///
    ///@return

    void setData(const Data&);


    ///
    ///Metodo retorna data armazenado.
    ///
    ///@return Data.

    Data getData() const;

    ///
    ///Armazena valor em horario.
    ///
    ///@param Horario.
    ///
    ///@return

    void setHorario(const Horario&);

    ///
    ///Metodo retorna horario armazenado.
    ///
    ///@return Horario.

    Horario getHorario() const;
};

inline void Sessao::setIdentificador(const Codigo &identificador){
    this->identificador = identificador;
}

inline Codigo Sessao::getIdentificador() const{
    return identificador;
}

inline void Sessao::setData(const Data &data){
    this->data = data;
}

inline Data Sessao::getData() const{
    return data;
}

inline void Sessao::setHorario(const Horario &horario){
    this->horario = horario;
}

inline Horario Sessao::getHorario() const{
    return horario;
}


///
///Padrao para representa&ccedil;ao de sala.
///

class Sala{
private:
    Codigo identificador;
    Nome nome;
    Capacidade capacidade;
public:
    ///
    ///Armazena valor em identificador.
    ///
    ///@param Identificador.
    ///
    ///@return

    void setIdentificador(const Codigo&);

    ///
    ///Metodo retorna identificador armazenado.
    ///
    ///@return Codigo.

    Codigo getIdentificador() const;

    ///
    ///Armazena valor em nome.
    ///
    ///@param Nome.
    ///
    ///@return

    void setNome(const Nome&);

    ///
    ///Metodo retorna nome armazenado.
    ///
    ///@return Nome.

    Nome getNome() const;

    ///
    ///Armazena valor em capacidade.
    ///
    ///@param Capacidade.
    ///
    ///@return

    void setCapacidade(const Capacidade&);

    ///
    ///Metodo retorna capacidade armazenada.
    ///
    ///@return Capacidade.

    Capacidade getCapacidade() const;
};

inline void Sala::setIdentificador(const Codigo &identificador){
    this->identificador = identificador;
}

inline Codigo Sala::getIdentificador() const{
    return identificador;
}

inline void Sala::setNome(const Nome &nome){
    this->nome = nome;
}

inline Nome Sala::getNome() const{
    return nome;
}

inline void Sala::setCapacidade(const Capacidade &capacidade){
    this->capacidade = capacidade;
}

inline Capacidade Sala::getCapacidade() const{
    return capacidade;
}
#endif // ENTIDADES_H_INCLUDED
