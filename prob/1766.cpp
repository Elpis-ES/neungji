#include <bits/stdc++.h>

#define MOD 1000000000

using namespace std;

int dp_arr[2][1 << 10][10];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    for(int i = 1; i < 10; i++){
        dp_arr[1][(1 << i)][i] = 1;
    }

    for(int dig = 2; dig <= n; dig++){
        memset(dp_arr[dig % 2], 0, sizeof(dp_arr[dig % 2]));
        for(int d = 0; d < 10; d++){
            for(int used = 0; used < (1 << 10); used++){
                if(d - 1 >= 0){
                    dp_arr[dig % 2][(used | (1 << d))][d] = (dp_arr[dig % 2][(used | (1 << d))][d] + dp_arr[(dig - 1) % 2][used][d - 1]) % MOD;
                }
                if(d + 1 < 10){
                    dp_arr[dig % 2][(used | (1 << d))][d] = (dp_arr[dig % 2][(used | (1 << d))][d] + dp_arr[(dig - 1) % 2][used][d + 1]) % MOD;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < 10; i++){
        res = (res + dp_arr[(n % 2)][(1 << 10) - 1][i]) % MOD;
    }

    cout << res << "\n";
}
