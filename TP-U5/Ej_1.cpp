#include <iostream>
#include <queue>
#include <string>

using namespace std;

class SistemaTurnos {
private:
   queue<string> turnos;

public:
    void registrarCliente(string nombre) {
        turnos.push(nombre); // Agrega al final de la cola
       cout << "Cliente " << nombre << " registrado.\n";
    }

    void llamarSiguienteCliente(int boxNum) {
        if (turnos.empty()) {
           cout << "No hay más clientes en espera.\n";
            return;
        }
       string cliente = turnos.front(); // Obtiene el primer cliente
        turnos.pop(); // Elimina el primer cliente
       cout << "Llamando al siguiente cliente: " << cliente << " - Box nro " << boxNum << "\n";
    }

    void mostrarClientes() {
       cout << "Clientes en espera:\n";
       queue<string> temp = turnos; // Copia temporal de la cola
        while (!temp.empty()) {
           cout << temp.front() << "\n"; // Muestra el cliente al frente
            temp.pop(); // Elimina el cliente de la copia temporal
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