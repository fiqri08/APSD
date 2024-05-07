#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int myarray = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[myarray]) {
                myarray = j;
            }
        }
        else if (myarray != i) {
            swap(arr[i], arr[myarray]);
        }
        else if ()
    }
}

int main() {
    int n;
    cout << "Masukkan panjang array: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen-elemen array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Array sebelum diurutkan: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);

    cout << "Array setelah diurutkan: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
