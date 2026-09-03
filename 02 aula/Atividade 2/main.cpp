#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


// O(n)
void f1(vector<int> vetor) {

    int soma = 0;

    for (int i = 0; i < vetor.size(); i++) {
        soma += vetor[i];
    }
}


// O(n²)
void f2(vector<int> vetor) {

    long long soma = 0;

    for (int i = 0; i < vetor.size(); i++) {

        for (int j = 0; j < vetor.size(); j++) {
            soma += vetor[j];
        }

    }
}


// O(n log n)
void f3(vector<int> vetor) {

    int encontrados = 0;

    for (int i = 0; i < vetor.size(); i++) {

        if (binary_search(vetor.begin(), vetor.end(), vetor[i])) {
            encontrados++;
        }

    }
}


int main() {

    int tamanhos[3] = {1000, 10000, 100000};


    for (int t = 0; t < 3; t++) {

        int n = tamanhos[t];

        vector<int> vetor(n);


        // Preenche o vetor
        for (int i = 0; i < n; i++) {
            vetor[i] = i;
        }


        cout << "\nTamanho: " << n << endl;


        // f1

        clock_t inicio = clock();

        f1(vetor);

        clock_t fim = clock();

        double tempo1 = double(fim - inicio) / CLOCKS_PER_SEC;


        // f2

        inicio = clock();

        f2(vetor);

        fim = clock();

        double tempo2 = double(fim - inicio) / CLOCKS_PER_SEC;


        // f3

        inicio = clock();

        f3(vetor);

        fim = clock();

        double tempo3 = double(fim - inicio) / CLOCKS_PER_SEC;


        cout << "f1 O(n): " << tempo1 << " segundos" << endl;
        cout << "f2 O(n²): " << tempo2 << " segundos" << endl;
        cout << "f3 O(n log n): " << tempo3 << " segundos" << endl;
    }


    return 0;
}

// 3. Explique como os resultados confirmam ou não a teoria da ordem de crescimento.

// A função f1, que possui complexidade O(n), apresentou o menor tempo e continuou rápida mesmo com 100.000 elementos.

// A função f3, de complexidade O(n log n), apresentou um crescimento um pouco maior que a f1, mas ainda teve um tempo
// de execução baixo.

// Já a função f2, de complexidade O(n²), teve um aumento muito grande no tempo. Com 1.000 elementos levou apenas
// 0,003882 segundos, mas com 100.000 elementos chegou a 30,6001 segundos.

// Isso mostra na prática que algoritmos O(n²) ficam muito mais lentos conforme a quantidade de dados aumenta, enquanto
// O(n) e O(n log n) conseguem trabalhar melhor com entradas maiores.