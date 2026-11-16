#include <iostream>
using namespace std;

int exemplo(int n) {
    int cont = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cont++;
        }
    }

    return cont;
}

int main() {
    cout << "n = 10   -> cont = " << exemplo(10) << endl;
    cout << "n = 100  -> cont = " << exemplo(100) << endl;
    cout << "n = 1000 -> cont = " << exemplo(1000) << endl;

    return 0;
}

// 1. Estime o número de operações em função de n.
// R:n^2 porque temos dois loops aninhados que percorrem de 0 a n.

// 2. Classifique a complexidade assintótica.
// R: O(n^2) - Complexidade quadrática.

// Compare a contagem real (cont impresso na tela) para n = 10, 100, 1000.
// R: Para n = 10, cont = 100; para n = 100, cont = 10000; para n = 1000, cont = 1000000. Isso confirma a estimativa de n^2.