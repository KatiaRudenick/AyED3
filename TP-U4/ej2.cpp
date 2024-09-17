#include <iostream>
#include <list>
#include <string>
using namespace std;

class Paciente {
public:
    int id;
    string nombre;
    int edad;

    Paciente(int id, string nombre, int edad) 
        : id(id), nombre(nombre), edad(edad) {}
};

class SistemaPacientes {
private:
    list<Paciente> pacientes;

public:
    void registrarPaciente(int id, string nombre, int edad) {
        pacientes.push_back(Paciente(id, nombre, edad));
    }

    void modificarPaciente(int id, string nuevoNombre, int nuevaEdad) {
        for (auto& paciente : pacientes) {
            if (paciente.id == id) {
                paciente.nombre = nuevoNombre;
                paciente.edad = nuevaEdad;
                return;
            }
        }
        cout << "Paciente no encontrado.\n";
    }

    void eliminarPaciente(int id) {
        for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
            if (it->id == id) {
                pacientes.erase(it);
                return;
            }
        }
        cout << "Paciente no encontrado.\n";
    }

    void listarPacientes() const {
        if (pacientes.empty()) {
            cout << "No hay pacientes registrados.\n";
            return;
        }
        for (const auto& paciente : pacientes) {
            cout << "ID: " << paciente.id 
                      << ", Nombre: " << paciente.nombre 
                      << ", Edad: " << paciente.edad << '\n';
        }
    }
};

void menu() {
    SistemaPacientes sistema;
    while (true) {
        cout << "\nMenu\n";
        cout << "1. Registrar Paciente\n";
        cout << "2. Modificar Paciente\n";
        cout << "3. Eliminar Paciente\n";
        cout << "4. Listar Pacientes\n";
        cout << "5. Salir\n";
        
        int opcion;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                int id;
                string nombre;
                int edad;
                cout << "Ingrese el ID del paciente: ";
                cin >> id;
                cin.ignore(); // Limpiar el buffer de entrada
                cout << "Ingrese el nombre del paciente: ";
                getline(cin, nombre);
                cout << "Ingrese la edad del paciente: ";
                cin >> edad;
                sistema.registrarPaciente(id, nombre, edad);
                cout << "Paciente registrado exitosamente.\n";
                break;
            }
            case 2: {
                int id;
                string nuevoNombre;
                int nuevaEdad;
                cout << "Ingrese el ID del paciente a modificar: ";
                cin >> id;
                cin.ignore();
                cout << "Ingrese el nuevo nombre del paciente: ";
                getline(cin, nuevoNombre);
                cout << "Ingrese la nueva edad del paciente: ";
                cin >> nuevaEdad;
                sistema.modificarPaciente(id, nuevoNombre, nuevaEdad);
                break;
            }
            case 3: {
                int id;
                cout << "Ingrese el ID del paciente a eliminar: ";
                cin >> id;
                sistema.eliminarPaciente(id);
                break;
            }
            case 4:
                sistema.listarPacientes();
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                return;
            default:
                cout << "Opcion no válida. Por favor, intente nuevamente.\n";
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}
