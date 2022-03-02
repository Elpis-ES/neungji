#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int tmp;

    ll price = 0;
    int prev;
    int cur;
    cin >> prev;
    for(int i = 0; i < n-1; i++){
        cin >> cur;
        price += (ll)max(prev, cur);
        prev = cur;
    }

    cout << price << "\n";
}
