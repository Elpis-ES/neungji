#include <bits/stdc++.h>

using namespace std;

struct ds{
    vector<int> g;
    vector<int> s;

    ds(int n) : g(n), s(n){
        for(int i = 0; i < n; i++){
            g[i] = i;
        }
    }

    int find(int i){
        if (i == g[i]){
            return i;
        }
        return g[i] = find(g[i]);
    }

    void set_size(int i, int sz){
        s[i] = sz;
    }

    int get_size(int i){
        return s[find(i)];
    }

    void merge_ally(int i, int j){
        int gi = find(i);
        int gj = find(j);

        if(gi != gj){
            if(s[gi] > s[gj]){
                g[gj] = gi;
                s[gi] += s[gj];
            }
            else{
                g[gi] = gj;
                s[gj] += s[gi];
            }
        }
    }

    void merge_enemy(int i, int j){
        int gi = find(i);
        int gj = find(j);

        if(gi != gj){
            if(s[gi] > s[gj]){
                g[gj] = gi;
                s[gi] -= s[gj];
            }
            else{
                g[gi] = gj;
                s[gj] -= s[gi];
            }
        }
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    ds d(n);
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        d.set_size(i, s);
    }
    for(int i = 0; i < m; i++){
        int opt, p, q;
        cin >> opt >> p >> q;
        p--;
        q--;
        if(opt == 1){
            d.merge_ally(p, q);
        }
        else{
            d.merge_enemy(p, q);
        }
    }

    vector<int> res;
    for(int i = 0; i < n; i++){
        if(d.find(i) == i){
            int sz = d.get_size(i);
            if(sz != 0){
                res.emplace_back(sz);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for(auto i : res){
        cout << i << " ";
    }
    cout << "\n";

}
