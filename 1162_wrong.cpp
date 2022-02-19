#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, f, t;
    ll l;
    priority_queue<tuple<ll, int, int>> pq;

    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> g (n);
    vector<vector<ll>> d(k+1, vector<ll> (n, LLONG_MAX));

    for(int i = 0; i < m; i++){
        cin >> f >> t >> l;
        f--;
        t--;
        g[f].emplace_back(t, l);
        g[t].emplace_back(f, l);
    }

    pq.emplace(0, k, 0);
    d[k][0] = 0;

    while(!pq.empty()){
        auto [cur_dist, road, cur_pos] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();

        if(d[road][cur_pos] < cur_dist){
            continue;
        }

        for(auto it = g[cur_pos].begin(); it != g[cur_pos].end(); it++){
            if(road != 0){
                if(d[road - 1][it->first] > cur_dist){
                    d[road - 1][it->first] = cur_dist;
                    pq.emplace(-d[road - 1][it->first], road - 1, it->first);
                }
            }
            if(d[road][it->first] > cur_dist + it->second){
                d[road][it->first] = cur_dist + it->second;
                pq.emplace(-d[road][it->first], road, it->first);
            }
        }
    }
    ll ret = LLONG_MAX;
    for(int i = 0; i <= k; i++){
        ret = min(ret, d[i][n-1]);
    }
    cout << ret << "\n";

}
