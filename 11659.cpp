#include <bits/stdc++.h>

using namespace std;

int sum_arr[100002];

int main(void){
    sum_arr[0] = 0;
    int N, M, t, i, j;
    scanf(" %d %d", &N, &M);
    for(i = 0; i < N; i++){
        scanf(" %d", &j);
        sum_arr[i + 1] = sum_arr[i] + j;
    }
    for(t = 0; t < M; t++){
        scanf(" %d %d", &i, &j);
        printf("%d ", sum_arr[j] - sum_arr[i - 1]);
    }
    printf("\n");
    return 0;
}
