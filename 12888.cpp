#include <bits/stdc++.h>

using namespace std;


int main(void){
    int h, i;
    long long dp[61];
    long long psum = 2;
    memset(dp, 0, sizeof(long long)  * 61);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;


    scanf(" %d", &h);
    if(dp[h] != 0){
        printf("%lld\n", dp[h]);
    }
    else{
        for(i = 3; i <= h; i++){
            dp[i] = psum * 2 + 1;
            psum += dp[i-1];
        }
        printf("%lld\n", dp[h]);
    }

    return 0;
}
