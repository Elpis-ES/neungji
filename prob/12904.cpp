#include <bits/stdc++.h>

using namespace std;
vector<bool> to;
vector<bool> from;

int main(){
    string t, f;
    cin >> t;
    for(int i = 0; i < t.size(); i++){
        to.push_back(t[i] == 'A' ? false : true);
    }
    cin >> f;
    for(int i = 0; i < f.size(); i++){
        from.push_back(f[i] == 'A' ? false :true);
    }

    while(from.size() > to.size()){
        if(from[from.size() - 1] == false){
            from.pop_back();
        }
        else{
            from.pop_back();
            reverse(from.begin(), from.end());
        }
    }

    int eq = true;
    for(int i = 0; i < to.size(); i++){
        if(to[i] != from[i]){
            eq = false;
            break;
        }
    }
    cout << eq << "\n";
}
