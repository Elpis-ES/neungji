#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> dp_arr;
vector<int> h;
int n, k;

int main(){
    int tmp;
    cin >> n >> k;

    dp_arr = vector<vector<ll>> (1 << n, vector<ll> (n, 0));

    for(int i = 0; i < n; i++){
        cin >> tmp;
        h.emplace_back(tmp);
    }

    int current_bit;

    for(int i = 0; i < n; i++){
        dp_arr[1 << i][i] = 1;
    }

    for(int bit = 1; bit < (1 << n); bit++){
        for(int target = 0; target < n; target++){
            if(bit & (1 << target)){
                continue;
            }
            else{
                current_bit = bit | (1 << target);
                for(int i = 0; i < n; i++){
                    if(!(bit & (1 << i))){
                        continue;
                    }
                    else{
                        if(abs(h[i] - h[target]) > k){
                            dp_arr[current_bit][target] += dp_arr[bit][i];
                        }
                    }
                }
            }
        }
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += dp_arr[(1 << n) - 1][i];
    }

    cout << sum << "\n";
}
