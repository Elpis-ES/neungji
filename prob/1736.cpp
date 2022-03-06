#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int tmp;
    vector<tuple<int, int>> pq;
    vector<vector<bool>> checked(n, vector<bool>(m, false));

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> tmp;
            if(tmp == 1){
                pq.emplace_back(y, x);
            }
        }
    }

    sort(pq.begin(), pq.end());

    int robot_cnt = 0;

    for(int i = 0; i < pq.size(); i++){
        auto [y, x] = pq[i];
        if(checked[y][x])
            continue;
        checked[y][x] = true;
        robot_cnt++;
        int cur_x = x;
        int cur_y = y;
        for(int j = i + 1; j < pq.size(); j++){
            auto [target_y, target_x] = pq[j];
            if(checked[target_y][target_x])
                continue;
            if(target_x >= cur_x && target_y >= cur_y){
                checked[target_y][target_x] = true;
                cur_x = target_x;
                cur_y = target_y;
            }
        }
    }
    cout << robot_cnt << "\n";

}
