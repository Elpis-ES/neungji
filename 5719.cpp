#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, d, f, t, l;
    vector<list<pair<int, int> > > g;
    vector<list<int> > from;
    vector<int> dist;
    vector<vector<bool> > blocked;
    priority_queue<pair<int, int> > pq;
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        g = vector<list<pair<int, int> > >(n, list<pair<int, int> > ());
        from = vector<list<int> >(n, list<int>());
        dist = vector<int>(n, INT_MAX);
        pq = priority_queue<pair<int, int> >();
        blocked = vector<vector<bool> >(n, vector<bool>(n, false));

        cin >> s >> d;

        for(int i = 0; i < m; i++){
            cin >> f >> t >> l;
            g[f].emplace(g[f].end(), t, l);
        }

        dist[s] = 0;
        pq.emplace(0, s);

        // First Dijkstra
        while(!pq.empty()){
            auto [cur_dist, cur_pt] = pq.top();
            cur_dist = -cur_dist;
            pq.pop();

            for(auto it = g[cur_pt].begin(); it != g[cur_pt].end(); it++){
                if(dist[cur_pt] < cur_dist){
                    continue;
                }
                if(dist[it->first] > cur_dist + it->second){
                    dist[it->first] = cur_dist + it->second;
                    pq.emplace(-dist[it->first], it->first);
                    from[it->first].clear();
                    from[it->first].push_back(cur_pt);
                }
                else if(dist[it->first] == cur_dist + it->second){
                    from[it->first].push_back(cur_pt);
                }
            }
        }

        // Remove edge

        queue<int> remove_queue;
        vector<bool> visited = vector<bool>(n, false);
        remove_queue.emplace(d);
        visited[d] = true;
        while(!remove_queue.empty()){
            int target = remove_queue.front();
            remove_queue.pop();
            for(auto it = from[target].begin(); it != from[target].end(); it++){
                if(!visited[*it]){
                    remove_queue.emplace(*it);
                    visited[*it] = true;
                }
                    blocked[*it][target] = true;
            }
        }

        // Second Dijkstra
        dist = vector<int>(n, INT_MAX);
        dist[s] = 0;
        pq.emplace(0, s);

        while(!pq.empty()){
            auto [cur_dist, cur_pt] = pq.top();
            cur_dist = -cur_dist;
            pq.pop();

            for(auto it = g[cur_pt].begin(); it != g[cur_pt].end(); it++){
                if(blocked[cur_pt][it->first]){
                    continue;
                }
                if(dist[cur_pt] < cur_dist){
                    continue;
                }
                if(dist[it->first] > cur_dist + it->second){
                    dist[it->first] = cur_dist + it->second;
                    pq.emplace(-dist[it->first], it->first);
                }
            }
        }

        cout << (dist[d] == INT_MAX ? -1 : dist[d]) << "\n";
    }

}
