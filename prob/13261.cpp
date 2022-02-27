#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, g;
vector<ll> sum;
vector<ll> dp_prev;
vector<ll> dp_cur;

ll cost(int i, int j){
    return (j - i + 1) * (sum[j + 1] - sum[i]);
}

void compute(int l, int r, int optl, int optr){
    if(l > r)
        return;

    int mid = (l + r) >> 1;
    pair<ll, int> best = {LLONG_MAX, -1};

    for(int k = optl; k <= min(mid, optr); k++){
        best = min(best, {(k ? dp_prev[k - 1] : 0) + cost(k, mid), k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> g;
    ll tmp;
    sum.emplace_back(0);
    ll val = 0;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        val += tmp;
        sum.emplace_back(val);
    }

    dp_prev = vector<ll> (n);
    dp_cur = vector<ll> (n);

    for(int i = 0; i < n; i++){
        dp_prev[i] = cost(0, i);
    }

    for(int i = 1; i < g; i++){
        compute(0, n - 1, 0, n - 1);
        dp_prev = dp_cur;
    }

    cout << dp_prev[n-1] << "\n";

}
