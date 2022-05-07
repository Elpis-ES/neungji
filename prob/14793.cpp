#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++){
        priority_queue<int> pq;
        int k, n;
        cin >> n >> k;
        pq.emplace(n);
        int ls, rs;
        for(int i = 0; i < k; i++){
            int cur = pq.top();
            pq.pop();
            cur--;
            ls = cur >> 1;
            rs = cur >> 1;
            if(cur % 2 == 1){
                rs++;
            }
            if(ls != 0){
                pq.emplace(ls);
            }
            if(rs != 0){
                pq.emplace(rs);
            }

        }
        cout << "Case #" << tt << ": " << max(ls, rs) << " " << min(ls, rs) << "\n";
    }
}
