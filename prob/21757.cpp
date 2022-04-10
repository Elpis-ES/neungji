#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> v;
vector<vector<ll>> dp_arr;
int n;
int target;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp_arr = vector<vector<ll>> (4, vector<ll>(n, 0));
    dp_arr[3] = vector<ll> (n, 1);

    int s = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        s += tmp;
        v.emplace_back(s);
    }

    if(v[n - 1] % 4 != 0){
        cout << "0\n";
        return 0;
    }

    target = v[n - 1] / 4;

    for(int i = n - 2; i >= 0; i--){
        for(int lvl = 2; lvl >= 0; lvl--){
            dp_arr[lvl][i] = dp_arr[lvl][i + 1];
            if(v[i] == (lvl + 1) * target){
                dp_arr[lvl][i] += dp_arr[lvl + 1][i + 1];
            }
        }
    }

    cout << dp_arr[0][0] << "\n";
}
