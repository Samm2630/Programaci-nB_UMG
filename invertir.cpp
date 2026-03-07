#include <iostream>
#include <string>
using namespace std;
int main() {
    string text;
    int a, b;
    cout << "Ingrese una cadena de texto: ";
    getline(cin, text);
    cout << "Ingrese el indice inicial: ";
    cin >> a;
    cout << "Ingrese el indice final:";
    cin >> b;
    if (text[0] == '\0') {
        cout << "Error: La cadena de texto no puede estar vacia." << endl;
        return 1;
    }
    int longitud = text.length();
    if (b >= longitud) {
        b = longitud - 1;
    }
    if (a < 0) {
        a = 0;
    }
    while (a < b) {
        char temp = text[a-1];
        text[a-1] = text[b-1];
        text[b-1] = temp;
        a++;
        b--;
    }
    if (a >= b) {
        cout << "Error: El indice inicial debe ser menor que el indice final." << endl;
        return 1;
    }

    cout << "Cadena resultante: " << text << endl;
    return 0;
}