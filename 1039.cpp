#include <bits/stdc++.h>

using namespace std;

int dp_arr[1000001][11];

int make_int(int n, int p, int q, int len){
    int ret = 0;
    int mult = 1;
    int cur = n;

    int a[8];

    for(int i = 0; i < len; i++){
        a[i] = cur % 10;
        cur = cur / 10;
    }

    if(q == len - 1 && a[p] == 0){
        return -1;
    }
    for(int i = 0; i < len; i++){
        if(i == p){
            ret += mult * a[q];
        }
        else if(i == q){
            ret += mult * a[p];
        }
        else{
            ret += mult * a[i];
        }
        mult *= 10;
    }
    return ret;

}

int dp(int n, int i, int len){
    if(dp_arr[n][i] != 0){
        return dp_arr[n][i];
    }
    if(n >=1 && n <= 9){
        return -1;
    }
    if(i == 0){
        return n;
    }
    int cur_max = -1;
    int cur_num;
    for(int p = 0; p < len; p++){
        for(int q = 0; q < p; q++){
            cur_num = make_int(n, p, q, len);
            if(cur_max < dp(cur_num, i-1, len)){
                cur_max = dp(cur_num, i-1, len);
            }
        }
    }
    dp_arr[n][i] = cur_max;
    return cur_max;
}

int main(){
    int n, k;
    scanf(" %d %d", &n, &k);
    printf("%d\n", dp(n, k, int(floor(log10(n) + 1))));
}
