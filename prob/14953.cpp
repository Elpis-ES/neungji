#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;

vector<int> dp_arr;

int dp(int i){
    if(dp_arr[i] != -1){
        return dp_arr[i];
    }
    int cur_max = 1;
    for(auto a: v[i]){
        if(v[a].size() > v[i].size()){
            cur_max = max(cur_max, dp(a) + 1);
        }
    }
    dp_arr[i] = cur_max;
    return cur_max;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    v = vector<vector<int>> (n);
    dp_arr = vector<int> (n, -1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    int max_val = INT_MIN;
    for(int i = 0; i < n; i++){
        max_val = max(max_val, dp(i));
    }
    cout << max_val << "\n";
}
