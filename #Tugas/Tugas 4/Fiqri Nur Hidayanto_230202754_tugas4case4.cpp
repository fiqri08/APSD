#include <iostream>
using namespace std;

int main() {
    int sum;
    for(int i = 1; i <= 10; i += 2){
        sum = 1;
        for (int j = 1; j <= i; j += 2){
                if(j !=1)
         cout << " * ";
        cout << j;
            sum = sum * j;
        }
   printf(" = %d\n", sum );
    }
    return 0;
}

