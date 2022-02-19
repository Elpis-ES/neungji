#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<tuple<int, int, char>> v;

    int n, m, a, b;
    char c;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v.emplace_back(b, a, c);
    }
    sort(v.begin(), v.end());

    for(auto const& [p, q, r] : v){
        cout << r;
    }
    cout << "\n";
}
