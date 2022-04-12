#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int g, p;
    cin >> g >> p;
    int v[100001];
    for(int i = 0; i <= g; i++){
        v[i] = i;
    }

    int cnt = 0;
    for(int i = 0; i < p; i++){
        int cur;
        cin >> cur;

        int idx = cur;
        while(v[idx] != idx){
            idx = v[idx];
        }

        if(v[idx] == 0){
            break;
        }

        v[idx]--;
        v[cur] = v[idx];

        cnt++;
    }
    cout << cnt << "\n";
}
