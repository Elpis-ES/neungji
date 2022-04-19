#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> prev(1000001, 0);
    vector<int> nxt(1000001, 0);

    int n, m;
    cin >> n >> m;
    int tmp;
    int p;

    cin >> tmp;
    prev[tmp] = tmp;
    nxt[tmp] = tmp;
    p = tmp;

    for(int i = 1; i < n; i++){
        cin >> tmp;
        prev[tmp] = p;
        nxt[tmp] = nxt[p];
        prev[nxt[tmp]] = tmp;
        nxt[prev[tmp]] = tmp;
        p = tmp;
    }

    int a, b;
    int target;

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        switch(s[0]){
            case 'B':
                cin >> a >> b;
                switch(s[1]){
                    case 'N':
                        cout << nxt[a] << "\n";
                        prev[b] = a;
                        nxt[b] = nxt[a];
                        prev[nxt[a]] = b;
                        nxt[a] = b;
                        break;
                    case 'P':
                        cout << prev[a] << "\n";
                        prev[b] = prev[a];
                        nxt[b] = a;
                        nxt[prev[a]] = b;
                        prev[a] = b;
                        break;

                }
                break;
            case 'C':
                cin >> a;
                switch(s[1]){
                    case 'N':
                        target = nxt[a];
                        break;
                    case 'P':
                        target = prev[a];
                        break;
                }
                cout << target << "\n";
                nxt[prev[target]] = nxt[target];
                prev[nxt[target]] = prev[target];
                nxt[target] = 0;
                prev[target] = 0;
                break;
        }
    }

}
