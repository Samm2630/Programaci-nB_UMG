#include <iostream>
#include <string>
using namespace std;
int main(){
    string bin;
    long long decimal = 0;
    cout << "Ingrese un numero binario: (solo 0 y 1)" << endl;
    cin >> bin;

    for(char c : bin){
        if (c == '1' || c == '0'){
            decimal = decimal * 2 + (c - '0');
        } else {
            cout << "Error: El numero binario solo puede contener 0 y 1." << endl;
            return 1;
        }
    }
    cout << "El numero decimal es: " << decimal << endl;
}