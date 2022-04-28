#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v;
        int end = 0;
        int cur = 0;
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            v.emplace_back(tmp);
            if(end != m){
                end++;
                cur += tmp;
            }
        }
        int cnt = 0;
        if(n == m){
            if(cur < k){
                cnt++;
            }
        }
        else{
            for(int start = 0; start < n; start++){
                if(cur < k){
                    cnt++;
                }
                cur += v[end % n];
                cur -= v[start % n];
                end++;
            }
        }
        cout << cnt << "\n";
    }
}
