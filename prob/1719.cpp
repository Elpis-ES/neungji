#include <bits/stdc++.h>


using namespace std;

int w[201][201];
int nxt[201][201];


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
        if(d < w[f][t]){
            w[f][t] =  d;
            nxt[f][t] = t;
        }
        if(d < w[t][f]){
            w[t][f] = d;
            nxt[t][f] = f;
        }
    }
    int tmp_w;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                tmp_w = w[i][k] + w[k][j];
                if(tmp_w < w[i][j]){
                    w[i][j] = tmp_w;
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                cout << "- ";
            }
            else{
                cout << nxt[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
