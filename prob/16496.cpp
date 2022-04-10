#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [](string a, string b) {return a + b > b + a;});
    if(v[0] != "0"){
        for(int i = 0; i < n; i++){
            cout << v[i] << " | ";
        }
    }
    else{
        cout << "0";
    }
    cout << "\n";
}
