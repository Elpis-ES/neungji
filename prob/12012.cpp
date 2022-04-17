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

    int n, m;

    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<bool> c (n + 1, false);

    for(int i = 0; i < m; i++){
        int p, q;
        cin >> p >> q;
        g[p].emplace_back(q);
        g[q].emplace_back(p);
    }

    vector<int> v;

    ds d(n);

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }

    int target = 0;
    vector<bool> added(n + 1, false);
    vector<string> s;

    int cnt = 0;
    for(auto it = v.rbegin(); it != v.rend(); it++){
        int cur = *it;
        cnt++;
        added[cur] = true;
        for(auto i : g[cur]){
            if(added[i]){
                d.merge(cur, i);
            }
        }

        s.emplace_back(d.get_size(cur) == cnt ? "YES\n" : "NO\n");

    }

    for(auto it = s.rbegin(); it != s.rend(); it++){
        string ss = *it;
        cout << ss ;
    }

}
