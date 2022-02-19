#include <bits/stdc++.h>

using namespace std;

int w[101][101];
int nxt[101][101];


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
            cout << (w[i][j] == 0x3f3f3f3f ? 0 : w[i][j]) << " ";
        }
        cout << "\n";
    }

    vector<int> tmp_v;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                cout << "0\n";
                continue;
            }
            if(w[i][j] != 0x3f3f3f3f){
                tmp_v = vector<int> ();
                tmp_v.push_back(i);
                int nxt_pt = nxt[i][j];
                do{
                    tmp_v.push_back(nxt_pt);
                    nxt_pt = nxt[nxt_pt][j];
                }while(nxt_pt != 0);
                cout << tmp_v.size() << " ";
                for(auto it = tmp_v.begin(); it != tmp_v.end(); it++){
                    cout << *it << " ";
                }
                cout << "\n";
            }
            else{
                cout << "0\n";
            }
        }
    }
}
