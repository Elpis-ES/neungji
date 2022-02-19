#include <bits/stdc++.h>

using namespace std;

bool A[101][101];

int bfs(int cur, int N){
    int i, ret;
    if (A[cur][cur] == 1){
        //already visited
        return 0;
    }
    ret = 1;
    A[cur][cur] = true;
    for(i = 1; i <= N; i++){
        if(A[cur][i] == true){
            ret += bfs(i, N);
        }
    }
    return ret;
}

int main(){
    int n, i, k;
    int a, b;
    scanf(" %d", &n);
    scanf(" %d", &i);
    for(k = 0; k < i; k++){
        scanf(" %d %d", &a, &b);
        A[a][b] = true;
        A[b][a] = true;
    }
    printf("%d\n", bfs(1, n) - 1);
    return 0;
}
