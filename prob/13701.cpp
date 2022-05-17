#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> v ((1 << 25), false);
    int i;
    while(cin >> i){
        if(v[i] == false){
            cout << i << " ";
            v[i] = true;
        }
    }
    cout << "\n";

}
