#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int>>> g;
vector<int> dist;

int dijkstra(int src, int dst){
    dist = vector<int> (n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);

    while(!pq.empty()){
        auto [cur_dist, cur_pos] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();

        if(dist[cur_pos] < cur_dist){
            continue;
        }
        for(auto it = g[cur_pos].begin(); it!= g[cur_pos].end(); it++){
            if(dist[it->first] > it->second + cur_dist){
                dist[it->first] = it->second + cur_dist;
                pq.emplace(-dist[it->first], it->first);
            }
        }
    }

    return dist[dst];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, x;

    cin >> n >> m >> x;
    x--;
    g = vector<vector<pair<int, int>>> (n, vector<pair<int, int>> ());

    int f, t, d;
    for(int i = 0; i < m; i++){
        cin >> f >> t >> d;
        g[f-1].emplace_back(t-1, d);
    }
    vector<int> dist_from(n);
    for(int i = 0; i < n; i++){
        dist_from[i] = dijkstra(i, x);
    }
    dijkstra(x, 0);

    int max_time = -1;
    for(int i = 0; i < n; i++){
        max_time = max(max_time, dist_from[i] + dist[i]);
    }
    cout << max_time << "\n";

}
