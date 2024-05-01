#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for(int f = 2; f <= 20; f +=2){
        sum += f;
        if(f!=20){
            printf("%d + ", f);
        }else{
        printf("%d ", f);
        }
    }
    printf("= %d\n", sum );
    return 0;
}
