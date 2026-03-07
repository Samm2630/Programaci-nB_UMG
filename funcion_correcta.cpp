#include <iostream>
using namespace std;
int addFive(int num){
    num += 5;
    return num;
}
int main(){
    int number;
    cout << "Ingrese un numero: ";
    cin >> number;
    int result = addFive(number);
    cout << "El resultado es: " << result << endl;
    return 0;
}