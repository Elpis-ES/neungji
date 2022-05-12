#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll l = 0;
    ll r = 1000000000;
    vector<ll> v(n);
    for(auto &i : v){
        cin >> i;
    }

    ll result = 0;

    while(l < r){
        ll cur_l = (l + r) / 2;
        ll cur_r = cur_l + 1;
        ll result_l = 0;
        ll result_r = 0;

        for(ll i = 0; i < n; i++){
            result_l += abs(v[i] - cur_l * i);
            result_r += abs(v[i] - cur_r * i);
        }

        if(result_l > result_r){
            result = result_r;
            l = cur_r;
        }
        else{
            result = result_l;
            r = cur_l;
        }
    }
    cout << result << "\n";

}

