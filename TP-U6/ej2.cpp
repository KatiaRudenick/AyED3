#include <iostream>

using namespace std;

bool par(int n);
bool impar(int n);

bool par(int n) {
    if (n == 0) return true;   
    return impar(n - 1);   
}

bool impar(int n) {
    if (n == 0) return false;   
    return par(n - 1);        
}

int main() {
    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    if (par(numero))
        cout << numero << " es par.\n";
    else
        cout << numero << " es impar.\n";

    return 0;
}
