#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());

    ll h_sum[2] = {0, 0};
    ll l_sum[2] = {0, 0};
    int cnt = 0;
    int h_idx[2] = {n, n};
    int l_idx[2] = {-1, -1};



    while(cnt != n){
        if(cnt % 2 == 0){
            h_idx[0]--;
            h_sum[0] += v[h_idx[0]];

            l_idx[1]++;
            l_sum[1] += v[l_idx[1]];
        }
        else{
            l_idx[0]++;
            l_sum[0] += v[l_idx[0]];

            h_idx[1]--;
            h_sum[1] += v[h_idx[1]];
        }
        cnt++;
    }
    ll sum[2];
    sum[0] = (h_sum[0] * 2) - (l_sum[0] * 2);
    sum[1] = (h_sum[1] * 2) - (l_sum[1] * 2);
    if(n % 2 == 1){
        sum[0] -= (v[h_idx[0]] + v[h_idx[0] + 1]);
        sum[1] += (v[l_idx[1]] + v[l_idx[1] - 1]);
    }
    else{
        sum[0] -= v[h_idx[0]];
        sum[0] += v[l_idx[0]];

        sum[1] -= v[h_idx[1]];
        sum[1] += v[l_idx[1]];
    }

    cout << max(sum[0], sum[1]) << "\n";
}

