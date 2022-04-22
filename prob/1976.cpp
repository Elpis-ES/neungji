#include <bits/stdc++.h>

using namespace std;

struct ds{
    vector<int> g;

    ds(int n): g(n){
        for(int i = 0; i < n; i++){
            g[i] = i;
        }
    }

    int find(int i){
        if(g[i] == i){
            return i;
        }
        return g[i] = find(g[i]);
    }

    bool merge(int i, int j){
        int gi = find(i);
        int gj = find(j);

        if(gi != gj){
            g[gj] = gi;
            return true;
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    ds d(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 1){
                d.merge(i, j);
            }
        }
    }
    int target = -1;
    bool connected = true;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        tmp--;
        if (target == -1){
            target = d.find(tmp);
        }
        else{
            if(target != d.find(tmp)){
                connected = false;
                break;
            }
        }
    }
    cout << (connected ? "YES\n" : "NO\n");
}
