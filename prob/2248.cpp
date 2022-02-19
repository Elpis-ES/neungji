#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll dp_arr[32][32];

ll dp_cnt(int n, int l){
    if(dp_arr[n][l] != -1){
        return dp_arr[n][l];
    }
    else if(l < 0 || n <= 0){
        return 0;
    }
    ll ret;
    if(l > n){
        l = n;
    }
    if(l == n){
        ret = 1 << n;
    }
    else if(l == 0){
        ret = 1;
    }
    else{
        ret = dp_cnt(n-1, l-1) + dp_cnt(n-1, l);
    }
    dp_arr[n][l] = ret;
    return ret;
}

ll dp(int n, int l, ll i){
    if(n == 0 || l == 0 || i == 0){
        return 0;
    }
    ll cur = dp_cnt(n-1, l);
    if(cur > i){
        return dp(n-1, l, i);
    }
    else{
        return (1 << (n-1)) + dp(n-1, l-1, i-cur);
    }
}


int main(){
    int N, L;
    ll I;
    memset(dp_arr, -1, sizeof(ll) * 32 * 32);
    scanf(" %d %d %lld", &N, &L, &I);
    ll res = dp(N, L, I - 1);
    string s;
    for(int i = 0; i < N; i++){
        s.push_back(res % 2 ? '1' : '0');
        res = res >> 1;
    }
    reverse(s.begin(), s.end());
    printf("%s\n", s.c_str());
}
