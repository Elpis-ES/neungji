#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<pair<ll, ll>> s;

    ll n;
    ll total = 0;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll tmp;
        cin >> tmp;
        while(!s.empty()){
            auto [h, l] = s.top();
            if(h <= tmp){
                s.pop();
                total += (i - l);
            }
            else{
                break;
            }
        }
        s.emplace(tmp, i + 1);
    }

    while(!s.empty()){
        auto [h, l] = s.top();
        s.pop();
        total += (n - l);
    }

    cout << total << "\n";
}
