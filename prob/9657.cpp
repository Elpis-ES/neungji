#include <bits/stdc++.h>

using namespace std;

int dp_arr[1001][2];

int dp(int n, int p){
    int nxt = p == 1 ? 2 : 1;
    if(n == 1 || n == 3 || n == 4){
        return p;
    }
    else if(n == 2){
        return nxt;
    }
    else if(dp_arr[n][p-1] != 0){
        return dp_arr[n][p-1];
    }
    else{
        int a = dp(n-1, nxt);
        int b = dp(n-3, nxt);
        int ret;

        if(a == p || b == p || c == p){
            ret = p;
        }
        else{
            ret = nxt;
        }
        dp_arr[n][p-1] = ret;
        return ret;
    }
}

int main(){
    int i;
    scanf(" %d", &i);
    printf("%s\n", dp(i, 1) == 1 ? "SK" : "CY");
}
