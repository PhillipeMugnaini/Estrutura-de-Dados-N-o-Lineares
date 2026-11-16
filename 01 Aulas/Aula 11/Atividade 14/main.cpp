#include <iostream>
#include <vector>
using namespace std;

class Grafo {
private:
    vector<vector<int>> adjacencia;

    // Visita os vertices conectados ao vertice atual
    void dfs(int vertice, vector<bool>& visitado) {
        visitado[vertice] = true;

        for (int vizinho : adjacencia[vertice]) {
            if (!visitado[vizinho]) {
                dfs(vizinho, visitado);
            }
        }
    }

public:
    Grafo(int quantidadeVertices) {
        adjacencia.resize(quantidadeVertices);
    }

    // Insere uma aresta nos dois sentidos (grafo nao direcionado)
    void adicionarAresta(int origem, int destino) {
        adjacencia[origem].push_back(destino);
        adjacencia[destino].push_back(origem);
    }

    // Exibe a lista de adjacencia
    void mostrarGrafo() {
        for (int i = 0; i < static_cast<int>(adjacencia.size()); i++) {
            cout << "Vertice " << i << " conectado a: ";
            for (int vizinho : adjacencia[i]) {
                cout << vizinho << " ";
            }
            cout << endl;
        }
    }

    // Verifica se todos os vertices podem ser visitados a partir de 0
    bool ehConexo() {
        if (adjacencia.empty()) {
            return true;
        }

        vector<bool> visitado(adjacencia.size(), false);
        dfs(0, visitado);

        for (bool foiVisitado : visitado) {
            if (!foiVisitado) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Grafo grafo(6);

    // Conexoes mostradas na atividade
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(0, 3);
    grafo.adicionarAresta(1, 4);
    grafo.adicionarAresta(2, 5);
    grafo.adicionarAresta(3, 4);
    grafo.adicionarAresta(4, 5);

    cout << "Lista de adjacencia:" << endl;
    grafo.mostrarGrafo();

    if (grafo.ehConexo()) {
        cout << "\nO grafo e conexo." << endl;
    } else {
        cout << "\nO grafo nao e conexo." << endl;
    }

    return 0;
}
