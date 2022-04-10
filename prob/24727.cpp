#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<pair<int, int>> arr[2];
vector<int> cnt (2, 0);
int n;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int main(){
    cin >> n >> cnt[0] >> cnt[1];

    v = vector<vector<int>> (n, vector<int> (n, 0));
    cnt[0]--;
    cnt[1]--;
    v[0][0] = 1;
    v[n-1][n-1] = 2;

    for(int diag = 1; diag <= 2 * (n - 1); diag++){
        for(int x = min(n-1, diag), y = diag - x; x >= 0; x--, y = diag - x){
            if(y >= n)
                continue;
            if(cnt[0] > 0){
                v[y][x] = 1;
                cnt[0]--;
            }
        }
    }

    for(int diag = 2 * (n - 1); diag >= 0; diag--){
        for(int y = min(n - 1, diag), x = diag - y; y >= 0; y--, x = diag - y){
            if(x >= n)
                continue;
            if(cnt[1] > 0 && v[y][x] == 0){
                bool enemy_near = false;
                bool me_near = false;
                for(int i = 0; i < 4; i++){
                    int adj_x = x + dx[i];
                    int adj_y = y + dy[i];
                    if(adj_x >= 0 && adj_y >= 0 && adj_x < n && adj_y < n){
                        if(v[adj_y][adj_x] == 1){
                            enemy_near = true;
                        }
                        if(v[adj_y][adj_x] == 2){
                            me_near = true;
                        }
                    }

                }
                if(me_near && !enemy_near){
                    v[y][x] = 2;
                    cnt[1]--;
                }
            }
        }
    }

    if(cnt[0] == 0 && cnt[1] == 0){
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                cout << v[j][i];
            }
            cout << "\n";
        }
    }
    else{
        cout << "-1\n";
    }

}
