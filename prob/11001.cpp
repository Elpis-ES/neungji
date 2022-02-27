#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> t;
vector<ll> v;
int n, d;

ll ret = -1;

ll c(int i, int j){
    return (j - i) * t[j] + v[i];
}

void compute(int l, int r, int optl, int optr){
    if(l > r)
        return;

    int mid = (l + r) >> 1;
    pair<ll, int> best = {0, -1};
    for(int k = max(optl, mid - d) ; k <= min(mid, optr); k++){
        best = max(best, {c(k, mid), k});
    }

    ret = max(ret, best.first);
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;

    ll tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        t.emplace_back(tmp);
    }

    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }

    compute(0, n-1, 0, n-1);

    cout << ret << "\n";

}
