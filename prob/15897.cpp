#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int s = (int)floor(sqrt(n - 1));

    ll res = n - (s * s);
    int prev = 0;
    for(int i = s; i > 0; i--){
        int x = (n - 1) / i;
        res += (x - prev) * i * 2;
        prev = x;
    }
    cout << res << "\n";

}
