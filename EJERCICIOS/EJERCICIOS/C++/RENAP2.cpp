#include <iostream>
#include <vector>
#include <ctime>
#include <locale.h>
using namespace std;
int main() {
	
	setlocale(LC_ALL, "spanish");
    vector<string> nombres;
    vector<string> municipios;
    vector<int> diasNacimiento;
    vector<int> mesesNacimiento;
    vector<int> anosNacimiento;
    vector<bool> esMayorDeEdad;

    int n;

    cout << "REGISTRO" << endl;
    cout << "Personas a registrar ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nombre, municipio;
        int dia, mes, ano;

        cout << "\n Nombre: ";
        cin.ignore();
        getline(cin, nombre);
        nombres.push_back(nombre);

        cout << "\n Municipio ";
        getline(cin, municipio);
        municipios.push_back(municipio);

        cout << "\n Fecha de Nacimiento " << " (dia mes año): ";
        cin >> dia >> mes >> ano;

        diasNacimiento.push_back(dia);
        mesesNacimiento.push_back(mes);
        anosNacimiento.push_back(ano);

        time_t t = time(0);
        tm *ltm = localtime(&t);
        int edadActual = ltm->tm_year + 1900 - ano;
        bool mayorDeEdad = (edadActual > 18 || (edadActual == 18 && ltm->tm_mon > mes - 1) || (edadActual == 18 && ltm->tm_mon == mes - 1 && ltm->tm_mday >= dia));
        esMayorDeEdad.push_back(mayorDeEdad);
    }

    cout << "\n Datos de los ciudadanos:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nombre: " << nombres[i] << endl;
        cout << "municipio: "<<municipios[i]<< endl;
        cout << "Fecha de nacimiento: " << diasNacimiento[i] << "/" << mesesNacimiento[i] << "/" << anosNacimiento[i] << endl;
        if (esMayorDeEdad[i]) {
            cout<< " "<<nombres[i]<<" es mayor de edad." << endl;
        } else {
            cout<< " "<<nombres[i]<<" no es mayor de edad." << endl;
        }
        cout << endl;
    }

    return 0;
}
