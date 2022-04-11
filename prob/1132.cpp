#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> s;
    vector<ll> v(10, 0);
    vector<bool> can_be_zero(10, true);

    int n;
    cin >> n;

    vector<ll> pow10;
    ll p = 1;
    while(pow10.size() != 14){
        pow10.emplace_back(p);
        p *= 10;
    }

    int alpha_used = 0;
    for(int i = 0; i < n; i++){
        string ss;
        cin >> ss;
        s.emplace_back(ss);
        for(int j = 0; j < ss.length(); j++){
            int target_idx = ss[j] - 'A';
            int cur_digit = ss.length() - j - 1;
            if(v[target_idx] == 0){
                alpha_used++;
            }
            v[target_idx] += pow10[cur_digit];
            if(j == 0){
                can_be_zero[target_idx] = false;
            }
        }
    }

    if(alpha_used == 10){
        ll cur_min = LLONG_MAX;
        int min_idx = -1;
        for(int i = 0; i < 10; i++){
            if(can_be_zero[i] && cur_min > v[i]){
                cur_min = v[i];
                min_idx = i;
            }
        }
        v[min_idx] = 0;
    }
    sort(v.begin(), v.end());

    ll sum = 0;
    for(ll i = 0; i < 10; i++){
        sum += i * v[i];
    }
    cout << sum << "\n";

}
