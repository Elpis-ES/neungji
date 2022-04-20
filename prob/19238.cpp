#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> target;
vector<vector<int>> g;
int n, m, f;
int cur_x, cur_y;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

bool route(int t){
    auto [target_y, target_x] = target[t];
    priority_queue<tuple<int, int, int>> pq;
    vector<vector<int>> d (n, vector<int> (n, INT_MAX));
    pq.emplace(0, cur_y, cur_x);

    bool ret = false;

    while(!pq.empty()){
        auto [dist, y, x] = pq.top();
        pq.pop();
        dist = -dist;
        if(dist >= d[y][x]){
            continue;
        }
        d[y][x] = dist;
        if(y == target_y && x == target_x){
            ret = true;
            cur_x = x;
            cur_y = y;
            f += dist;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            int nxt_dist = dist + 1;
            if(nxt_y >= 0 && nxt_y < n && nxt_x >= 0 && nxt_x < n){
                if(g[nxt_y][nxt_x] != 1 && nxt_dist <= f){
                    pq.emplace(-nxt_dist, nxt_y, nxt_x);
                }
            }
        }
    }
    return ret;
}
int find_customer(){
    priority_queue<tuple<int, int, int>> pq;
    vector<vector<int>> d (n, vector<int> (n, INT_MAX));
    pq.emplace(0, -cur_y, -cur_x);
    int ret = -1;
    while(!pq.empty()){
        auto[dist, y, x] = pq.top();
        pq.pop();
        dist = -dist;
        y = -y;
        x = -x;
        if(dist >= d[y][x]){
            continue;
        }

        d[y][x] = dist;

        if(g[y][x] >= 2){
            ret = g[y][x] - 2;
            f -= dist;
            cur_y = y;
            cur_x = x;
            g[y][x] = 0;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            int nxt_dist = dist + 1;
            if(nxt_y >= 0 && nxt_y < n && nxt_x >= 0 && nxt_x < n){
                if(g[nxt_y][nxt_x] != 1 && nxt_dist <= f){
                    pq.emplace(-nxt_dist, -nxt_y, -nxt_x);
                }
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m >> f;
    g = vector<vector<int>> (n, vector<int>(n));
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            int tmp;
            cin >> tmp;
            g[row][col] = tmp;
        }
    }

    cin >> cur_y >> cur_x;
    cur_x--;
    cur_y--;

    for(int i = 0; i < m; i++){
        int fx, fy, tx, ty;
        cin >> fy >> fx >> ty >> tx;
        fx--;
        fy--;
        tx--;
        ty--;
        g[fy][fx] = 2 + i;
        target.emplace_back(ty, tx);
    }
    for(int i = 0; i < m; i++){
        int target = find_customer();
        if(target == -1){
            f = -1;
            break;
        }
        if(route(target) == false){
            f = -1;
            break;
        }
    }
    cout << f << "\n";

}
