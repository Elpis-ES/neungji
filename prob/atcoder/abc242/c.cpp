#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> dp_arr(n + 1, vector<int>(10, 0));

    for(int i = 1; i < 10; i++){
        dp_arr[2][i]++;
        if(i - 1 >= 1){
            dp_arr[2][i]++;
        }
        if(i + 1 <= 9){
            dp_arr[2][i]++;
        }
    }

    for(int i = 3; i <= n; i++){
        for(int j = 1; j < 10; j++){
            int cur = dp_arr[i-1][j];
            if(j - 1 >= 1){
                cur = (cur + dp_arr[i-1][j-1]) % MOD;
            }
            if(j + 1 <= 9){
                cur = (cur + dp_arr[i-1][j+1]) % MOD;
            }
            dp_arr[i][j] = cur;
        }
    }

    int sum = 0;
    for(int i = 1; i < 10; i++){
        sum = (sum + dp_arr[n][i]) % MOD;
    }

    cout << sum << "\n";

 }
