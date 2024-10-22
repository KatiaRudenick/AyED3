#include <iostream>
#include <list>
#include <string>

using namespace std;

class SistemaTurnos {
private:
    list<pair<string, int>> turnos;  // Lista de clientes con su tiempo de espera inicializado en 0

public:
    
    void registrarCliente(string nombre) {
        turnos.push_back(make_pair(nombre, 0));  // Se agrega el cliente a la lista con tiempo de espera 0
        cout << "Cliente " << nombre << " registrado.\n";
    }

    void calcularTiempoEsperaRecursivo(list<pair<string, int>>::iterator it, int tiempoEspera) {
        if (it == turnos.end()) return;  

        // Actualizar el tiempo de espera del cliente actual
        it->second = tiempoEspera;

        // Llamada recursiva con el tiempo de espera incrementado en 5 minutos para el siguiente cliente
        calcularTiempoEsperaRecursivo(next(it), tiempoEspera + 5);
    }

    void calcularTiempoEspera() {
        calcularTiempoEsperaRecursivo(turnos.begin(), 0);
    }

    void mostrarClientes() {
        cout << "Clientes en espera y su tiempo estimado de espera:\n";
        for (const auto& cliente : turnos) {
            cout << cliente.first << " - Tiempo de espera: " << cliente.second << " minutos\n";
        }
    }

    void llamarSiguienteCliente(int boxNum) {
        if (turnos.empty()) {
            cout << "No hay más clientes en espera.\n";
            return;
        }

        // Llamar al primer cliente en la lista
        string cliente = turnos.front().first;
        int tiempoEspera = turnos.front().second;
        turnos.pop_front();  // Eliminar el cliente de la lista

        cout << "Llamando al siguiente cliente: " << cliente << " - Box nro " << boxNum 
             << " - Tiempo de espera: " << tiempoEspera << " minutos\n";

        // Llamada recursiva al siguiente cliente
        llamarSiguienteCliente(boxNum + 1);
    }
};

int main() {
    SistemaTurnos sistema;

    // Registrando clientes
    sistema.registrarCliente("Selena");
    sistema.registrarCliente("Gigi");
    sistema.registrarCliente("Kendall");

    // Calcular tiempos de espera para todos los clientes desde el inicio de la lista
    sistema.calcularTiempoEspera();

    // Mostrando clientes en espera con su tiempo estimado
    sistema.mostrarClientes();

    // Llamar recursivamente a los clientes
    sistema.llamarSiguienteCliente(1);

    return 0;
}
