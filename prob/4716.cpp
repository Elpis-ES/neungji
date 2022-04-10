#include <bits/stdc++.h>

using namespace std;

void solve(int n, int a, int b){
    vector<tuple<int, int, int, int>> v;
    for(int i = 0; i < n; i++){
        int m, p, q;
        cin >> m >> p >> q;
        v.emplace_back(-abs(p - q), m, p, q);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for(auto [d, m, p, q]: v){
        int balloon_cnt;
        if(p < q){
            balloon_cnt = min(m, a);
            sum += p * balloon_cnt;
            a -= balloon_cnt;
            m -= balloon_cnt;
            if(m != 0){
                sum += q * m;
                b -= m;
            }
        }
        else{
            balloon_cnt = min(m, b);
            sum += q * balloon_cnt;
            b -= balloon_cnt;
            m -= balloon_cnt;
            if(m != 0){
                sum += p * m;
                a -= m;
            }
        }
    }
    cout << sum << "\n";

}

int main(){
    int n, a, b;
    while(true){
        cin >> n >> a >> b;
        if (n == 0 && a == 0 && b == 0){
            break;
        }
        solve(n, a, b);
    }
}
