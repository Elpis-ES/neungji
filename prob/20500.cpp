#include <bits/stdc++.h>

#define ll long long 
#define MOD 1000000007

using namespace std;

ll dp_arr[1516][15];

int main(){
    memset(dp_arr, 0, sizeof(ll)*1516*15);
    int n;
    scanf(" %d", &n);
    dp_arr[1][5] = 1;
    dp_arr[1][1] = 1;

    for(int i = 2; i <= n; i++){
        for(int prev_mod = 0; prev_mod < 15; prev_mod++){
            dp_arr[i][(prev_mod * 10 + 1) % 15] += dp_arr[i-1][prev_mod];
            dp_arr[i][(prev_mod * 10 + 1) % 15] = dp_arr[i][(prev_mod * 10 + 1) % 15] % MOD;
            dp_arr[i][(prev_mod * 10 + 5) % 15] += dp_arr[i-1][prev_mod];
            dp_arr[i][(prev_mod * 10 + 5) % 15] = dp_arr[i][(prev_mod * 10 + 5) % 15] % MOD;
        }
    }

    printf("%lld\n", dp_arr[n][0]);
}
