#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000009

int dp_arr[1000001];

int main(){
    dp_arr[0] = 0;
    dp_arr[1] = 1;
    dp_arr[2] = 2;
    dp_arr[3] = 4;

    int t, n;
    scanf(" %d", &t);
    for(int i = 0; i < t; i++){
        scanf(" %d", &n);
        if (dp_arr[n] != 0){
            printf("%d\n", dp_arr[n]);
        }
        else{
            for(int j = 4; j <= n; j++){
                dp_arr[j] = (dp_arr[j-1] + dp_arr[j-2] + dp_arr[j-3]) % MOD;
            }
            printf("%d\n", dp_arr[n]);
        }
    }

    return 0;
}
