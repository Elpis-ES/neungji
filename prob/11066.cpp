#include <bits/stdc++.h>

using namespace std;

int dp_arr[502][502];
int k_arr[502][502];
int sum_arr[502];

int main(){
    int t, k, n, num, tmp, i, j, cur_min, opt_val;
    scanf(" %d", &t);
    for(int p = 0; p < t; p++){
        scanf(" %d", &k);
        memset(dp_arr, 0, sizeof(int)*502*502);
        memset(k_arr, 0, sizeof(int)*502*502);
        memset(sum_arr, 0, sizeof(int)*502);
        for(int q = 1; q <= k; q++){
            scanf(" %d", &num);
            sum_arr[q] = sum_arr[q-1] + num;
            k_arr[q][q] = q;
        }
        for(int m = 1; m <= k-1; m++){
            for(i = 1; i <= k - m; i++){
                j = i + m;
                cur_min = INT_MAX;
                for(int opt = k_arr[i][j-1]; opt <= k_arr[i+1][j]; opt++){
                    tmp = dp_arr[i][opt] + dp_arr[opt+1][j] + sum_arr[j] - sum_arr[i - 1];
                    if(tmp < cur_min){
                        cur_min = tmp;
                        opt_val = opt;
                    }
                }
                dp_arr[i][j] = cur_min;
                k_arr[i][j] = opt_val;
            }
        }

        printf("%d\n", dp_arr[1][k]);

    }
    return 0;
}
