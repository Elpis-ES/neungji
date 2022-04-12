#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

vector<vector<int>> dp_arr;

int dp(int from, int to){
    if(from == to){
        return 0;
    }
    if(dp_arr[from][to] != -1){
        return dp_arr[from][to];
    }
    int ret = INT_MAX;
    for(int i = from; i < to; i++){

        int cur = dp(from, i) + dp(i + 1, to) + v[from].first * v[i].second * v[to].second;
        ret = min(cur, ret);
    }
    dp_arr[from][to] = ret;
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    v = vector<pair<int, int>> (n);
    dp_arr = vector<vector<int>> (n, vector<int> (n, -1));
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    cout << dp(0, n-1) << "\n";
}
