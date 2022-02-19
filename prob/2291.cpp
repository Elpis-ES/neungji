#include <bits/stdc++.h>

using namespace std;


int dp_arr[11][221][221];
int ans[10];

int dp_cnt(int n, int m, int start){
    if(n == 1 && start <= m){
        return 1;
    }
    if(start * n > m){
        return 0;
    }
    if (dp_arr[n][m][start] != 0){
        return dp_arr[n][m][start];
    }
    int ret = 0;
    int max_start = m / n;
    for(int i = start; i <= max_start + 1; i++){
        if(m < i){
            break;
        }
        ret += dp_cnt(n-1, m - i, i);
    }
    dp_arr[n][m][start] = ret;
    return ret;
}

void dp(int digit, int n, int m, int k){
    if(n == 1){
        ans[digit] = m;
        return;
    }
    int cnt = 0;
    int max_start = m / n;
    int prev_cnt = 0;
    int start = digit == 0 ? 1 : ans[digit - 1];
    bool digit_found = false;
    for(int i = start; i <= max_start + 2; i++){
        cnt += dp_cnt(n-1, m - i, i);
        if(k > prev_cnt && k <= cnt){
            ans[digit] = i;
            dp(digit + 1, n - 1, m - i, k - prev_cnt);
            break;
        }
        prev_cnt = cnt;
    }
}

int main(){
    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);
    dp(0, n, m, k);
    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}
