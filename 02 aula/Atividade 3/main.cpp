#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


// BUBBLE SORT
void bubbleSort(vector<int>& vetor) {

    int n = vetor.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - 1 - i; j++) {

            if (vetor[j] > vetor[j + 1]) {

                int aux = vetor[j];

                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}


// JUNTA AS PARTES DO MERGE SORT
void juntar(vector<int>& vetor, int inicio, int meio, int fim) {

    vector<int> temp;

    int i = inicio;
    int j = meio + 1;

    while (i <= meio && j <= fim) {

        if (vetor[i] < vetor[j]) {
            temp.push_back(vetor[i]);
            i++;
        }
        else {
            temp.push_back(vetor[j]);
            j++;
        }
    }

    while (i <= meio) {
        temp.push_back(vetor[i]);
        i++;
    }

    while (j <= fim) {
        temp.push_back(vetor[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        vetor[inicio + k] = temp[k];
    }
}


// MERGE SORT
void mergeSort(vector<int>& vetor, int inicio, int fim) {

    if (inicio < fim) {

        int meio = (inicio + fim) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        juntar(vetor, inicio, meio, fim);
    }
}


int main() {

    int n = 10000;

    vector<int> vetor1(n);
    vector<int> vetor2(n);


    for (int i = 0; i < n; i++) {

        vetor1[i] = n - i;
        vetor2[i] = n - i;
    }


    cout << "Iniciando Merge Sort..." << endl;

    clock_t inicio = clock();

    mergeSort(vetor2, 0, n - 1);

    clock_t fim = clock();

    double tempoMerge = double(fim - inicio) / CLOCKS_PER_SEC;

    cout << "Merge Sort terminou!" << endl;
    cout << "Tempo: " << tempoMerge << " segundos" << endl;



    cout << "\nIniciando Bubble Sort..." << endl;

    inicio = clock();

    bubbleSort(vetor1);

    fim = clock();

    double tempoBubble = double(fim - inicio) / CLOCKS_PER_SEC;

    cout << "Bubble Sort terminou!" << endl;
    cout << "Tempo: " << tempoBubble << " segundos" << endl;


    return 0;
}   

// 1. Estime aproximadamente quantas comparações cada algoritmo realizaria.
// R: O Merge Sort realiza aproximadamente n log n comparações, enquanto o Bubble Sort realiza aproximadamente n^2 comparações.

// 3. Discuta em quais situações práticas o algoritmo quadrático ainda poderia ser escolhido.
// RO Bubble Sort pode ser escolhido para vetores pequenos ou para fins de aprendizado. Em grandes volumes de dados
// ele não é indicado, pois seu tempo cresce muito mais rapidamente que o Merge Sort.