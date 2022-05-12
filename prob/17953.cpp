#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> dp_arr;
vector<vector<int>> v;
int n, m;

int dp(int i, int dessert, int same){
    if(i == n){
        return 0;
    }
    if(dp_arr[dessert][i][same] != -1){
        return dp_arr[dessert][i][same];
    }

    int ret = INT_MIN;
    int add = v[dessert][i];
    if(same){
        add /= 2;
    }
    for(int j = 0; j < m; j++){
        int cur_same = 0;
        if(j == dessert){
            cur_same = 1;
        }
        int cur = add + dp(i + 1, j, cur_same);
        ret = max(ret, cur);
    }
    dp_arr[dessert][i][same] = ret;
    return ret;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    dp_arr = vector<vector<vector<int>>> (m, vector<vector<int>> (n, vector<int>(2, -1)));
    v = vector<vector<int>> (m, vector<int>());

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            v[i].emplace_back(tmp);
        }
    }

    int res = 0;
    for(int i = 0; i < m; i++){
        res = max(res, dp(0, i, 0));
    }
    cout << res << "\n";

}
