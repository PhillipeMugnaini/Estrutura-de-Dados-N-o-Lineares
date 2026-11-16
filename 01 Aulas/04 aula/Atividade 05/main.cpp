#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Árvore genérica
struct NoGenerico {
    string nome;
    vector<NoGenerico*> filhos;

    NoGenerico(string n) {
        nome = n;
    }
};

// Árvore binária
struct NoBinario {
    string nome;
    NoBinario* esquerdo;
    NoBinario* direito;

    NoBinario(string n) {
        nome = n;
        esquerdo = nullptr;
        direito = nullptr;
    }
};


// Mostra a árvore genérica
void mostrarGenerica(NoGenerico* no, int nivel = 0) {

    if (no == nullptr)
        return;

    for (int i = 0; i < nivel; i++)
        cout << "   ";

    cout << no->nome << endl;

    for (NoGenerico* filho : no->filhos) {
        mostrarGenerica(filho, nivel + 1);
    }
}


// Converte árvore genérica para binária
NoBinario* converterParaBinaria(NoGenerico* no) {

    if (no == nullptr)
        return nullptr;

    NoBinario* novo = new NoBinario(no->nome);

    // Se possuir filhos
    if (!no->filhos.empty()) {

        // Primeiro filho vira filho esquerdo
        novo->esquerdo = converterParaBinaria(no->filhos[0]);

        NoBinario* atual = novo->esquerdo;

        // Os próximos filhos viram irmãos à direita
        for (int i = 1; i < no->filhos.size(); i++) {

            atual->direito =
                converterParaBinaria(no->filhos[i]);

            atual = atual->direito;
        }
    }

    return novo;
}


// Mostra as ligações da árvore binária
void mostrarBinaria(NoBinario* no) {

    if (no == nullptr)
        return;

    cout << "\nNo: " << no->nome << endl;

    if (no->esquerdo != nullptr)
        cout << "  Esquerda: "
             << no->esquerdo->nome << endl;

    if (no->direito != nullptr)
        cout << "  Direita: "
             << no->direito->nome << endl;

    mostrarBinaria(no->esquerdo);
    mostrarBinaria(no->direito);
}


int main() {

    // 1ª geração
    NoGenerico* avos =
        new NoGenerico("Odete + Dimas");


    // 2ª geração
    NoGenerico* marcelo =
        new NoGenerico("Marcelo + Marcia");

    NoGenerico* elton =
        new NoGenerico("Elton + Ariane");

    NoGenerico* elvis =
        new NoGenerico("Elvis + Pricila");


    // 3ª geração
    NoGenerico* phillipe =
        new NoGenerico("Phillipe");

    NoGenerico* guilherme =
        new NoGenerico("Guilherme");

    NoGenerico* estela =
        new NoGenerico("Estela");

    NoGenerico* yasmin =
        new NoGenerico("Yasmin");


    // Filhos de Odete + Dimas
    avos->filhos.push_back(marcelo);
    avos->filhos.push_back(elton);
    avos->filhos.push_back(elvis);


    // Filhos de Marcelo + Marcia
    marcelo->filhos.push_back(phillipe);
    marcelo->filhos.push_back(guilherme);


    // Filha de Elton + Ariane
    elton->filhos.push_back(estela);


    // Filha de Elvis + Pricila
    elvis->filhos.push_back(yasmin);


    cout << "ARVORE GENEALOGICA\n\n";

    mostrarGenerica(avos);


    // Conversão
    NoBinario* raizBinaria =
        converterParaBinaria(avos);


    cout << "\n\nARVORE BINARIA";
    cout << "\nFilho mais a esquerda - Irmao a direita\n";

    mostrarBinaria(raizBinaria);


    return 0;
}