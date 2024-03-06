//Programa que cambia de posisicion cada digito de un numerodecimal
#include <iostream>
using namespace std;

int main() {

    cout << "Ingresar un numero decimal: ";
    string numero;
    cin >> numero;
    if(numero== " "){
    	cout<<"ingrese un valor decimal"<<endl;
	}else
	{
    string numeroRevertido;
    for (int i = numero.length() - 1; i >= 0; --i) {
        numeroRevertido += numero[i];
    
    cout << "posicion intercambiada: " << numeroRevertido << endl;
}
}
    return 0;
}
