#include <bits/stdc++.h>

using namespace std;

string s;
int n;
vector<vector<int>> palindrome_idx;
vector<int> dp_arr;

int dp(int i){
    if(i >= n){
        return 0;
    }
    if(dp_arr[i] != -1){
        return dp_arr[i];
    }
    int ret = INT_MAX;
    for(auto nxt: palindrome_idx[i]){
        ret = min(ret, dp(nxt + 1) + 1);
    }
    dp_arr[i] = ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.length();
    palindrome_idx = vector<vector<int>> (n);
    dp_arr = vector<int> (n, -1);
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
        q.emplace(i, i);
        palindrome_idx[i].emplace_back(i);
        if(i != n - 1 && s[i] == s[i + 1]){
            q.emplace(i, i + 1);
            palindrome_idx[i].emplace_back(i + 1);
        }
    }

    while(!q.empty()){
        auto [f, t] = q.front();
        q.pop();
        if(f == 0 || t == n - 1){
            continue;
        }
        if(s[f - 1] == s[t + 1]){
            q.emplace(f - 1, t + 1);
            palindrome_idx[f - 1].emplace_back(t + 1);
        }
    }
    cout << dp(0) << "\n";

}
