#include <iostream>
#include <string>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

using namespace std;

class Tanque {
private:
    float capacidadRegular;
    float capacidadPremium;
    float capacidadEcoExtra;

public:
    Tanque(float capRegular, float capPremium, float capEcoExtra)
        : capacidadRegular(capRegular), capacidadPremium(capPremium), capacidadEcoExtra(capEcoExtra) {}

    void mostrarCapacidades() {
        cout << "Capacidad Regular: " << capacidadRegular << " litros" << endl;
        cout << "Capacidad Premium: " << capacidadPremium << " litros" << endl;
        cout << "Capacidad EcoExtra: " << capacidadEcoExtra << " litros" << endl;
    }
};

class EstacionDeServicio {
private:
    string nombre;
    string codigo;
    string gerente;
    string region;
    string ubicacionGPS;
    Tanque tanque; // Un tanque asociado a la estación

public:
    // Constructor
    EstacionDeServicio(string n, string c, string g, string r, string gps, Tanque t)
        : nombre(n), codigo(c), gerente(g), region(r), ubicacionGPS(gps), tanque(t) {}

    // Método para mostrar la información de la estación
    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Gerente: " << gerente << endl;
        cout << "Region: " << region << endl;
        cout << "Ubicacion GPS: " << ubicacionGPS << endl;
        tanque.mostrarCapacidades();
    }
};

// Función para generar una capacidad aleatoria entre 100 y 200
float generarCapacidadAleatoria() {
    return rand() % 101 + 100; // Genera un número entre 100 y 200
}

// Función para seleccionar un nombre de gerente aleatorio
string seleccionarGerenteAleatorio() {
    string gerentes[] = {"Juan Luis", "David", "Joselito", "Jhon", "Samuel", "Carlos"};
    return gerentes[rand() % 6]; // Selecciona un nombre aleatorio
}

int main() {
    // Inicializar el generador de números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Crear los tanques para cada estación de servicio con capacidades aleatorias
    Tanque tanqueSur(generarCapacidadAleatoria(), generarCapacidadAleatoria(), generarCapacidadAleatoria());
    Tanque tanqueCentro(generarCapacidadAleatoria(), generarCapacidadAleatoria(), generarCapacidadAleatoria());
    Tanque tanqueNorte(generarCapacidadAleatoria(), generarCapacidadAleatoria(), generarCapacidadAleatoria());

    // Crear las estaciones de servicio automáticamente
    EstacionDeServicio estacionNorte("Estacion Norte", "EN003", seleccionarGerenteAleatorio(), "Norte", "6^12'47.9\"N 75^32'23.2\"W", tanqueNorte);
    EstacionDeServicio estacionSur("Estacion Sur", "ES001", seleccionarGerenteAleatorio(), "Sur", "6^09'12.0\"N 75^36'05.5\"W", tanqueSur);
    EstacionDeServicio estacionCentro("Estacion Centro", "EC002", seleccionarGerenteAleatorio(), "Centro", "6^15'19.2\"N 75^34'21.3\"W", tanqueCentro);

    // Mostrar información de las estaciones
    cout << "Informacion de las estaciones de servicio:" << endl;
    cout << endl;
    estacionNorte.mostrarInfo();
    cout << endl;
    estacionCentro.mostrarInfo();
    cout << endl;
    estacionSur.mostrarInfo();
    cout << endl;

    return 0;
}
