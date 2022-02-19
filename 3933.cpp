#include <bits/stdc++.h>
#define MAX (1 << 15)

using namespace std;

int dp_arr[5][MAX + 1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp_arr[0][0] = 1;
    int val;

    for(int i = 1; i * i <= MAX; i++){
        for(int n = 1; n <= 4; n++){
            for(int j = 0; j <= MAX; j++){
                val = j + (i * i);
                if(val <= MAX){
                    dp_arr[n][val] += dp_arr[n-1][j];
                }
            }
        }
    }

    int n;
    int res;
    while(true){
        cin >> n;
        res = 0;
        if(n == 0){
            break;
        }
        for(int i = 1; i <= 4; i++){
            res += dp_arr[i][n];
        }
        cout << res << "\n";
    }
}
