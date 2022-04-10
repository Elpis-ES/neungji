#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007ll

using namespace std;

vector<vector<ll>> a (8, vector<ll>(8));

vector<vector<ll>> mult(vector<vector<ll>> p, vector<vector<ll>> q){
    vector<vector<ll>> ret (8, vector<ll>(8, 0));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 8; k++){
                ret[i][j] += p[i][k] * q[k][j];
                ret[i][j] = ret[i][j] % MOD;
            }
        }
    }
    return ret;
}

vector<vector<ll>> dp(int i){
    if(i == 1){
        return a;
    }
    vector<vector<ll>> tmp;
    tmp = dp(i >> 1);
    tmp = mult(tmp, tmp);

    if(i % 2 == 1){
        tmp = mult(tmp, a);
    }
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    a = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
        };
    int n;
    cin >> n;
    vector<vector<ll>> cur = dp(n);
    cout << cur[7][7] << "\n";
}

