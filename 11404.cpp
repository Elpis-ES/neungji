#include <bits/stdc++.h>

using namespace std;

int w[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(w, 0x3f, sizeof(w));

    int n, m;
    cin >> n;
    cin >> m;
    int f, t, d;
    for(int i = 0; i <= n; i++){
        w[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        cin >> f >> t >> d;
        w[f][t] = min(w[f][t], d);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << (w[i][j] == 0x3f3f3f3f ? 0 : w[i][j]) << " ";
        }
        cout << "\n";
    }
}
