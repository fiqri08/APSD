#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int b = 0;
   int total = 110;

    for (int i = 5; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            cout << a;
            b += a;
            if (j < i) {
                cout << " + ";
            }
            a -= 2;
        }
        cout << " = " << b << endl;
        b = 0;
        a = 10;
    }
    cout << "----------" << endl;
    cout << total << endl;

    return 0;
}
