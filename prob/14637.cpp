#include <bits/stdc++.h>
#include <unistd.h>
#define epsilon 1e-6

using namespace std;

vector<pair<double, double>> v;

inline double calc(double c){
    double ret = 0;
    for(auto[d, s] : v){
        ret += (d / (s + c));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double t;
    cin >> n >> t;
    double lo;
    bool lo_init = false;
    double hi = 1e7;
    for(int i = 0; i < n; i++){
        double d, s;
        cin >> d >> s;
        double cur = (d / t) - s;
        if(!lo_init){
            lo = cur;
            lo_init = true;
        }
        else{
            lo = max(cur, lo);
        }
        v.emplace_back(d, s);
    }

    double cur = (lo + hi) / 2;
    double res = calc(cur);
    while(fabs(t - cur) > epsilon && (hi - lo) > epsilon){
        if(res > t){
            lo = cur;
        }
        else{
            hi = cur;
        }
        cur = (lo + hi) / 2;
        res = calc(cur);
    }
    cout << fixed << setprecision(9) << cur << "\n";
}
