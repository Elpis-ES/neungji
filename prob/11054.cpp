#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp_arr;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    v = vector<int> (n);
    dp_arr = vector<vector<int>> (2, vector<int> (n));

    for(auto &i : v){
        cin >> i;
    }

    int ret = 0;
    for(int i = 0; i < n; i++){
        int target = v[i];
        int increase_max = 0;
        int decrease_max = 0;
        for(int j = 0; j < i; j++){
            int cur = v[j];
            if(v[j] < target){
                increase_max = max(increase_max, dp_arr[0][j]);
            }
            if(v[j] > target){
                decrease_max = max(decrease_max, max(dp_arr[0][j], dp_arr[1][j]));
            }
        }
        dp_arr[0][i] = increase_max + 1;
        dp_arr[1][i] = decrease_max + 1;
        ret = max(max(dp_arr[0][i], dp_arr[1][i]), ret);
    }
    cout << ret << "\n";
}
