#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<pair<int, int>> pq;
    vector<int> v;

    int n;
    cin >> n;

    v.emplace_back(0);

    int tmp;
    int psum = 0;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        psum += tmp;
        v.emplace_back(psum);
        pq.emplace(tmp, i);
    }

    int cur_val = 0;
    int cur_pos = 1;

    while(!pq.empty() && cur_pos < n){
        auto [val, pos] = pq.top();
        pq.pop();

        if(pos >= cur_pos){
            int sell_val = v[pos] - v[pos - 1];
            int sell_cnt = pos - cur_pos;
            int buy_val = v[pos - 1] - v[cur_pos - 1];
            cur_val += (sell_val * sell_cnt) - buy_val;
            cur_pos = pos + 1;
        }
    }
    cout << cur_val << "\n";
}
