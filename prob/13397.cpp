#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    int l = 0;
    int max_val = INT_MIN;
    int min_val = INT_MAX;

    for(auto &i : v){
        cin >> i;
        max_val = max(max_val, i);
        min_val = min(min_val, i);
    }
    int r = max_val - min_val;

    while(l <= r){
        int cur = (l + r) / 2;

        int cnt = 0;
        int cur_min = INT_MAX;
        int cur_max = INT_MIN;
        for(auto i : v){
            int tmp_min = min(cur_min, i);
            int tmp_max = max(cur_max, i);
            if(tmp_max - tmp_min > cur){
                cnt++;
                cur_min = i;
                cur_max = i;
            }
            else{
                cur_min = tmp_min;
                cur_max = tmp_max;
            }
        }
        cnt++;
        if(cnt > m){
            l = cur + 1;
        }
        else{
            r = cur - 1;
        }
    }
    cout << l << "\n";
}
