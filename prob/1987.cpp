#include <bits/stdc++.h>

using namespace std;

int y, x;
vector<string> m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dp(int p, int q, int mask){
    if(mask & (1 << (m[q][p] - 'A'))){
        return 0;
    }
    mask = mask | (1 << (m[q][p] - 'A'));
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int cur_x = p + dx[i];
        int cur_y = q + dy[i];
        if(cur_x >= 0 && cur_x < x && cur_y >=0 && cur_y < y){
            ret = max(ret, dp(cur_x, cur_y, mask));
        }
    }
    return ret + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> y >> x;
    for(int i = 0; i < y; i++){
        string s;
        cin >> s;
        m.emplace_back(s);
    }
    cout << dp(0, 0, 0) << "\n";
}

