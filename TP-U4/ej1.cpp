#include <iostream>
#include <string>

using namespace std;

//Representa un nodo en la lista vinculada
class Paciente {
public:
    int id;
    string nombre;
    int edad;
    Paciente* siguiente;

    Paciente(int id, string nombre, int edad) 
        : id(id), nombre(nombre), edad(edad), siguiente(nullptr) {}
};

class ListaPacientes {
private:
    Paciente* head; //'head' apunta al primer nodo de la lista

public:
    ListaPacientes() : head(nullptr) {}

    ~ListaPacientes() {
        while (head) {
            Paciente* temp = head;
            head = head->siguiente;
            delete temp;
        }
    }

    void registrarPaciente(int id, string nombre, int edad) {
        Paciente* nuevoPaciente = new Paciente(id, nombre, edad);
        if (head == nullptr) {
            head = nuevoPaciente;
        } else {
            Paciente* actual = head;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoPaciente;
        }
    }

    void modificarPaciente(int id, string nuevoNombre, int nuevaEdad) {
        Paciente* actual = head;
        while (actual) {
            if (actual->id == id) {
                actual->nombre = nuevoNombre;
                actual->edad = nuevaEdad;
                return;
            }
            actual = actual->siguiente;
        }
        cout << "Paciente no encontrado.\n";
    }

    void eliminarPaciente(int id) {
        Paciente* actual = head;
        Paciente* previo = nullptr;
        while (actual) {
            if (actual->id == id) {
                if (previo) {
                    previo->siguiente = actual->siguiente;
                } else {
                    head = actual->siguiente;
                }
                delete actual;
                return;
            }
            previo = actual;
            actual = actual->siguiente;
        }
        cout << "Paciente no encontrado.\n";
    }

    void listarPacientes() const {
        if (head == nullptr) {
            cout << "No hay pacientes registrados.\n";
            return;
        }
        Paciente* actual = head;
        while (actual) {
            cout << "ID: " << actual->id 
                      << ", Nombre: " << actual->nombre 
                      << ", Edad: " << actual->edad << '\n';
            actual = actual->siguiente;
        }
    }
};

void menu() {
    ListaPacientes lista;
    while (true) {
        cout << "\n--- Menú del Sistema de Pacientes ---\n";
        cout << "1. Registrar Paciente\n";
        cout << "2. Modificar Paciente\n";
        cout << "3. Eliminar Paciente\n";
        cout << "4. Listar Pacientes\n";
        cout << "5. Salir\n";
        
        int opcion;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        
        switch (opcion) {
            case 1: {
                int id;
                string nombre;
                int edad;
                cout << "Ingrese el ID del paciente: ";
                cin >> id;
                cin.ignore();
                cout << "Ingrese el nombre del paciente: ";
                getline(cin, nombre);
                cout << "Ingrese la edad del paciente: ";
                cin >> edad;
                lista.registrarPaciente(id, nombre, edad);
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
                lista.modificarPaciente(id, nuevoNombre, nuevaEdad);
                break;
            }
            case 3: {
                int id;
                cout << "Ingrese el ID del paciente a eliminar: ";
                cin >> id;
                lista.eliminarPaciente(id);
                break;
            }
            case 4:
                lista.listarPacientes();
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                return;
            default:
                cout << "Opción no válida. Por favor, intente nuevamente.\n";
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}
