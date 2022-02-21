#include <bits/stdc++.h>

using namespace std;

int grid[30][30];
int grid_after[30][30];
bool visited[30][30];
int m, n;
vector<vector<pair<int, int> > > graph;

void dfs(int x, int y){
    vector<pair<int, int> > v;
    int value = grid[x][y];
    v.push_back(make_pair(x, y));
    int p, q;
    for(int i = 0; i < v.size(); i++){
        p = v[i].first;
        q = v[i].second;
        visited[p][q] = true;
        if(p + 1 < m && grid[p+1][q] == value && !visited[p+1][q]){
            v.push_back(make_pair(p+1, q));
        }
        if(p - 1 >= 0 && grid[p-1][q] == value && !visited[p-1][q]){
            v.push_back(make_pair(p-1, q));
        }
        if(q + 1 < n && grid[p][q+1] == value && !visited[p][q+1]){
            v.push_back(make_pair(p, q+1));
        }
        if(q - 1 >= 0 && grid[p][q-1] == value && !visited[p][q-1]){
            v.push_back(make_pair(p, q-1));
        }
    }
    graph.push_back(v);
}

int main(){
    scanf(" %d %d", &n, &m);
    for(int y = 0; y <n; y++){
        for(int x = 0; x < m; x++){
            scanf(" %d", &grid[x][y]);
        }
    }
    for(int y = 0; y <n; y++){
        for(int x = 0; x < m; x++){
            scanf(" %d", &grid_after[x][y]);
        }
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(!visited[x][y]){
                dfs(x, y);
            }
        }
    }

    int x, y, cur_val;
    int parts_changed = 0;
    bool is_cpcu = true;
    bool all_same;
    for(auto it = graph.begin(); it != graph.end(); it++){
        x = (*it)[0].first;
        y = (*it)[0].second;
        cur_val = grid_after[x][y];
        all_same = true;
        for(auto iit = it->begin(); iit != it->end(); iit++){
            x = iit->first;
            y = iit->second;
            if(grid_after[x][y] != cur_val){
                all_same = false;
                break;
            }
        }
        if(all_same && cur_val != grid[x][y]){
            parts_changed++;
        }
        if(!all_same || parts_changed >= 2){
            is_cpcu = false;
            break;
        }
    }

    printf("%s\n", is_cpcu ? "YES" : "NO");


}
