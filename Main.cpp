#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 100;

struct Objeto {
    char nombre;
    double valor;
    double peso;
    double relacion;
};

void mezclarObjetos(Objeto objetos[], int inicio, int medio, int fin) {
    Objeto auxiliar[MAX];

    int i = inicio;
    int j = medio + 1;
    int k = inicio;

    while (i <= medio && j <= fin) {
        if (objetos[i].relacion >= objetos[j].relacion) {
            auxiliar[k] = objetos[i];
            i++;
        } else {
            auxiliar[k] = objetos[j];
            j++;
        }
        k++;
    }

    while (i <= medio) {
        auxiliar[k] = objetos[i];
        i++;
        k++;
    }

    while (j <= fin) {
        auxiliar[k] = objetos[j];
        j++;
        k++;
    }

    for (int x = inicio; x <= fin; x++) {
        objetos[x] = auxiliar[x];
    }
}

void ordenarObjetos(Objeto objetos[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;

        ordenarObjetos(objetos, inicio, medio);
        ordenarObjetos(objetos, medio + 1, fin);

        mezclarObjetos(objetos, inicio, medio, fin);
    }
}

//  PROBLEMA 1: 

void mochilaFraccional() {
    Objeto objetos[MAX];

    int n;
    double capacidad;

    cout << "\n--- MOCHILA FRACCIONAL ---\n";

    cout << "Cantidad de objetos: ";
    cin >> n;

    if (n <= 0 || n > MAX) {
        cout << "Cantidad de objetos no valida.\n";
        return;
    }

    cout << "Capacidad de la mochila: ";
    cin >> capacidad;

    if (capacidad <= 0) {
        cout << "La capacidad debe ser mayor que cero.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nObjeto " << i + 1 << endl;

        cout << "Nombre (una letra): ";
        cin >> objetos[i].nombre;

        cout << "Valor: ";
        cin >> objetos[i].valor;

        cout << "Peso: ";
        cin >> objetos[i].peso;

        if (objetos[i].valor < 0 || objetos[i].peso <= 0) {
            cout << "El valor no puede ser negativo y el peso debe ser mayor que cero.\n";
            return;
        }

        objetos[i].relacion = objetos[i].valor / objetos[i].peso;
    }

    ordenarObjetos(objetos, 0, n - 1);

    double pesoUtilizado = 0;
    double valorTotal = 0;

    cout << "\nObjetos seleccionados:\n";

    for (int i = 0; i < n; i++) {
        double espacio = capacidad - pesoUtilizado;

        if (espacio <= 0) {
            break;
        }

        double pesoTomado;
        double valorObtenido;

        if (objetos[i].peso <= espacio) {

            pesoTomado = objetos[i].peso;
            valorObtenido = objetos[i].valor;

            cout << "Objeto " << objetos[i].nombre << ": completo";
        } else {
            pesoTomado = espacio;
            valorObtenido = objetos[i].valor *
                            (pesoTomado / objetos[i].peso);

            cout << "Objeto " << objetos[i].nombre << ": parcial";
        }

        double porcentaje = (pesoTomado / objetos[i].peso) * 100;

        pesoUtilizado += pesoTomado;
        valorTotal += valorObtenido;

        cout << " (" << fixed << setprecision(2)
             << porcentaje << "%)";
        cout << " - Peso tomado: " << pesoTomado;
        cout << " - Valor obtenido: " << valorObtenido << endl;
    }

    cout << "\nPeso utilizado: " << fixed << setprecision(2)
         << pesoUtilizado << endl;

    cout << "Capacidad restante: " << capacidad - pesoUtilizado << endl;

    cout << "Valor total obtenido: " << valorTotal << endl;
}

void mezclarCasas(int casas[], int inicio, int medio, int fin) {
    int auxiliar[MAX];

    int i = inicio;
    int j = medio + 1;
    int k = inicio;

    while (i <= medio && j <= fin) {
        if (casas[i] <= casas[j]) {
            auxiliar[k] = casas[i];
            i++;
        } else {
            auxiliar[k] = casas[j];
            j++;
        }
        k++;
    }

    while (i <= medio) {
        auxiliar[k] = casas[i];
        i++;
        k++;
    }

    while (j <= fin) {
        auxiliar[k] = casas[j];
        j++;
        k++;
    }

    for (int x = inicio; x <= fin; x++) {
        casas[x] = auxiliar[x];
    }
}

void ordenarCasas(int casas[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;

        ordenarCasas(casas, inicio, medio);
        ordenarCasas(casas, medio + 1, fin);

        mezclarCasas(casas, inicio, medio, fin);
    }
}

//  PROBLEMA 2
void coberturaAntenas() {
    int casas[MAX];
    int antenas[MAX];

    int n;
    int R;

    cout << "\n--- COBERTURA DE ANTENAS ---\n";

    cout << "Cantidad de casas: ";
    cin >> n;

    if (n <= 0 || n > MAX) {
        cout << "Cantidad de casas no valida.\n";
        return;
    }

    cout << "Radio de cobertura: ";
    cin >> R;

    if (R < 0) {
        cout << "El radio no puede ser negativo.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "Posicion de la casa " << i + 1 << ": ";
        cin >> casas[i];
    }

    ordenarCasas(casas, 0, n - 1);

    int cantidad = 0;
    int i = 0;

    while (i < n) {

        int posicion = casas[i] + R;

        antenas[cantidad] = posicion;
        cantidad++;

        while (i < n && casas[i] <= posicion + R) {
            i++;
        }
    }

    cout << "\nPosiciones de las antenas:\n";

    for (int j = 0; j < cantidad; j++) {
        cout << "Antena " << j + 1 << ": "
             << antenas[j] << endl;
    }

    cout << "Cantidad minima de antenas: "
         << cantidad << endl;
}

int main() {
    int opcion;

    do {
        cout << "\n===== ALGORITMOS VORACES =====\n";
        cout << "1. Mochila fraccional\n";
        cout << "2. Cobertura de antenas\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        if (opcion == 1) {
            mochilaFraccional();
        } else if (opcion == 2) {
            coberturaAntenas();
        } else if (opcion == 3) {
            cout << "\nPrograma finalizado.\n";
        } else {
            cout << "\nOpcion no valida.\n";
        }

    } while (opcion != 3);

    return 0;
}