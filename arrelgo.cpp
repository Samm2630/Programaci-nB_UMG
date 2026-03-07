#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Ingresa un numero entero positivo" << endl;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++){
        array[i] = n - i;
    }
    cout << " n = ";
    for (int i = 0; i < n; i++){
        cout << array[i];
        if (i < n - 1){
            cout << " , ";
        }
    }
    return 0;
}