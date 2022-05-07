#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, len;
    cin >> n >> m >> len;
    vector<int> v;
    v.emplace_back(0);
    v.emplace_back(len);

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
    sort(v.begin(), v.end());

    int l = 1;
    int r = len - 1;

    while(l <= r){
        int cur = (r + l) / 2;
        int cnt = 0;

        for(int i = 0; i <= n; i++){
            int space = v[i + 1] - v[i];
            cnt += space / cur;
            if(space % cur == 0){
                cnt--;
            }
        }

        if(cnt > m){
            l = cur + 1;
        }
        else{
            r = cur - 1;
        }
    }

    cout << l << "\n";
}
