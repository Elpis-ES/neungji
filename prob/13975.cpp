#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<ll> pq;
    ll t, k, tmp;
    ll total = 0;
    ll f, s;
    cin >> t;
    for(ll i = 0; i < t; i++){
        pq = priority_queue<ll> ();
        cin >> k;
        for(ll j = 0; j < k; j++){
            cin >> tmp;
            pq.emplace(-tmp);
        }
        total = 0;
        while(pq.size() >= 2){
            f = pq.top();
            f = -f;
            pq.pop();
            s = pq.top();
            s = -s;
            pq.pop();
            total += (f + s);
            pq.emplace(-f -s);
        }
        cout << total << "\n";
    }
}
