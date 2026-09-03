#include <iostream>
#include <vector>

using namespace std;


// Estrutura do no
struct Node {

    int valor;

    Node* esquerdo;
    Node* direito;
};


int main() {


    Node* raiz = new Node{10, nullptr, nullptr};

    raiz->esquerdo = new Node{5, nullptr, nullptr};
    raiz->direito = new Node{15, nullptr, nullptr};

    raiz->esquerdo->esquerdo = new Node{2, nullptr, nullptr};
    raiz->esquerdo->direito = new Node{7, nullptr, nullptr};

    raiz->direito->esquerdo = new Node{12, nullptr, nullptr};
    raiz->direito->direito = new Node{20, nullptr, nullptr};


    cout << "Arvore usando ponteiros:" << endl;

    cout << raiz->valor << endl;

    cout << raiz->esquerdo->valor << " ";
    cout << raiz->direito->valor << endl;

    cout << raiz->esquerdo->esquerdo->valor << " ";
    cout << raiz->esquerdo->direito->valor << " ";
    cout << raiz->direito->esquerdo->valor << " ";
    cout << raiz->direito->direito->valor << endl;

    vector<int> arvore = {10, 5, 15, 2, 7, 12, 20};


    cout << endl;

    cout << "Arvore usando vetor:" << endl;


    for (int i = 0; i < arvore.size(); i++) {

        cout << "Posicao " << i;
        cout << " = " << arvore[i] << endl;
    }


    return 0;
}