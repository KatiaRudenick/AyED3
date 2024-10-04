#include <iostream>
#include <list>
#include <string>

using namespace std;

class SistemaTurnos {
private:
    list<string> turnos; 

public:
    void registrarCliente(string nombre) {
        turnos.push_back(nombre); // Agrega al final de la lista
        cout << "Cliente " << nombre << " registrado.\n";
    }

    void llamarSiguienteCliente(int boxNum) {
        if (turnos.empty()) {
            cout << "No hay más clientes en espera.\n";
            return;
        }
        string cliente = turnos.front(); // Obtiene el primer cliente
        turnos.pop_front(); // Elimina el primer cliente
        cout << "Llamando al siguiente cliente: " << cliente << " - Box nro " << boxNum << "\n";
    }

    void mostrarClientes() {
        cout << "Clientes en espera:\n";
        for (const auto& cliente : turnos) {
            cout << cliente << "\n"; // Muestra cada cliente
        }
    }
};

int main() {
    SistemaTurnos sistema;
    sistema.registrarCliente("Selena");
    sistema.registrarCliente("Gigi");
    sistema.registrarCliente("Kendall");

    sistema.mostrarClientes();

    sistema.llamarSiguienteCliente(1); 
    sistema.llamarSiguienteCliente(2); 
    sistema.llamarSiguienteCliente(3); 

    return 0;
}
