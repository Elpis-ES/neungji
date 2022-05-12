#include <bits/stdc++.h>

using namespace std;

struct disjoint_set{
    vector<int> g;
    vector<int> s;
    disjoint_set(int n): g(n + 1), s(n + 1){
        for(int i = 1; i <= n; i++){
            g[i] = i;
            s[i] = 1;
        }
    }

    int find(int i){
        if(g[i] == i){
            return i;
        }
        return g[i] = find(g[i]);
    }

    void merge(int i, int j){
        int gi = find(i);
        int gj = find(j);
        if(gi != gj){
            g[gi] = gj;
            s[gj] += s[gi];
        }
    }

    int groupsize(int i){
        return s[find(i)];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    disjoint_set ds(n);
    priority_queue<tuple<int, int, int>> pq;

    for(int i = 0; i < m; i++){
        int l, p, q;
        cin >> p >> q >> l;
        if(p == q){
            continue;
        }
        pq.emplace(-l, p, q);
    }
    int len = 0;
    while(!pq.empty()){
        auto[l, p, q] = pq.top();
        l = -l;
        pq.pop();
        if(ds.find(p) == ds.find(q)){
            continue;
        }
        ds.merge(p, q);
        len += l;
        if(ds.groupsize(p) == n){
            break;
        }
    }
    cout << len << "\n";
}
