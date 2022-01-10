#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k){
    int remainder = n - (k * (k + 1) / 2);
    if(remainder < 0){
        return -1;
    }
    if(remainder % k == 0){
        return k-1;
    }
    else{
        return k;
    }
}

int main(void){
    int n, k;
    scanf(" %d %d", &n, &k);
    printf("%d\n", solve(n, k));
    return 0;
}
