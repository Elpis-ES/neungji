#include <bits/stdc++.h>

using namespace std;

int dp_arr[502][502];
int sum_arr[502];

int main(){
    int t, k, n, num, tmp, cur_min;
    scanf(" %d", &t);
    for(int i = 0; i < t; i++){
        scanf(" %d", &k);
        memset(dp_arr, 0, sizeof(int)*502*502);
        memset(sum_arr, 0, sizeof(int)*502);
        for(int j = 1; j <= k; j++){
            scanf(" %d", &num);
            sum_arr[j] = sum_arr[j-1] + num;
            dp_arr[j][j] = 0;
        }
        for(int p = k - 1; p >=1; p--){
            for(int r = p + 1; r <= k; r++){
                cur_min = INT_MAX;
                for(int q = p; q < r; q++){
                    tmp = dp_arr[p][q] + dp_arr[q+1][r] + sum_arr[r] - sum_arr[p-1];
                    if(tmp < cur_min){
                        cur_min = tmp;
                    }
                }
                dp_arr[p][r] = cur_min;
            }
        }
        printf("%d\n", dp_arr[1][k]);

    }
    return 0;
}
