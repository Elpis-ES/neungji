#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> v;
    string s;
    cin >> s;
    string c = "";
    for(auto it = s.rbegin(); it != s.rend(); it++){
        c = *it + c;
        v.emplace_back(c);
    }
    sort(v.begin(), v.end());
    for(auto i : v){
        cout << i << "\n";
    }
}
