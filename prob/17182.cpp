#include <bits/stdc++.h>

using namespace std;

int w[10][10];
int v[1 << 10][10];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(v, 0x3f, sizeof(v));

    int n, s;
    cin >> n >> s;
    int tmp;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> tmp;
            w[y][x] = tmp;
        }
    }

    v[1 << s][s] = 0;

    for(int i = 1 << s; i < (1 << n); i++){
        if(i & (1 << s)){
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    for(int k = 0; k < n; k++){
                        if(i & (1 << k)){
                            v[i][j] = min(v[i][j], v[i ^ (1 << j)][k] + w[k][j]);
                        }
                    }
                    for(int k = 0; k < n; k++){
                        if(i & (1 << k)){
                            v[i][k] = min(v[i][k], v[i][j] + w[j][k]);
                        }
                    }
                }
            }
        }
    }
    int ret = INT_MAX;
    for(int i = 0; i < n; i++){
        ret = min(ret, v[(1 << n) - 1][i]);
    }
    cout << ret << "\n";
}
