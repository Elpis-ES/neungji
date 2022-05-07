#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;
    vector<unordered_map<int, int>> g(n + 1);
    vector<ll> len(n + 1, LLONG_MAX);
    vector<int> prev(n + 1);
    for(int i = 0; i < m; i++){
        int p, q, l;
        cin >> p >> q >> l;
        g[p][q] = l;
        g[q][p] = l;
    }

    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, 1);
    len[1] = 0;
    prev[1] = 0;

    while(!pq.empty()){
        auto[l, p] = pq.top();
        l = -l;
        pq.pop();
        if(len[p] < l){
            continue;
        }
        for(auto [nxt_p, nxt_l] : g[p]){
            if(len[nxt_p] > nxt_l + l){
                len[nxt_p] = nxt_l + l;
                pq.emplace(-len[nxt_p], nxt_p);
                prev[nxt_p] = p;
            }
        }
    }
    for(auto i : len){
        cout << i << "\n";
    }


}
