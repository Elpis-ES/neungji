#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> p;
    vector<int> q;
    int n, m;

    cin >> n;
    p = vector<int>(n);
    for(auto &i: p){
        cin >> i;
    }

    cin >> m;
    q = vector<int> (m);
    for(auto &i : q){
        cin >> i;
    }

    vector<int> dp(m, 0);
    vector<vector<int>> prev(m, vector<int> (m + 1, -1));

    for(int i = 0; i < n; i++){
        int len = 0;
        int prev_pos = -1;
        for(int j = 0; j < m; j++){
            if(p[i] == q[j]){
                if(len + 1 > dp[j]){
                    dp[j] = len + 1;
                    prev[j][len + 1] = prev_pos;
                }
            }
            else if(p[i] > q[j]){
                if(dp[j] > len){
                    len = dp[j];
                    prev_pos = j;
                }
            }
        }
    }


    int max_len = 0;
    int pos = -1;
    for(int i = 0; i < m; i++){
        if(dp[i] > max_len){
            max_len = dp[i];
            pos = i;
        }
    }

    cout << max_len << "\n";
    int mlen = max_len;
    vector<int> seq;

    while(pos != -1){
        seq.emplace_back(q[pos]);
        pos = prev[pos][max_len];
        max_len--;
    }

    for(auto it = seq.rbegin(); it != seq.rend(); it++){
        cout << *it << " ";
    }
    cout << "\n";

}
