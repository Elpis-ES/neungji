#include <bits/stdc++.h>

using namespace std;

char a[1001];
char b[1001];
int a_len;
int b_len;

int dp_arr[1001][1001];

int dp(int i, int j){
    if(i < 0 || j < 0){
        return 0;
    }
    if(dp_arr[i][j] != -1){
        return dp_arr[i][j];
    }
    int cur_dp;
    if(a[i] == b[j]){
        cur_dp = dp(i-1, j-1) + 1;
    }
    else{
        cur_dp = max(dp(i-1, j), dp(i, j-1));
    }
    dp_arr[i][j] = cur_dp;
    return cur_dp;
}


int main(){
    memset(dp_arr, -1, sizeof(int)*1001*1001);
    scanf("%s\n", a);
    a_len = strlen(a);
    scanf("%s", b);
    b_len = strlen(b);
    printf("%d\n", dp(a_len - 1, b_len - 1));

}
