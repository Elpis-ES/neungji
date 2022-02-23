#include <bits/stdc++.h>

using namespace std;

vector<int> price;
vector<vector<pair<int, int>>> g;
int n, m;

int get_price(int i){
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>> pq;
    dist[i] = 0;
    pq.emplace(0, i);

    while(!pq.empty()){
        auto[cur_dist, cur_pos] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();

        if(dist[cur_pos] < cur_dist){
            continue;
        }

        for(auto const& [nxt_pos, nxt_dist] : g[cur_pos]){
            if(dist[nxt_pos] > cur_dist + nxt_dist){
                dist[nxt_pos] = cur_dist + nxt_dist;
                pq.emplace(-cur_dist - nxt_dist, nxt_pos);
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; i++){
        if(dist[i] <= m){
            ret += price[i];
        }
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r;
    cin >> n >> m >> r;

    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        price.emplace_back(tmp);
    }


    g = vector<vector<pair<int, int>>> (n, vector<pair<int, int>>());
    int f, t, d;
    for(int i = 0; i < r; i++){
        cin >> f >> t >> d;
        g[f - 1].emplace_back(t - 1, d);
        g[t - 1].emplace_back(f - 1, d);
    }

    int max_val = -1;
    for(int i = 0; i < n; i++){
        max_val = max(max_val, get_price(i));
    }
    cout << max_val << "\n";

}
