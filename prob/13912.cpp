#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long

using namespace std;
vector<vector<int>> ncr;
vector<int> dp_arr;


int dp(int i){
    if(dp_arr[i] != -1){
        return dp_arr[i];
    }
    int n = (1 << (1 + i)) - 2;
    int r = n >> 1;

    ll ret = ncr[n][r];
    int nxt = dp(i - 1);

    ret = (1ll * ret * nxt) % MOD;
    ret = (1ll * ret * nxt) % MOD;

    dp_arr[i] = (int)ret;

    return ret;
}


int main(){
    int h;
    cin >> h;

    int l = 1 << (1 + h);
    dp_arr = vector<int>(11, -1);
    dp_arr[0] = 1;
    dp_arr[1] = 2;
    //dp_arr[2] = 80;

    ncr = vector<vector<int>> (l, vector<int> (l));

    for(int n = 0; n < l; n++){
        for(int r = 0; r <= n; r ++){
            if(r == 0 || r == n){
                ncr[n][r] = 1;
            }
            else{
                ncr[n][r] = (ncr[n - 1][r - 1] + ncr[n - 1][r]) % MOD;
            }
        }
    }

    cout << dp(h) << "\n";

}
