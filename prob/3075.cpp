#include <bits/stdc++.h>
#define ll long long
using namespace std;

int p;
vector<int> ppl;
vector<vector<pair<int, ll>>> m;

ll dist(int to){
    vector<ll> dist (p + 1, LLONG_MAX);
    priority_queue<pair<ll, int>> pq;

    dist[to] = 0;
    pq.emplace(0, to);

    while(!pq.empty()){
        auto [cur_dist, cur_pos] = pq.top();
        cur_dist = -cur_dist;
        pq.pop();

        if(dist[cur_pos] < cur_dist){
            continue;
        }
        for(const auto &[nxt_pos, nxt_dist] : m[cur_pos]){
            if(dist[nxt_pos] > cur_dist + nxt_dist){
                dist[nxt_pos] = cur_dist + nxt_dist;
                pq.emplace(-dist[nxt_pos], nxt_pos);
            }
        }
    }

    ll ret = 0;
    for(const auto &target : ppl){
        if(dist[target] == LLONG_MAX){
            ret = LLONG_MAX;
            break;
        }
        ret += dist[target] * dist[target];
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, tmp;
    cin >> t;
    int n, q, from, to;
    ll d;
    for(int T = 0; T < t; T++){
        cin >> n >> p >> q;
        ppl = vector<int>();
        m = vector<vector<pair<int, ll>>> (p + 1, vector<pair<int, ll>>());
        for(int i = 0; i < n; i++){
            cin >> tmp;
            ppl.emplace_back(tmp);
        }
        for(int i = 0; i < q; i++){
            cin >> from >> to >> d;
            m[from].emplace_back(to, d);
            m[to].emplace_back(from, d);
        }
        ll val = LLONG_MAX;
        int galaxy;
        for(int i = 1; i <= p; i++){
            ll target = dist(i);
            if(target < val){
                val = target;
                galaxy = i;
            }
        }
        cout << galaxy << " " << val << "\n";
    }
}
