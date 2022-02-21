#include <bits/stdc++.h>

using namespace std;

int dp_arr[501][501];
int sum_arr[501][501];
int size_arr[501];

int dp(int start, int end, int sum){
    printf("DP[%d %d] called with sum %d\n", start, end, sum);
    if(start == end){
        return sum;
    }
    if(dp_arr[start][end] != 0){
        return dp_arr[start][end];
    }
    int cur_min = INT_MAX;
    int cur_sum = 0;
    int a, b;
    int tmp;

    for(int i = start; i <= end; i++){
        cur_sum += size_arr[i];
        if(i == start){
            tmp = sum + dp(i+1, end, sum - cur_sum);
        }
        else if(i == end){
            tmp = dp(start, i-1, sum - cur_sum) + sum;
        }
        else{
            a = dp(start, i, cur_sum);
            b = dp(i+1, end, sum - cur_sum);
            tmp = a+b+sum;
        }
        if(tmp < cur_min){
            cur_min = tmp;
        }
    }
    dp_arr[start][end] = cur_min;
    return cur_min;
}

int main(){
    int t, k;
    int sum;
    scanf(" %d", &t);
    for(int i = 0; i < t; i++){
        memset(dp_arr, 0, sizeof(int)*501*501);
        memset(sum_arr, 0, sizeof(int)*501*501);
        sum = 0;
        scanf(" %d", &k);
        for(int j = 0; j < k; j++){
            scanf(" %d", &size_arr[j]);
            sum += size_arr[j];
        }
        printf("%d\n", dp(0, k-1, sum));
    }
    return 0;
}
