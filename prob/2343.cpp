#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    int min_val = INT_MIN;
    for(auto &i : v){
        cin >> i;
        min_val = max(i, min_val);
    }

    int l = min_val;
    int r = 1000000000;

    while(l <= r){
        int len = (l + r) / 2;
        int cnt = 0;

        int cur = 0;
        for(auto i : v){
            if(cur + i > len){
                cnt++;
                cur = i;
            }
            else{
                cur += i;
            }
        }
        if(cur != 0){
            cnt++;
        }

        if(cnt > m){
            l = len + 1;
        }
        else{
            r = len - 1;
        }

    }
    cout << l << "\n";

}
