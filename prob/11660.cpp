#include <bits/stdc++.h>

using namespace std;

int arr[1026][1026];

int main(void){
    int N, M;
    int i, j, n;
    int x1, y1, x2, y2;
    scanf(" %d %d", &N, &M);
    for(j = 1; j <=N; j++){
        for(i = 1; i <=N; i++){
            scanf(" %d", &n);
            arr[j][i] = n + arr[j][i-1] + arr[j-1][i] - arr[j-1][i-1];
        }
    }

    for(i = 0; i < M; i++){
        scanf(" %d %d %d %d", &y1, &x1, &y2, &x2);
        printf("%d\n", arr[y2][x2] - arr[y2][x1 - 1] - arr[y1 -1][x2] + arr[y1-1][x1-1]);
    }
    return 0;

}
