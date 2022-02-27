#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;
vector<ll> a;
vector<ll> dp_prev;
vector<ll> dp_cur;
vector<vector<ll>> dp_arr;

ll cost(int i, int j){
    if(dp_arr[i][j] != LLONG_MIN){
        return dp_arr[i][j];
    }
    else{
        ll ret = 0;
        for(int k = i; k <= j; k++){
            ret = ret | a[k];
        }
        dp_arr[i][j] = ret;
        return ret;
    }
}

void compute(int l, int r, int optl, int optr){
    if(l > r)
        return;

    int mid = (l + r) >> 1;
    pair<ll, int> best = {0, -1};

    for(int i = optl; i <= min(mid, optr); i++){
        best = max(best, {(i ? dp_prev[i - 1] : 0) + cost(i, mid), i});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        a.emplace_back(tmp);
    }

    dp_prev = vector<ll> (n+1);
    dp_cur = vector<ll> (n+1);
    dp_arr = vector<vector<ll>> (n+1, vector<ll> (n+1, LLONG_MIN));

    for(int i = 0; i < n; i++){
        dp_prev[i] = cost(0, i);
    }

    for(int i = 1; i < k; i++){
        compute(0, n - 1, 0, n - 1);
        dp_prev = dp_cur;
    }

    cout << dp_prev[n-1] << "\n";

}
