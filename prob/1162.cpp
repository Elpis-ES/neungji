#include <bits/stdc++.h>

using namespace std;

vector<list<pair<int, int>>> g;
vector<vector<int>> dp_arr;
vector<vector<bool>> visited;
int n;

int dijkstra(int start){
    vector<int> d (n, INT_MAX);

    priority_queue<pair<int, int>> pq;
    d[start] = 0;
    pq.emplace(0, start);
    while(!pq.empty()){
        auto [cur_dist, cur_pos] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();
        for(auto it = g[cur_pos].begin(); it!= g[cur_pos].end(); it++){
            if(d[cur_pos] < cur_dist){
                continue;
            }
            if(d[it->first] > cur_dist + it->second){
                d[it->first] = cur_dist + it->second;
                pq.emplace(-d[it->first], it->first);
            }
        }
    }
    return d[n-1];
}

int dp(int start, int road){
    if(dp_arr[start][road] != -1){
        return dp_arr[start][road];
    }
    if(start == n - 1){
        return 0;
    }
    int ret = INT_MAX;
    if(road == 0){
        ret = dijkstra(start);
    }
    else{
        for(auto it = g[start].begin(); it != g[start].end(); it++){
            if(!visited[road][it->first]){
                visited[road][it->first] = true;
                ret = min(ret, it->second + dp(it->first, road));
            }
            ret = min(ret, dp(it->first, road - 1));
        }
    }
    dp_arr[start][road] = ret;
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, k, f, t, l;

    cin >> n >> m >> k;

    g = vector<list<pair<int, int>>> (n);
    visited = vector<vector<bool>> (k+1, vector<bool>(n+1, false));

    for(int i = 0; i < m; i++){
        cin >> f >> t >> l;
        f--;
        t--;
        g[f].emplace_back(t, l);
        g[t].emplace_back(f, l);
    }

    dp_arr = vector<vector<int>> (k+1, vector<int>(n+1, -1));
    int ret = dp(0, k);
    cout << ret << "\n";

}
