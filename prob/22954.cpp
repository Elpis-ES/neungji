#include <bits/stdc++.h>

using namespace std;

vector<bool> check;
vector<vector<pair<int, int>>> g;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    if(n == 1 || n == 2){
        cout << "-1\n";
        return 0;
    }

    g = vector<vector<pair<int, int>>> (n + 1);
    check = vector<bool>(n + 1, false);

    for(int i = 1; i <= m; i++){
        int p, q;
        cin >> p >> q;
        g[p].emplace_back(q, i);
        g[q].emplace_back(p, i);
    }

    vector<int> edge1;
    vector<int> vertex1;

    vertex1.emplace_back(1);
    queue<pair<int, int>> q;
    q.emplace(1, 0);
    check[1] = true;

    bool leaf_found = false;
    int target_leaf;
    int target_edge;

    while(!q.empty()){
        auto [cur_v, cur_e] = q.front();
        bool is_leaf = true;
        q.pop();
        for(auto [v, e] : g[cur_v]){
            if(check[v] == false){
                is_leaf = false;
                check[v] = true;
                q.emplace(v, e);
                vertex1.emplace_back(v);
                edge1.emplace_back(e);
            }
        }
        if(!leaf_found && is_leaf){
            leaf_found = true;
            target_leaf = cur_v;
            target_edge = cur_e;
        }
    }
    if(vertex1.size() == n){
        // There exists MST
        sort(vertex1.begin(), vertex1.end());
        sort(edge1.begin(), edge1.end());
        cout << "1 " << vertex1.size() - 1 << "\n";
        cout << target_leaf << "\n";
        cout << "\n";
        for(auto i : vertex1){
            if(i != target_leaf){
                cout << i << " ";
            }
        }
        cout << "\n";
        for(auto i : edge1){
            if(i != target_edge){
                cout << i << " ";
            }
        }
        cout << "\n";
        return 0;
    }
    else{
        vector<int> edge2;
        vector<int> vertex2;

        for(int i = 1; i <= n; i++){
            if(check[i] == false){
                check[i] = true;
                q.emplace(i, 0);
                vertex2.emplace_back(i);
                break;
            }
        }

        while(!q.empty()){
            auto[cur, _] = q.front();
            q.pop();
            for(auto [v, e]: g[cur]){
                if(check[v] == false){
                    check[v] = true;
                    q.emplace(v, e);
                    vertex2.emplace_back(v);
                    edge2.emplace_back(e);
                }
            }
        }

        if(vertex1.size() + vertex2.size() == n && (vertex1.size() != vertex2.size())){
            sort(vertex1.begin(), vertex1.end());
            sort(edge1.begin(), edge1.end());
            sort(vertex2.begin(), vertex2.end());
            sort(edge2.begin(), edge2.end());

            cout << vertex1.size() << " " << vertex2.size() << "\n";
            for(auto i: vertex1){
                cout << i << " ";
            }
            cout << "\n";
            for(auto i : edge1){
                cout << i << " ";
            }
            cout << "\n";
            for(auto i: vertex2){
                cout << i << " ";
            }
            cout << "\n";
            for(auto i : edge2){
                cout << i << " ";
            }
            cout << "\n";
            return 0;
        }
        else{
            cout << "-1\n";
            return 0;
        }
    }
}
