#include <bits/stdc++.h>

#define ll long long int

using namespace std;
#define MOD 1000000000000000000LL

ll pascal_top[101][101];
ll pascal_bottom[101][101];

pair<ll, ll> combination(ll n, ll k){
    if(pascal_bottom[n][k] != 0LL || pascal_top[n][k] != 0LL){
        return make_pair(pascal_top[n][k], pascal_bottom[n][k]);
    }
    if(k == 0 || k == n){
        return make_pair(0LL, 1LL);
    }
    if(k == 1 || k == n-1){
        return make_pair(0LL , n);
    }
    pair<ll, ll> a = combination(n-1, k-1);
    pair<ll, ll> b = combination(n-1, k);
    ll top = a.first + b.first;
    ll bottom = a.second + b.second;
    if(bottom >= MOD){
        //overflow
        bottom = bottom % MOD;
        top = top + 1;
    }
    pascal_top[n][k] = top;
    pascal_bottom[n][k] = bottom;
    return make_pair(top, bottom);
}

int main(void){
    ll n, k;
    scanf(" %lld %lld", &n, &k);
    pair<ll, ll> p = combination(n, k);
    if(p.first != 0LL){
        printf("%lld", p.first);
    }
    printf("%lld\n", p.second);
    return 0;
}
