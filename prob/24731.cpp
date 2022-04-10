#include <bits/stdc++.h>
#define MOD 1000003
#define ll long long

using namespace std;

ll pow2(ll i){
    if(i == 0){
        return 1;
    }
    if(i == 1){
        return 2;
    }
    else{
        ll res = pow2(i >> 1);
        res = (res * res) % MOD;
        if(i % 2){
            res = (res << 1) % MOD;
        }
        return res;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll c = pow2(n);
    ll c_sq = (c * c) % MOD;
    c = (c_sq - ((3 * c) % MOD) + 2);
    if (c < 0){
        c += MOD;
    }
    c = (c * 833336) % MOD;
    cout << c << "\n";
}
