#include <bits/stdc++.h>

using namespace std;

int map[501][501];

int main(){
    int tc, n, m, w;
    int f, t, l;
    scanf(" %d", &tc);
    for(int i = 0; i < tc; i++){
        memset(map, 0, sizeof(int)*501*501);
        scanf(" %d %d %d", &n, m, w);
        for(int j = 0; j < m; j++){
            scanf(" %d %d %d", &f, &t, &l);
            map[f][t] = l;
            map[t][f] = l;
        }
        for(int j = 0; j < w; j++){
            scanf(" %d %d %d", &f, &t, &l);
            map[f][t] = -l;
        }
    }
}
