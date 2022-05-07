#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    int max_h = INT_MIN;
    int min_h = INT_MAX;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
        max_h = max(y, max_h);
        min_h = min(y, min_h);
    }
    sort(v.begin(), v.end());

    int l = 0;
    int r = max_h - min_h;

    while(l <= r){
        int cur = (l + r) / 2;
        int cur_min = v[0].second;
        int cur_max = v[0].second;
        int cnt = 1;
        for(auto [x, y] : v){
            int tmp_min = min(cur_min, y);
            int tmp_max = max(cur_max, y);
            if(tmp_max - tmp_min > cur){
                cur_max = y;
                cur_min = y;
                cnt++;
            }
            else{
                cur_min = tmp_min;
                cur_max = tmp_max;
            }
        }
        if(cnt <= k){
            r = cur - 1;
        }
        else{
            l = cur + 1;
        }
    }

    cout << (l >> 1) << "." << (l % 2 ? "5" : "0") << "\n";


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
