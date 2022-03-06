#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> cnt_arr(26, 0);

    for(int i = 0; i < s.length(); i++){
        cnt_arr[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        char c = 'a' + i;
        for(int j = 0; j < cnt_arr[i]; j++){
            cout << c;
        }
    }
    cout << "\n";
}
