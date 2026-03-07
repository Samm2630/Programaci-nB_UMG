#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;
    int array[n];
    int inverso[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> array[i];
    }
    for (int i = 0; i < n; i++) {
        inverso[i] = array[i] * -1;
    }
    cout << "\n Arreglo original: [";
    for (int i = 0; i < n; i++) {
        cout << array[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
    cout << "\nArreglo inverso aditivo: [";
    for (int i = 0; i < n; i++) {
        cout << inverso[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}