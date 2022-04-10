#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    ll m;
    cin >> n >> k >> m;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i++){
        ll p, c;
        cin >> p >> c;
        v.emplace_back(c, p);
    }
    sort(v.begin(), v.end());
    priority_queue<tuple<ll, ll, ll>> pq;
    int cnt = 0;
    for(auto [c, p]: v){
        if(k > 0){
            if(m >= c){
                // Can buy
                pq.emplace(-(p - c), c, p);
                k--;
                m -= c;
                cnt++;
            }
        }
        else{
            auto [_, c_e, p_e] = pq.top();
            if(p_e + c < p + c_e){
                // Try swap;
                if(m + c_e - c - p_e >= 0){
                    m = m + c_e - c - p_e;
                    pq.pop();
                    pq.emplace(-(p - c), c, p);
                    cnt++;
                }
            }
            else{
                if(m >= p){
                    m -= p;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << "\n";
}
