#include <iostream>
#include <list>
#include <string>

using namespace std;

class SistemaTurnos {
private:
    list<string> turnos;  

public:
    
    void registrarCliente(string nombre) {
        turnos.push_back(nombre);  
        cout << "Cliente " << nombre << " registrado.\n";
    }

    // Funcion recursiva para llamar al siguiente cliente
    void llamarSiguienteCliente(int boxNum) {
        if (turnos.empty()) {
            cout << "No hay mas clientes en espera.\n";
            return;
        }

        // Llama al primer cliente en la lista
        string cliente = turnos.front();
        turnos.pop_front();  // Eliminar el cliente de la lista

        cout << "Llamando al siguiente cliente: " << cliente << " - Box nro " << boxNum << "\n";

        // Llamada recursiva al siguiente cliente
        llamarSiguienteCliente(boxNum + 1);
    }

    void mostrarClientes() {
        if (turnos.empty()) {
            cout << "No hay clientes en espera.\n";
            return;
        }

        cout << "Clientes en espera:\n";
        for (const auto& cliente : turnos) {
            cout << cliente << "\n";  
        }
    }
};

int main() {
    SistemaTurnos sistema;

    sistema.registrarCliente("Selena");
    sistema.registrarCliente("Gigi");
    sistema.registrarCliente("Kendall");

    sistema.mostrarClientes();

    // Llama recursivamente a los clientes
    sistema.llamarSiguienteCliente(1);

    return 0;
}
