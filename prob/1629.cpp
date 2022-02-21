#include <bits/stdc++.h>

using namespace std;

int mod(int a, int b, int c){
    if(b == 1){
        return a % c;
    }
    int val =  mod(a, b/2, c);
    if(b % 2 == 1){
        return (((val * val) % c) * mod(a, 1, c)) % c;
    }
    else{
        return ((val * val) % c);
    }
}

int main(void){
    int a, b, c;
    scanf(" %d %d %d", &a, &b, &c);
    printf("%d\n", mod(a, b, c));
}
