#include <bits/stdc++.h>

#define ll int
#define MOD 1000000007

using namespace std;

ll dp_arr[1001][1001];

int main(void){
    int n, m;
    scanf(" %d %d", &n, &m);
    for(int x = 1; x <=n; x++){
        for(int y= 1; y <=m; y++){
            if(x == 1 || y == 1){
                dp_arr[x][y] = 1;
            }
            else{
                dp_arr[x][y] = ((dp_arr[x-1][y] % MOD) + (dp_arr[x][y-1] % MOD)) % MOD + (dp_arr[x-1][y-1] % MOD);
            }
        }
    }
    printf("%d\n", dp_arr[n][m] % MOD);
}

