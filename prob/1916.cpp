#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g (n, vector<pair<int, ll>> ());
    priority_queue<pair<ll, int>> pq;
    vector<ll> dist(n, LLONG_MAX);
    int f, t;
    ll d;
    for(int i = 0; i < m; i++){
        cin >> f >> t >> d;
        g[f-1].emplace_back(t-1, d);
    }
    int src, dst;
    cin >> src >> dst;

    src--;
    dst--;

    dist[src] = 0;
    pq.emplace(0, src);

    while(!pq.empty()){
        auto [cur_dist, cur_pos] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();

        if(cur_dist > dist[cur_pos]){
            continue;
        }
        for(auto it = g[cur_pos].begin(); it != g[cur_pos].end(); it++){
            if(cur_dist + it->second < dist[it->first]){
                dist[it->first] = cur_dist + it->second;
                pq.emplace(-dist[it->first], it->first);
            }
        }
    }
    cout << dist[dst] << "\n";

}
