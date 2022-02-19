#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll dp_arr[61][61];

ll dp(int full, int half){
    if(dp_arr[full][half] != 0){
        return dp_arr[full][half];
    }
    if(full < 0 || half < 0){
    }
    if(full == 0 || full == 1 && half == 0){
        return 1LL;
    }
    ll a = (full - 1 >= 0) ? dp(full - 1, half +1) : 0;
    ll b = (half - 1 >= 0) ? dp(full, half - 1) : 0;
    dp_arr[full][half] = a + b;
    return a+b;
}


int main(){
    int N, n;
    while(true){
        scanf(" %d", &n);
        if(n!=0){
            printf("%lld\n", dp(n, 0));
        }
        else{
            break;
        }
    }
}
