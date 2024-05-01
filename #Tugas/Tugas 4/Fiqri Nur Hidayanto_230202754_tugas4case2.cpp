#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for(int f = 1; f <= 19; f +=2){
        sum += f;
        if(f!=19){
            printf("%d + ", f);
        }else{
        printf("%d ", f);
        }
    }
    printf("= %d\n", sum );
    return 0;
}
