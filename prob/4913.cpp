#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

vector <ll> cnt (1000001, 0);
vector <ll> prime_cnt (1000001, 0);

bool is_prime(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void calc(int l, int u){
    ll cur_cnt = 0;
    ll cur_prime_cnt = 0;
    for(int i = l; i <= u; i++){
        if(is_prime(i)){
            cur_cnt++;
            if((i >= 5 && (i % 4 == 1)) || i == 2){
                cur_prime_cnt++;
            }
        }
        cnt[i] = cur_cnt;
        prime_cnt[i] = cur_prime_cnt;
    }
    return;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, u;

    vector<pair<int, int>> v;

    int l_min = 1000001;
    int u_max = -1000001;
    while(true){
        cin >> l >> u;
        if(l == -1 && u == -1){
            break;
        }
        l_min = min(l_min, l);
        u_max = max(u_max, u);
        v.emplace_back(make_pair(l, u));
    }
    if(l_min < 0){
        l_min = 0;
    }
    if(u_max < 0){
        u_max = 0;
    }
    calc(l_min, u_max);
    int left, right;
    for(auto it = v.begin(); it != v.end(); it++){
        right = it->second < 1 ? 0 : it->second;
        left = it->first < 1 ? 0 : it->first - 1;
        cout << it->first << " " << it->second << " " << cnt[right] - cnt[left] << " " << prime_cnt[right] - prime_cnt[left] << "\n";
    }
}
