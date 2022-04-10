#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> w(3);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    w[0].resize(n);
    w[1].resize(n);
    w[2].resize(n);

    for(int i = 0; i < n; i++){
        cin >> w[0][i] >> w[1][i] >> w[2][i];
    }

}
