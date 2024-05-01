#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for(int i = 2; i <= 10; i += 2){
        sum += i;
        for (int j = 2; j <= i; j += 2){
        printf("%d ", j);
        if(j !=i){
            printf(" + ");
            }
        }
    printf("= %d\n", sum );
    }
    return 0;
}
