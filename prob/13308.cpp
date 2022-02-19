#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    priority_queue<tuple<ll, int, int>> pq;
    vector<ll> w;
    vector<vector<pair<int, ll>>> g(n);
    vector<vector<ll>> d(n, vector<ll> (n, LLONG_MAX));

    ll tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        w.emplace_back(tmp);
    }

    int f, t;
    ll dist;
    for(int i = 0; i < m; i++){
        cin >> f >> t >> dist;
        f--;
        t--;
        g[f].emplace_back(t, dist);
        g[t].emplace_back(f, dist);
    }

    d[0][0] = 0;
    pq.emplace(0, 0, 0);

    while(!pq.empty()){
        auto [cur_dist, cur_pos, last_fuel] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();

        if(cur_pos == n-1){
            cout << ret << "\n";
            return;
        }
        if(d[last_fuel][cur_pos] < cur_dist){
            continue;
        }
        for(auto it = g[cur_pos].begin(); it != g[cur_pos].end(); it++){
            if(w[cur_pos] < w[last_fuel] && d[cur_pos][cur_pos] > cur_dist){
                d[cur_pos][cur_pos] = cur_dist;
                pq.emplace(-d[cur_pos][cur_pos], cur_pos, cur_pos);
            }
            if(d[last_fuel][it->first] > cur_dist + (it->second * w[last_fuel])){
                d[last_fuel][it->first] = cur_dist + (it->second * w[last_fuel]);
                pq.emplace(-d[last_fuel][it->first], it->first, last_fuel);
            }
        }
    }

    ll ret = LLONG_MAX;

    for(int i = 0; i < n; i++){
        ret = min(ret, d[i][n-1]);
    }

    cout << ret << "\n";


}
