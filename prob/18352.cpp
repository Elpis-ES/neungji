#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    ll k;
    cin >> n >> m >> k >> x;

    priority_queue<pair<ll, int>> pq;
    vector<ll> dist (n + 1, LLONG_MAX);
    dist[x] = 0;
    pq.emplace(0, x);
    vector<vector<int>> m_arr (n + 1, vector<int>());

    int f, t;
    for(int i = 0; i < m; i++){
        cin >> f >> t;
        m_arr[f].emplace_back(t);
    }

    while(!pq.empty()){
        auto [cur_dist, cur_pos] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();

        if(dist[cur_pos] < cur_dist)
            continue;
        for(auto nxt_pos : m_arr[cur_pos]){
            if(dist[nxt_pos] > cur_dist + 1){
                dist[nxt_pos] = cur_dist + 1;
                pq.emplace(-dist[nxt_pos], nxt_pos);
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == k){
            cout << i << "\n";
            cnt++;
        }
    }
    if(cnt == 0){
        cout << "-1\n";
    }
}
