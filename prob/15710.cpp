#include <bits/stdc++.h>
#define MOD 1000000007ULL
#define ull long long

using namespace std;
ull num = (1ULL << 31) % MOD;

ull mult(int n){
    if (n == 0){
        return 1;
    }
    else if(n == 1){
        return num;
    }
    ull ret = mult(n / 2);
    printf("MULT(%d): %llu\n", n/2, ret);
    ret = (ret * ret) % MOD;
    if(n % 2){
        ret = (ret * num) % MOD;
    }
    return ret;
}

int main(){
    int a, b, n;
    scanf(" %d %d %d", &a, &b, &n);
    printf("%llu\n", mult(n - 1));
}
