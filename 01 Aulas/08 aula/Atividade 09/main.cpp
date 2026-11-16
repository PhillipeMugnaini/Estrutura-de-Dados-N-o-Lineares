
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

public:
    // Inserir um elemento
    void insert(int valor) {
        heap.push_back(valor);
        int i = heap.size() - 1;

        // Reorganiza o heap de baixo para cima
        while (i > 0) {
            int pai = (i - 1) / 2;

            if (heap[i] > heap[pai]) {
                swap(heap[i], heap[pai]);
                i = pai;
            } else {
                break;
            }
        }
    }

    // Retornar o maior elemento
    int getMax() {
        if (heap.empty()) {
            cout << "Fila vazia!" << endl;
            return -1;
        }

        return heap[0];
    }

    // Remover o maior elemento
    void deleteMax() {
        if (heap.empty()) {
            cout << "Fila vazia!" << endl;
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;
        int tamanho = heap.size();

        // Reorganiza o heap de cima para baixo
        while (true) {
            int esquerda = 2 * i + 1;
            int direita = 2 * i + 2;
            int maior = i;

            if (esquerda < tamanho &&
                heap[esquerda] > heap[maior]) {
                maior = esquerda;
            }

            if (direita < tamanho &&
                heap[direita] > heap[maior]) {
                maior = direita;
            }

            if (maior == i) {
                break;
            }

            swap(heap[i], heap[maior]);
            i = maior;
        }
    }

    // Mostrar o estado atual da fila
    void showQueue() {
        if (heap.empty()) {
            cout << "Fila vazia!" << endl;
            return;
        }

        cout << "Fila: ";
        for (int valor : heap) {
            cout << valor << " ";
        }
        cout << endl;
    }
};

int main() {
    // Criando o objeto queue
    MaxHeap queue;

    // Inserindo a sequencia solicitada
    queue.insert(30);
    queue.insert(10);
    queue.insert(50);
    queue.insert(40);
    queue.insert(20);

    cout << "Estado atual da fila:" << endl;
    queue.showQueue();

    cout << "\nMaior elemento: "
         << queue.getMax() << endl;

    cout << "\nRemovendo o maior elemento..." << endl;
    queue.deleteMax();

    cout << "\nFila apos remocao:" << endl;
    queue.showQueue();

    cout << "\nNovo maior elemento: "
         << queue.getMax() << endl;

    return 0;
}
