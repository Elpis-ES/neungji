#include <bits/stdc++.h>
#define MOD 900528

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<char, int> m;

    string s, t;
    cin >> s >> t;
    int d = s.length();
    for(int i = 1; i <= d; i++){
        m.insert({s[i - 1], i});
    }
    int total = 0;
    for(auto c : t){
        total = (total * d) % MOD;
        total += m[c];
        total = total % MOD;
    }
    cout << total << "\n";
}
