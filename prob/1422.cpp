#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> k >> n;
    int repeat = n - k;
    vector<int> v(k);
    for(int i = 0; i < k; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    vector<string> v_new;
    for(int i = 0; i < min(n, k); i++){
        if(i == 0){
            string s = to_string(v[0]);
            for(int j = 0; j < repeat; j++){
                s += to_string(v[0]);
            }
            v_new.emplace_back(s);
        }
        else{
            v_new.emplace_back(to_string(v[i]));
        }
    }
    bool repeated = false;
    sort(v_new.begin(), v_new.end(), [](string a, string b) {return a + b > b + a;});
    for(auto s : v_new){
        cout << s;
    }
    cout << "\n";
}
