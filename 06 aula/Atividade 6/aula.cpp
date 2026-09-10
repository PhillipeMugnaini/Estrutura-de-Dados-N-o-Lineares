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

    return 0;

}