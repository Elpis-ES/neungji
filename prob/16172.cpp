#include <bits/stdc++.h>

using namespace std;

string s, w;
vector<int> t;

void generate_table(){
    t[0] = -1;
    int pos = 1;
    int cnd = 0;

    while(pos < w.length()){
        if(w[pos] == w[cnd]){
            t[pos] = t[cnd];
        }
        else{
            t[pos] = cnd;
            while(cnd >= 0 && w[pos] != w[cnd]){
                cnd = t[cnd];
            }
        }
        pos++;
        cnd++;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    while(true){
        c = cin.get();
        if(c == '\n'){
            break;
        }
        if(c >= '0' && c <= '9'){
            continue;
        }
        s.push_back(c);
    }
    cin >> w;

    t = vector<int>(w.length() + 1, 0);
    generate_table();

    int np = 0;
    int j = 0;
    int k = 0;
    bool found = false;
    while(j < s.length()){
        if(w[k] == s[j]){
            j++;
            k++;
            if(k == w.length()){
                found = true;
                break;
            }
        }
        else{
            k = t[k];
            if(k < 0){
                j++;
                k++;
            }
        }
    }

    cout << (found ? "1\n" : "0\n");

}

