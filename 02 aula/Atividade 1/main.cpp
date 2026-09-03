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