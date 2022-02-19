#include <bits/stdc++.h>

using namespace std;

int main(void){
    int A, B, V;
    scanf(" %d %d %d", &A, &B, &V);
    if((V-A)%(A-B) == 0){
        printf("%d\n",  (V - B) / (A - B));
    }
    else{
        printf("%d\n", (V - B)/(A-B) + 1);
    }
    return 0;
}
