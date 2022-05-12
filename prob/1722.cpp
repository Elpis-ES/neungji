#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> fact = {1, 1};

    while(fact.size() != 21){
        fact.emplace_back(fact.size() * fact[fact.size() - 1]);
    }

    ll t;
    cin >> t;
    vector<bool> used(n, false);
    if(t == 2){
        ll ret = 1;
        for(ll i = 0; i < n; i++){
            ll num;
            cin >> num;
            used[num - 1] = true;
            ll cnt = 0;
            for(ll j = 0; j < num; j++){
                if(used[j] == false){
                    cnt++;
                }
            }
            ret += cnt * fact[n - i - 1];
        }
        cout << ret << "\n";

    }
    else{
        ll cnt;
        cin >> cnt;
        cnt --;

        for(ll i = 0; i < n; i++){
            ll quot = cnt / fact[n - i - 1];
            cnt = cnt % fact[n - i - 1];

            ll idx = -1;
            while(quot >= 0){
                idx++;
                if(used[idx] == false){
                    quot--;
                }
            }
            cout << idx + 1 << " ";
            used[idx] = true;
        }

        cout << "\n";

    }

}
