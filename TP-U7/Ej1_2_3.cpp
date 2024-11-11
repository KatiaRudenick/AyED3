#include <iostream>
using namespace std;

template <class T>
class ArbolBinario;

template <class T>
class NodoArbol {
private:
    T Info;
    NodoArbol<T> *HijoIzq;
    NodoArbol<T> *HijoDer;

public:
    NodoArbol() : HijoIzq(NULL), HijoDer(NULL) {}
    NodoArbol(T valor) : Info(valor), HijoIzq(NULL), HijoDer(NULL) {}
    T RegresaInfo() { return Info; }
    friend class ArbolBinario<T>;
};

template <class T>
class ArbolBinario {
private:
    NodoArbol<T> *raiz;

    void insertar(NodoArbol<T>*& nodo, T valor) {
        if (nodo == NULL) {
            nodo = new NodoArbol<T>(valor);
        } else if (valor < nodo->Info) {
            insertar(nodo->HijoIzq, valor);
        } else {
            insertar(nodo->HijoDer, valor);
        }
    }

    NodoArbol<T>* eliminar(NodoArbol<T>* nodo, T valor) {
        if (nodo == NULL) return nodo;
        if (valor < nodo->Info) {
            nodo->HijoIzq = eliminar(nodo->HijoIzq, valor);
        } else if (valor > nodo->Info) {
            nodo->HijoDer = eliminar(nodo->HijoDer, valor);
        } else {
            if (nodo->HijoIzq == NULL) {
                NodoArbol<T>* temp = nodo->HijoDer;
                delete nodo;
                return temp;
            } else if (nodo->HijoDer == NULL) {
                NodoArbol<T>* temp = nodo->HijoIzq;
                delete nodo;
                return temp;
            }
            NodoArbol<T>* temp = encontrarMinimo(nodo->HijoDer);
            nodo->Info = temp->Info;
            nodo->HijoDer = eliminar(nodo->HijoDer, temp->Info);
        }
        return nodo;
    }

    NodoArbol<T>* encontrarMinimo(NodoArbol<T>* nodo) {
        while (nodo->HijoIzq != NULL) nodo = nodo->HijoIzq;
        return nodo;
    }

    void preorden(NodoArbol<T>* nodo) {
        if (nodo != NULL) {
            cout << nodo->Info << " ";
            preorden(nodo->HijoIzq);
            preorden(nodo->HijoDer);
        }
    }

    void inorden(NodoArbol<T>* nodo) {
        if (nodo != NULL) {
            inorden(nodo->HijoIzq);
            cout << nodo->Info << " ";
            inorden(nodo->HijoDer);
        }
    }

    void postorden(NodoArbol<T>* nodo) {
        if (nodo != NULL) {
            postorden(nodo->HijoIzq);
            postorden(nodo->HijoDer);
            cout << nodo->Info << " ";
        }
    }

public:
    ArbolBinario() : raiz(NULL) {}

    void insertar(T valor) { insertar(raiz, valor); }
    void eliminar(T valor) { raiz = eliminar(raiz, valor); }
    void mostrarPreorden() { preorden(raiz); cout << endl; }
    void mostrarInorden() { inorden(raiz); cout << endl; }
    void mostrarPostorden() { postorden(raiz); cout << endl; }
};

int main() {
    ArbolBinario<char> arbol;

    // Ejercicio 1: Insertar los elementos para construir el arbol
    char elementos[] = {'G', 'B', 'Q', 'A', 'C', 'K', 'F', 'P', 'D', 'E', 'R', 'H'};
    for (char elemento : elementos) {
        arbol.insertar(elemento);
    }

    // Ejercicio 2: Mostrar estado del arbol tras eliminar elementos
    cout << "Arbol tras eliminar E:" << endl;
    arbol.eliminar('E');
    arbol.mostrarInorden();

    cout << "Arbol tras eliminar C:" << endl;
    arbol.eliminar('C');
    arbol.mostrarInorden();

    cout << "Arbol tras eliminar G:" << endl;
    arbol.eliminar('G');
    arbol.mostrarInorden();

    // Ejercicio 3: Mostrar recorridos
    cout << "Recorrido en preorden:" << endl;
    arbol.mostrarPreorden();

    cout << "Recorrido en inorden:" << endl;
    arbol.mostrarInorden();

    cout << "Recorrido en postorden:" << endl;
    arbol.mostrarPostorden();

    return 0;
}
