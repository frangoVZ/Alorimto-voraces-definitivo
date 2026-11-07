#include <iostream>
using namespace std;

struct Objeto {
    char nombre;
    float valor;
    float peso;
    float relacion;
};

void ordenar(Objeto objetos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (objetos[j].relacion < objetos[j + 1].relacion) {
                Objeto aux = objetos[j];
                objetos[j] = objetos[j + 1];
                objetos[j + 1] = aux;
            }
        }
    }
}

void mochila(Objeto objetos[], int n, float capacidad) {
    float valorTotal = 0;

    ordenar(objetos, n);

    cout << "\nObjetos seleccionados:\n";

    for (int i = 0; i < n; i++) {
        if (capacidad > 0) {
            if (objetos[i].peso <= capacidad) {
                
                capacidad = capacidad - objetos[i].peso;
                valorTotal = valorTotal + objetos[i].valor;

                cout << objetos[i].nombre
                     << ": completo"
                     << endl;
            } else {

                float fraccion = capacidad / objetos[i].peso;
                float valorObtenido = objetos[i].valor * fraccion;

                valorTotal = valorTotal + valorObtenido;

                cout << objetos[i].nombre
                     << ": " << fraccion * 100 << "% del objeto"
                     << endl;

                capacidad = 0;
            }
        }
    }

    cout << "\nValor total obtenido: " << valorTotal << endl;
}

int main() {
    int n;
    float capacidad;

    cout << "Cantidad de objetos: ";
    cin >> n;

    Objeto objetos[100];

    for (int i = 0; i < n; i++) {
        cout << "\nObjeto " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> objetos[i].nombre;

        cout << "Valor: ";
        cin >> objetos[i].valor;

        cout << "Peso: ";
        cin >> objetos[i].peso;

        objetos[i].relacion = objetos[i].valor / objetos[i].peso;
    }

    cout << "\nCapacidad de la mochila: ";
    cin >> capacidad;

    mochila(objetos, n, capacidad);

    return 0;
}