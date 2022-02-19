#include <bits/stdc++.h>
#define ll long long

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

    int m;

    cin >> n >> m;
    g = vector<vector<pair<int, int>>> (n, vector<pair<int, int>> ());

    int f, t, d;
    for(int i = 0; i < m; i++){
        cin >> f >> t >> d;
        g[f-1].emplace_back(t-1, d);
        g[t-1].emplace_back(f-1, d);
    }

    int a, b;
    cin >> a >> b;
    a--;
    b--;

    dijkstra(0, n-1);
    ll sa = (ll)dist[a];
    ll sb = (ll)dist[b];

    dijkstra(n-1, 0);
    ll ad = (ll)dist[a];
    ll bd = (ll)dist[b];

    ll ab = (ll)dijkstra(a, b);

    ll min_dist = LLONG_MAX;
    min_dist = min(min_dist, sa+ab+bd);
    min_dist = min(min_dist, sb+ab+ad);

    if(min_dist >= INT_MAX){
        min_dist = -1;
    }
    cout << min_dist << "\n";

}
