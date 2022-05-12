#include <bits/stdc++.h>

using namespace std;

vector<int> v[2];
vector<vector<int>> dp_arr;
vector<vector<pair<int, int>>> nxt;

int dp(int i, int j){
    if(i >= v[0].size() || j >= v[1].size()){
        return 0;
    }
    if(dp_arr[i][j] != -1){
        return dp_arr[i][j];
    }

    int ret;
    if(v[0][i] == v[1][j]){
        ret = 1 + dp(i + 1, j + 1);
        nxt[i][j].first = i + 1;
        nxt[i][j].second = j + 1;

    }
    else{
        int l = dp(i + 1, j);
        int r = dp(i, j + 1);
        if(l > r){
            ret = l;
            nxt[i][j].first = i + 1;
            nxt[i][j].second = j;
        }
        else{
            ret = r;
            nxt[i][j].first = i;
            nxt[i][j].second = j + 1;
        }

    }
    dp_arr[i][j] = ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 2; i++){
        int n;
        cin >> n;
        v[i] = vector<int>(n);
        for(auto &val : v[i]){
            cin >> val;
        }
    }

    dp_arr = vector<vector<int>> (v[0].size(), vector<int> (v[1].size(), -1));
    nxt = vector<vector<pair<int, int>>> (v[0].size(), vector<pair<int, int>> (v[1].size(), make_pair(v[0].size(), v[1].size())));

    cout << dp(0, 0) << "\n";
    int x = 0;
    int y = 0;
    while(x < v[0].size() && y < v[1].size()){
        if(v[0][x] == v[1][y]){
            cout << v[0][x] << " ";
        }
        auto [nxt_x, nxt_y] = nxt[x][y];
        x = nxt_x;
        y = nxt_y;
    }
    cout << "\n";

}
