#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(k);
    for(auto &i : v){
        cin >> i;
    }
    int r = v[k - 1] - v[0];
    int l = INT_MAX;
    for(int i = 0; i < k - 1; i++){
        int cur = v[i + 1] - v[i];
        l = min(l, cur);
    }

    while(l <= r){
        int cur = (l + r) / 2;
        int cnt = 1;
        int p = v[0];

        for(int i = 1; i < k; i++){
            if(v[i] - p >= cur){
                cnt++;
                p = v[i];
            }
        }

        if(cnt < m){
            r = cur - 1;
        }
        else{
            l = cur + 1;
        }

    }
    vector<bool> place (k, false);
    place[0] = 1;
    int cur = v[0];
    int cnt = 1;
    for(int i = 1; i < k && cnt < m; i++){
        if(v[i] - cur >= r){
            place[i] = true;
            cur = v[i];
            cnt++;
        }
    }
    if(cnt != m){
        place[k - 1] = true;
    }

    for(auto i : place){
        cout << i;
    }

    cout << "\n";
}
