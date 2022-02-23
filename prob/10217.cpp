#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m, k;
    cin >> t;

    for(int asdf = 0; asdf < t; asdf++){
        cin >> n >> m >> k;
        vector<vector<tuple<int, int, int>>> g (n, vector<tuple<int, int, int>>());
        priority_queue<tuple<int, int, int>> pq;
        vector<vector<int>> dist (n, vector<int> (m+1, INT_MAX));
        int u, v, c, d;
        for(int i = 0; i < k; i++){
            cin >> u >> v >> c >> d;
            g[u-1].emplace_back(v-1, c, d);
        }

        dist[0][m] = 0;
        pq.emplace(0, 0, m);
        while(!pq.empty()){
            auto[cur_dist, cur_pos, cur_money] = pq.top();
            cur_dist = -cur_dist;
            pq.pop();

            if(dist[cur_pos][cur_money] < cur_dist){
                continue;
            }
            for(auto const& [nxt_pos, nxt_cost, nxt_dist] : g[cur_pos]){
                int money_left = cur_money - nxt_cost;
                if(money_left >= 0){
                    if(dist[nxt_pos][money_left] > cur_dist + nxt_dist){
                        dist[nxt_pos][money_left] = cur_dist + nxt_dist;
                        for(int mm = money_left - 1; mm >= 0; mm--){
                            if(dist[nxt_pos][mm] > dist[nxt_pos][money_left]){
                                dist[nxt_pos][mm] = dist[nxt_pos][money_left];
                            }
                            else{
                                break;
                            }
                        }
                        pq.emplace(-dist[nxt_pos][money_left], nxt_pos, money_left);
                    }
                }
            }
        }
        int ret = INT_MAX;
        for(int i = 0; i <= m; i++){
            ret = min(ret, dist[n-1][i]);
        }
        if(ret == INT_MAX){
            cout << "Poor KCM\n";
        }
        else{
            cout << ret << "\n";
        }
    }
}
