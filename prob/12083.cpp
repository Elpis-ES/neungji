#include <bits/stdc++.h>

using namespace std;

bool bfs(int i, vector<vector<int>> &v, vector<int> &status){
    queue<int> q;
    q.emplace(i);

    status[i] = 0;
    int ret = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int cur_stat = status[cur];
        for(int nxt : v[cur]){
            if(status[nxt] == -1){
                status[nxt] = (cur_stat + 1) % 2;
                q.emplace(nxt);
            }
            else if(status[nxt] == status[cur]){
                ret = false;
                break;
            }
        }
    }
    return ret;
}

void solve(int c){
    int n;
    cin >> n;
    unordered_map<string, int> m;
    vector<vector<int>> v;
    int idx = 0;
    for(int i = 0; i < n; i++){
        string p;
        cin >> p;
        int p_idx;
        if(m.find(p) == m.end()){
            m[p] = idx;
            p_idx = idx;
            idx++;
            v.emplace_back(vector<int>());
        }
        else{
            p_idx = m[p];
        }

        string q;
        cin >> q;
        int q_idx;
        if(m.find(q) == m.end()){
            m[q] = idx;
            q_idx = idx;
            idx++;
            v.emplace_back(vector<int>());
        }
        else{
            q_idx = m[q];
        }
        v[p_idx].emplace_back(q_idx);
        v[q_idx].emplace_back(p_idx);
    }

    vector<int> status(v.size(), -1);
    bool res = true;
    for(int i = 0; i < v.size(); i++){
        if(status[i] == -1){
            if(bfs(i, v, status) == false){
                res = false;
                break;
            }
        }
    }
    cout << "Case #" << c << ": " << (res ? "Yes\n" : "No\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
}
