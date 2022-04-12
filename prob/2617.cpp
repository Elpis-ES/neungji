#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> from_arr;
vector<vector<int>> to_arr;

int dfs(int t, vector<vector<int>> g){
    vector<bool> visited(n + 1, false);
    queue<int> q;
    int cnt = 0;
    visited[t] = true;
    for(auto v : g[t]){
        if(!visited[v]){
            q.emplace(v);
            visited[v] = true;
        }
    }
    while(!q.empty()){
        int i = q.front();
        q.pop();
        cnt++;
        for(auto v: g[i]){
            if(!visited[v]){
                visited[v] = true;
                q.emplace(v);
            }
        }
    }
    return cnt;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    from_arr = vector<vector<int>> (n + 1);
    to_arr = vector<vector<int>> (n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        from_arr[a].emplace_back(b);
        to_arr[b].emplace_back(a);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(dfs(i, from_arr) >= (n + 1) / 2 || dfs(i, to_arr) >= (n + 1) / 2){
            cnt++;
        }
    }
    cout << cnt << "\n";
}
