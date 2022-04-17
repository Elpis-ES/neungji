#include <bits/stdc++.h>

using namespace std;

int n;

vector<bool> removed;
vector<vector<int>> g;

bool bfs(int num){
    int target = 1;
    vector<bool> checked (n + 1, false);
    for( ; target <= n; target++){
        if(!removed[target]){
            break;
        }
    }
    queue<int> q;
    q.emplace(target);
    int cnt = 1;
    checked[target] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(auto i : g[t]){
            if (!removed[i] && !checked[i]){
                checked[i] = true;
                q.emplace(i);
                cnt++;
            }
        }
    }
    return cnt == num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;

    cin >> n >> m;

    removed = vector<bool> (n + 1, false);
    g = vector<vector<int>> (n + 1);

    for(int i = 0; i < m; i++){
        int p, q;
        cin >> p >> q;
        g[p].emplace_back(q);
        g[q].emplace_back(p);
    }
    int cnt = n;
    for(int i = 0; i < n; i++){
        cout << (bfs(cnt) ? "YES\n" : "NO\n");
        int t;
        cin >> t;
        removed[t] = true;
        cnt--;
    }

}
