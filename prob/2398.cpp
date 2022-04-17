#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int, int>>> g;

pair<vector<int>, vector<int>> dijkstra(int start){

    vector<int> len(n + 1, INT_MAX);
    vector<int> prev(n + 1);
    prev[start] = -1;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);
    len[start] = 0;

    while(!pq.empty()){
        auto [w, v] = pq.top();
        pq.pop();

        w = -w;

        if(w > len[v]){
            continue;
        }
        for(auto [nxt_v, nxt_w] : g[v]){
            if(w + nxt_w < len[nxt_v]){
                len[nxt_v] = w + nxt_w;
                pq.emplace(-len[nxt_v], nxt_v);
                prev[nxt_v] = v;
            }
        }
    }
    return make_pair(len, prev);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    g = vector<vector<pair<int, int>>> (n + 1);

    for(int i = 0; i < m; i++){
        int p, q, w;
        cin >> p >> q >> w;
        g[p].emplace_back(q, w);
        g[q].emplace_back(p, w);
    }

    vector<int> p(3);
    for(auto &it : p){
        cin >> it;
    }
    vector<vector<int>> weight(3);
    vector<vector<int>> prev(3);

    for(int i = 0; i < 3; i++){
        auto[ww, pp] = dijkstra(p[i]);
        weight[i] = ww;
        prev[i] = pp;
    }

    int min_weight = INT_MAX;
    int min_point = 0;
    for(int i = 1; i <= n; i++){
        int cur_weight = weight[0][i] + weight[1][i] + weight[2][i];
        if(cur_weight < min_weight){
            min_weight = cur_weight;
            min_point = i;
        }
    }
    vector<pair<int, int>> path;
    for(int i = 0; i < 3; i++){
        int cur = min_point;
        while(true){
            if(prev[i][cur] == -1){
                break;
            }
            else{
                path.emplace_back(cur, prev[i][cur]);
                cur = prev[i][cur];
            }
        }
    }

    cout << min_weight << " " << path.size() << "\n";
    for(auto [p, q] : path){
        cout << p << " " << q << "\n";
    }

}
