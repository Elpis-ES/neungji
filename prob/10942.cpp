#include <bits/stdc++.h>

using namespace std;


int main(){

    int n;
    cin >> n;
    vector<int> v (n);
    vector<vector<bool>> dp_arr (n, vector<bool> (n, false));

    for(int i = 0; i < n; i++){
        cin >> v[i];
        dp_arr[i][i] = true;
    }
    for(int i = 1; i < n; i++){
        if(v[i] == v[i - 1]){
            dp_arr[i-1][i] = true;
        }
    }

    for(int i = 2; i < n; i++){
        for(int f = 0; f + i < n; f++){
            dp_arr[f][f + i] = dp_arr[f + 1][f + i - 1] & (v[f] == v[f + i]);
        }
    }
    cin >> n;

    for(int i = 0; i < n; i++){
        int f, t;
        cin >> f >> t;
        cout << dp_arr[f-1][t-1] << "\n";
    }

}
