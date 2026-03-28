#include <iostream>
using namespace std;

void Sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;
    Sort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}