#ifndef AVL_H
#define AVL_H


#include "Jogador.h"
#include <iostream>

using namespace std;


struct Node {

    Jogador jogador;

    Node* esquerda;
    Node* direita;

    int altura;

};


class AVL {


private:

    Node* raiz;


    int altura(Node* no);

    int maior(int a, int b);

    int fatorBalanceamento(Node* no);


    Node* novoNo(Jogador jogador);


    Node* rotacaoDireita(Node* y);

    Node* rotacaoEsquerda(Node* x);


    Node* balancear(Node* no);


    Node* inserir(Node* no, Jogador jogador);


    Node* remover(Node* no, int pontuacao);


    Node* menorValor(Node* no);



    void preOrdem(Node* no);

    void emOrdem(Node* no);

    void posOrdem(Node* no);


    void top5(Node* no, int &contador);



public:


    AVL();


    void inserir(Jogador jogador);


    Node* buscar(int pontuacao);


    void remover(int pontuacao);


    void atualizarPontuacao(int pontuacaoAtual, int novaPontuacao);


    void mostrarPreOrdem();

    void mostrarEmOrdem();

    void mostrarPosOrdem();


    void mostrarAltura();


    void mostrarTop5();


};


#endif