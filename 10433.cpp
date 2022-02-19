#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int dp_arr[5001][5001];

int dp(int n, int k){
    if(n == 0){
        if(k == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(k < 0){
        return 0;
    }
    if(dp_arr[n][k] != -1){
        return dp_arr[n][k];
    }
    dp_arr[n][k] = ((dp(n-1, k+1) % MOD) + (dp(n-1, k-1) % MOD)) % MOD;
    return dp_arr[n][k];
}


int main(){
    int n, k;
    memset(dp_arr, -1, sizeof(int)*5001*5001);
    scanf(" %d", &n);

    for(int i = 0; i < n; i++){
        scanf(" %d", &k);
        printf("%d\n", dp(k, 0));
    }
}
