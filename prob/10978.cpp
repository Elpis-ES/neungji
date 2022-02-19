#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll dp_arr[21];

ll dp(int i){
    if(dp_arr[i] != -1){
        return dp_arr[i];
    }
    dp_arr[i] = (i-1) * (dp(i-2) + dp(i-1));
    return dp_arr[i];
}

int main(){
    int n, k;
    memset(dp_arr, -1, sizeof(ll) * 21);
    dp_arr[1] = 0;
    dp_arr[2] = 1;
    dp_arr[3] = 2;
    dp_arr[4] = 9;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %d", &k);
        printf("%lld\n", dp(k));
    }
}
