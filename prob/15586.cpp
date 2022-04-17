#include <bits/stdc++.h>

using namespace std;

struct ds{
    vector<int> g;
    vector<int> s;

    ds(int n) : g(n + 1), s(n + 1){
        for(int i = 1; i <= n; i++){
            g[i] = i;
            s[i] = 1;
        }
    }

    int find(int i){
        if (i == g[i]){
            return i;
        }
        return g[i] = find(g[i]);
    }

    int get_size(int i){
        return s[find(i)];
    }

    void merge(int i, int j){
        int gi = find(i);
        int gj = find(j);

        if(gi != gj){
            g[gi] = gj;
            s[gj] += s[gi];
        }
    }
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, int>> g;
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g.emplace_back(-c, a, b);
    }

    sort(g.begin(), g.end());

    vector<int> res(q);
    priority_queue<tuple<int, int, int>> query;

    for(int i = 0; i < q; i++){
        int k, v;
        cin >> k >> v;
        query.emplace(k, v, i);
    }
    ds d(n);

    int query_idx = 0;
    for(auto[w, a, b] : g){
        w = -w;
        while(!query.empty()){
            auto [target_w, target_v, q_idx] = query.top();
            if(target_w <= w){
                break;
            }
            res[q_idx] = d.get_size(target_v) - 1;
            query.pop();
        }
        d.merge(a, b);
    }

    while (!query.empty()){
        auto [target_w, target_v, q_idx] = query.top();
        query.pop();
        res[q_idx] = d.get_size(target_v) - 1;
    }
    for(auto i : res){
        cout << i << "\n";
    }
}
