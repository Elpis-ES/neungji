#include <bits/stdc++.h>

using namespace std;

int dp_arr[(1<<15) + 1];

int dp(int n, int left, int prev){
    if(n == 0){
        return 1;
    }
    else if(left == 0){
        return 0;
    }
    else{
        int ret = 0;
        for(int i = prev; i * i <= n; i++){
            ret += dp(n - (i * i), left - 1, i);
        }
        return ret;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp_arr, -1, sizeof(dp_arr));
    int n;
    int res;
    while(true){
        cin >> n;
        res = 0;
        if(n == 0){
            break;
        }
        if(dp_arr[n] == -1){
            for(int i = 1; i * i <= n; i++){
                res += dp(n - (i * i), 3, i);
            }
            dp_arr[n] = res;
        }
        else{
            res = dp_arr[n];
        }
        cout << res << "\n";
    }
}
