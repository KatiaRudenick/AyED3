#include <iostream>
#include <stack>
#include <string>

using namespace std;

class HistorialLlamadas {
private:
    stack<string> llamadas;

public:
    void agregarLlamada(string numero) {
        llamadas.push(numero);
        cout << "Numero " << numero << " agregado al historial.\n";
    }

    void mostrarHistorial() {
        stack<string> temp = llamadas;
        cout << "Historial de llamadas:\n";
        while (!temp.empty()) {
            cout << temp.top() << "\n";
            temp.pop();
        }
    }

    void deshacerLlamada() {
        if (llamadas.empty()) {
            cout << "No hay llamadas en el historial.\n";
            return;
        }
        string numero = llamadas.top();
        llamadas.pop();
        cout << "Llamada deshecha: " << numero << "\n";
    }
};

int main() {
    HistorialLlamadas historial;
    historial.agregarLlamada("123-456-7890");
    historial.agregarLlamada("987-654-3210");
    historial.agregarLlamada("555-123-4567");

    historial.mostrarHistorial();

    historial.deshacerLlamada();
    historial.mostrarHistorial();

    return 0;
}
