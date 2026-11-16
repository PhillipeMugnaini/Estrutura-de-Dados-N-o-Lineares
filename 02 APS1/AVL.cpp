#include "AVL.h"

AVL::AVL(){

    raiz = nullptr;

}

int AVL::altura(Node* no){

    if(no == nullptr)
        return 0;

    return no->altura;

}

int AVL::maior(int a,int b){

    return (a>b)?a:b;

}

int AVL::fatorBalanceamento(Node* no){

    if(no==nullptr)
        return 0;

    return altura(no->esquerda) - altura(no->direita);

}

Node* AVL::novoNo(Jogador jogador){


    Node* novo = new Node;

    novo->jogador = jogador;

    novo->esquerda = nullptr;

    novo->direita = nullptr;

    novo->altura = 1;

    return novo;

}

Node* AVL::rotacaoDireita(Node* y){


    Node* x = y->esquerda;

    Node* T2 = x->direita;

    x->direita = y;

    y->esquerda = T2;

    y->altura = maior(
        altura(y->esquerda),
        altura(y->direita)
    ) + 1;

    x->altura = maior(
        altura(x->esquerda),
        altura(x->direita)
    ) + 1;

    return x;

}

Node* AVL::rotacaoEsquerda(Node* x){

    Node* y = x->direita;

    Node* T2 = y->esquerda;

    y->esquerda = x;

    x->direita = T2;

    x->altura = maior(
        altura(x->esquerda),
        altura(x->direita)
    ) + 1;

    y->altura = maior(
        altura(y->esquerda),
        altura(y->direita)
    ) + 1;

    return y;

}

Node* AVL::balancear(Node* no){

    no->altura =
    maior(
        altura(no->esquerda),
        altura(no->direita)
    ) + 1;

    int fb = fatorBalanceamento(no);

    // esquerda esquerda

    if(fb > 1 && fatorBalanceamento(no->esquerda)>=0)
        return rotacaoDireita(no);

    // direita direita

    if(fb < -1 && fatorBalanceamento(no->direita)<=0)
        return rotacaoEsquerda(no);

    // esquerda direita

    if(fb > 1 && fatorBalanceamento(no->esquerda)<0){

        no->esquerda =
        rotacaoEsquerda(no->esquerda);

        return rotacaoDireita(no);

    }

    // direita esquerda

    if(fb < -1 && fatorBalanceamento(no->direita)>0){

        no->direita =
        rotacaoDireita(no->direita);

        return rotacaoEsquerda(no);

    }

    return no;

}

Node* AVL::inserir(Node* no, Jogador jogador){


    if(no==nullptr)
        return novoNo(jogador);

    if(jogador.pontuacao < no->jogador.pontuacao)

        no->esquerda =
        inserir(no->esquerda,jogador);

    else if(jogador.pontuacao > no->jogador.pontuacao)

        no->direita =
        inserir(no->direita,jogador);

    else{

        cout<<"Pontuacao ja cadastrada!\n";

        return no;

    }

    return balancear(no);

}

void AVL::inserir(Jogador jogador){

    raiz = inserir(raiz,jogador);

}

Node* AVL::buscar(int pontuacao){

    Node* atual = raiz;

    while(atual!=nullptr){

        if(pontuacao == atual->jogador.pontuacao)

            return atual;

        if(pontuacao < atual->jogador.pontuacao)

            atual = atual->esquerda;

        else

            atual = atual->direita;

    }

    return nullptr;

}

Node* AVL::menorValor(Node* no){

    Node* atual = no;

    while(atual->esquerda!=nullptr)

        atual = atual->esquerda;

    return atual;

}

Node* AVL::remover(Node* no,int pontuacao){

    if(no==nullptr)

        return no;

    if(pontuacao < no->jogador.pontuacao)

        no->esquerda =
        remover(no->esquerda,pontuacao);

    else if(pontuacao > no->jogador.pontuacao)

        no->direita =
        remover(no->direita,pontuacao);

    else{

        if(no->esquerda==nullptr ||
           no->direita==nullptr){

            Node* temp =
            no->esquerda ?
            no->esquerda :
            no->direita;

            delete no;

            return temp;

        }

        Node* temp =
        menorValor(no->direita);

        no->jogador =
        temp->jogador;

        no->direita =
        remover(
            no->direita,
            temp->jogador.pontuacao
        );


    }

    return balancear(no);

}

void AVL::remover(int pontuacao){

    raiz =
    remover(raiz,pontuacao);

}

void AVL::atualizarPontuacao(
int atual,
int nova){

    Node* jogador = buscar(atual);

    if(jogador==nullptr){

        cout<<"Jogador nao encontrado\n";

        return;

    }

    Jogador novo =
    jogador->jogador;

    remover(atual);

    novo.pontuacao = nova;

    inserir(novo);

}

void AVL::emOrdem(Node* no){

    if(no){

        emOrdem(no->esquerda);

        cout
        <<no->jogador.nome
        <<" - "
        <<no->jogador.pontuacao
        <<endl;

        emOrdem(no->direita);

    }

}

void AVL::preOrdem(Node* no){


    if(no){

        cout
        <<no->jogador.nome
        <<" - "
        <<no->jogador.pontuacao
        <<endl;

        preOrdem(no->esquerda);

        preOrdem(no->direita);

    }

}

void AVL::posOrdem(Node* no){

    if(no){

        posOrdem(no->esquerda);

        posOrdem(no->direita);

        cout
        <<no->jogador.nome
        <<" - "
        <<no->jogador.pontuacao
        <<endl;

    }

}

void AVL::mostrarEmOrdem(){

    emOrdem(raiz);

}

void AVL::mostrarPreOrdem(){

    preOrdem(raiz);

}

void AVL::mostrarPosOrdem(){

    posOrdem(raiz);

}

void AVL::mostrarAltura(){

    cout<<"Altura da arvore: "
    <<altura(raiz)
    <<endl;

}

void AVL::top5(Node* no,int &contador){

    if(no && contador<5){

        top5(no->direita,contador);


        if(contador<5){

            cout
            <<no->jogador.nome
            <<" - "
            <<no->jogador.pontuacao
            <<endl;

            contador++;

        }

        top5(no->esquerda,contador);

    }

}

void AVL::mostrarTop5(){

    int contador=0;

    top5(raiz,contador);

}