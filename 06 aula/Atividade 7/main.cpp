#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* esquerdo;
    Node* direito;
};

void inOrder(Node* raiz){
    if(raiz){
        inOrder(raiz->esquerdo);
        cout << raiz->valor << " ";
        inOrder(raiz->direito);
    }
};

void preOrder(Node* raiz){
    if(raiz){
        cout << raiz->valor << " ";
        preOrder(raiz->esquerdo);
        preOrder(raiz->direito);
    }
};

void postOrder(Node* raiz){
    if(raiz){
        postOrder(raiz->esquerdo);
        postOrder(raiz->direito);
        cout << raiz->valor << " ";
    }
};

Node* insert(Node* raiz, int valor) {
    if (raiz == nullptr) {
        return new Node{valor, nullptr, nullptr};
    }
    else if (valor < raiz->valor) {
        raiz->esquerdo = insert(raiz->esquerdo, valor);
    } else if (valor > raiz->valor) {
        raiz->direito = insert(raiz->direito, valor);
    }
    else{
        cout << "Valor " << valor << " já existe na árvore." << endl;
    }
    return raiz;
};

Node* remove(Node* raiz, int valor){
    if(!raiz)return raiz;

    if(valor < raiz->valor){
        raiz->esquerdo = remove(raiz->esquerdo, valor);
    }else if(valor > raiz->valor){
        raiz->direito = remove(raiz->direito, valor);
    }else{
        if(!raiz->esquerdo){
            return raiz->direito;
        }
        if(!raiz->direito){
            return raiz->esquerdo;
        }

        Node* succ = raiz->direito;
        while(succ->esquerdo){
            succ = succ->esquerdo;
        }
        raiz->valor = succ->valor;
        raiz->direito = remove(raiz->direito, succ->valor);
    }
    return raiz;
}


int main() {

    Node* raiz = new Node{10, nullptr, nullptr};
    raiz->esquerdo = new Node{5, nullptr, nullptr};
    raiz->direito = new Node{15, nullptr, nullptr};
    raiz->esquerdo -> esquerdo = new Node{2, nullptr, nullptr};
    raiz->esquerdo -> direito = new Node{7, nullptr, nullptr};
    raiz->direito -> direito = new Node{20, nullptr, nullptr};

    cout << "In-order: ";
    inOrder(raiz);
    cout << endl;

    cout << "Pre-order: ";
    preOrder(raiz);
    cout << endl;

    cout << "Post-order: ";
    postOrder(raiz);
    cout << endl;

    cout << "Inserindo 12:" << endl;
    insert(raiz, 12);
    cout << "In-order após inserção: ";
    inOrder(raiz);
    cout << endl;

    cout << "Removendo 15:" << endl;
    remove(raiz, 15);
    cout << "In-order após remoção: ";
    inOrder(raiz);
    cout << endl;

}