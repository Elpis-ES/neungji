#include <bits/stdc++.h>

using namespace std;

struct ds{
    vector<int> g;

    ds(int n) : g(n){
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

    void merge(int i, int j){
        int gi = find(i);
        int gj = find(j);

        if(gi != gj){
            g[gi] = gj;
        }
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n;
        cin >> n;
        ds d(n);
        vector<tuple<int, int, int>> v;
        for(int i = 0; i < n; i++){
            int x, y, r;
            cin >> x >> y >> r;
            int j = 0;
            for(auto [xj, yj, rj] : v){
                int dist = (xj - x) * (xj - x) + (yj - y) * (yj - y);
                int radius = (r + rj) * (r + rj);
                if(dist <= radius){
                    d.merge(i, j);
                }
                j++;

            }
            v.emplace_back(x, y, r);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(d.find(i) == i){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

}
