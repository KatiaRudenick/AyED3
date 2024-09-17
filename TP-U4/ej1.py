#Representa a cada paciente en la lista.
class Paciente:
    def __init__(self, id, nombre, edad):
        self.id = id
        self.nombre = nombre
        self.edad = edad
        self.siguiente = None

#Puntero 'head' para referenciar el primer nodo de la lista.
class ListaPacientes:
    def __init__(self):
        self.head = None

    def registrar_paciente(self, id, nombre, edad):
        nuevo_paciente = Paciente(id, nombre, edad)
        if self.head is None:
            self.head = nuevo_paciente
        else:
            actual = self.head
            while actual.siguiente:
                actual = actual.siguiente
            actual.siguiente = nuevo_paciente

    def modificar_paciente(self, id, nuevo_nombre, nueva_edad):
        actual = self.head
        while actual:
            if actual.id == id:
                actual.nombre = nuevo_nombre
                actual.edad = nueva_edad
                return
            actual = actual.siguiente
        print("Paciente no encontrado.")

    def eliminar_paciente(self, id):
        actual = self.head
        previo = None
        while actual:
            if actual.id == id:
                if previo:
                    previo.siguiente = actual.siguiente
                else:
                    self.head = actual.siguiente
                return
            previo = actual
            actual = actual.siguiente
        print("Paciente no encontrado.")

    def listar_pacientes(self):
        actual = self.head
        if not actual:
            print("No hay pacientes registrados.")
        while actual:
            print(f"ID: {actual.id}, Nombre: {actual.nombre}, Edad: {actual.edad}")
            actual = actual.siguiente

def menu():
    lista = ListaPacientes()
    while True:
        print("\n--- Menú del Sistema de Pacientes ---")
        print("1. Registrar Paciente")
        print("2. Modificar Paciente")
        print("3. Eliminar Paciente")
        print("4. Listar Pacientes")
        print("5. Salir")
        
        opcion = input("Seleccione una opción: ")
        
        if opcion == '1':
            id = int(input("Ingrese el ID del paciente: "))
            nombre = input("Ingrese el nombre del paciente: ")
            edad = int(input("Ingrese la edad del paciente: "))
            lista.registrar_paciente(id, nombre, edad)
            print("Paciente registrado exitosamente.")
        elif opcion == '2':
            id = int(input("Ingrese el ID del paciente a modificar: "))
            nuevo_nombre = input("Ingrese el nuevo nombre del paciente: ")
            nueva_edad = int(input("Ingrese la nueva edad del paciente: "))
            lista.modificar_paciente(id, nuevo_nombre, nueva_edad)
        elif opcion == '3':
            id = int(input("Ingrese el ID del paciente a eliminar: "))
            lista.eliminar_paciente(id)
        elif opcion == '4':
            lista.listar_pacientes()
        elif opcion == '5':
            print("Saliendo del sistema...")
            break
        else:
            print("Opción no válida. Por favor, intente nuevamente.")

# Ejecución del menú
menu()
