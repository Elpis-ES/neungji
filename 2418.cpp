#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<vector<vector<ll>>>dp_arr;
vector<vector<char>>m;
string s;
int h, w, l;

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll dp(int x, int y, int pos){
    if(dp_arr[pos][y][x] != -1){
        return dp_arr[pos][y][x];
    }

    int nxt_x, nxt_y;

    ll ret = 0;
    if(m[y][x] == s[pos]){
        if(pos == l - 1){
            ret = 1;
        }
        else{
            for(int i = 0; i < 8; i++){
                nxt_x = x + dx[i];
                nxt_y = y + dy[i];
                if(0 <= nxt_x && nxt_x < w && 0 <= nxt_y && nxt_y < h){
                    ret += dp(nxt_x, nxt_y, pos + 1);
                }
            }
        }
    }
    dp_arr[pos][y][x] = ret;
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> l;

    m = vector<vector<char>> (h, vector<char> (w));
    dp_arr = vector<vector<vector<ll>>> (l, vector<vector<ll>> (h, vector<ll> (w, -1)));

    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            cin >> m[y][x];
        }
    }

    cin >> s;

    ll ret = 0;
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            ret += dp(x, y, 0);
        }
    }
    cout << ret << "\n";
}
