#include <bits/stdc++.h>

using namespace std;

int A[200003];
int dp_arr[200003];

void solve(){
    int i, n;
    memset(A, 0, sizeof(int) * 200003);
    memset(dp_arr, 0, sizeof(int) * 200003);
    scanf(" %d", &n);
    for(i = 1; i <= n; i++){
        scanf(" %d", &A[i*2]);
    }
    for(i = 1; i <= n; i++){
        scanf(" %d", &A[i*2+1]);
    }
    dp_arr[2] = A[2];
    dp_arr[3] = A[3];
    int prev_max;
    for(i = 2; i <= n; i++){
        prev_max = max(dp_arr[(i-2)*2], dp_arr[(i-2)*2+1]);
        dp_arr[i*2] = A[i*2]+max(prev_max, dp_arr[(i-1)*2 + 1]);
        dp_arr[i*2+1] = A[i*2+1]+max(prev_max, dp_arr[(i-1)*2]);
    }
    printf("%d\n", max(dp_arr[n*2], dp_arr[n*2+1]));

    return;
}


int main(){
    int T;
    int i;
    scanf(" %d", &T);
    for(i = 0; i < T; i++){
        solve();
    }
    return 0;
}
