#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(n, vector<int> (m, 0));

    queue<pair<int, int>> q;
    vector<vector<bool>> placed(n, vector<bool> (m, false));

    int total = m * n;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            cin >> v[j][i];
            if(v[j][i] == 1){
                total--;
                placed[j][i] = true;
                q.emplace(i, j);
            }
            else if(v[j][i] == -1){
                total--;
            }
        }
    }
    q.emplace(-1, -1);
    int day = 1;
    if(total == 0){
        day = 0;
    }
    while(!q.empty()){
        if (total == 0){
            break;
        }
        auto [x, y] = q.front();
        q.pop();
        if(x == -1 && y == -1 && !q.empty()){
            day++;
            q.emplace(-1, -1);
        }
        else{
            for(int i = 0; i < 4; i++){
                int nxt_x = x + dx[i];
                int nxt_y = y + dy[i];
                if(nxt_x >= 0 && nxt_x < m && nxt_y >= 0 && nxt_y < n){
                    if(!placed[nxt_y][nxt_x] && v[nxt_y][nxt_x] == 0){
                        total--;
                        q.emplace(nxt_x, nxt_y);
                        placed[nxt_y][nxt_x] = true;
                    }
                }
            }
        }
    }

    if(total != 0){
        cout << "-1\n";
    }
    else{
        cout << day << "\n";
    }
}
