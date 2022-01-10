#include <bits/stdc++.h>

using namespace std;
int tree[10002][10002];

int main(void){
    int f, t, w;
    int n, i;
    scanf(" %d", &n);
    for(i = 0; i < n; i++){
        scanf (" %d %d %d", &f, &t, &w);
        tree[f][t] = w;
        tree[t][f] = w;
    }

}
