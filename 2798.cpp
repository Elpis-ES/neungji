#include <bits/stdc++.h>

using namespace std;
int a[101];
int solve(int i, int N, int M, int k){
    int ret = 0;
    if (k == 0){
        return 0;
    }
    if(N - i == k){
        for(int j = i; j < N; j++){
            ret += a[j];
        }
        return ret;
    }
    int p = a[i] + solve(i+1, N, M - a[i], k-1);
    int q = solve(i+1, N, M, k);
    if(M - p < M - q){
        if(M - p < 0){
            ret = q;
        }
        else{
            ret = p;
        }
    }
    else{
        if(M-q < 0){
            ret = p;
        }
        else{
            ret = q;
        }
    }
    return ret;
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    int i;
    for(i = 0; i < N; i++){
      scanf(" %d", &a[i]);
    }
    int ret = solve(0, N, M, 3);
    printf("%d\n", ret);
}
