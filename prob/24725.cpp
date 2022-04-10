#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> v;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int find(int x, int y, int pos, int dir){
    int ret = 0;
    switch(pos){
        case 3:
            if(v[y][x] == 'P' || v[y][x] == 'J'){
                return 1;
            }
            break;
        case 2:
            if(v[y][x] == 'F' || v[y][x] == 'T'){
                int nxt_x = x + dx[dir];
                int nxt_y = y + dy[dir];
                if(nxt_x >= 0 && nxt_x < m && nxt_y >= 0 && nxt_y < n)
                        ret += find(nxt_x, nxt_y, pos + 1, dir);
            }
            break;
        case 1:
            if(v[y][x] == 'N' || v[y][x] == 'S'){
                int nxt_x = x + dx[dir];
                int nxt_y = y + dy[dir];
                if(nxt_x >= 0 && nxt_x < m && nxt_y >= 0 && nxt_y < n)
                    ret += find(nxt_x, nxt_y, pos + 1, dir);
            }
            break;
        case 0:
            if(v[y][x] == 'E' || v[y][x] == 'I'){
                int nxt_x = x + dx[dir];
                int nxt_y = y + dy[dir];
                if(nxt_x >= 0 && nxt_x < m && nxt_y >= 0 && nxt_y < n)
                    ret += find(nxt_x, nxt_y, pos + 1, dir);
            }
            break;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        v.emplace_back(s);
    }
    int ret = 0;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            for(int d = 0 ; d < 8; d++)
                ret += find(x, y, 0, d);
        }
    }
    cout << ret<< "\n";

}
