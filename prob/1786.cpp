#include <bits/stdc++.h>

using namespace std;

string s, w;
vector<int> fail_check;

void generate_table(){
    int i = 0;
    int j = 1;
    fail_check.emplace_back(0);
    while(j < w.length()){
        if(w[i] == w[j]){
            i++;
            fail_check.emplace_back(i);
            j++;
        }
        else if(i == 0){
            fail_check.emplace_back(0);;
            j++;
        }
        else{
            i = fail_check[i - 1];
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    getline(cin, s);
    getline(cin, w);

    generate_table();

    int w_pos = 0;

    vector<int> found_idx;

    for(int s_pos = 0; s_pos < s.length(); s_pos++){
        while(w_pos && s[s_pos] != w[w_pos]){
            w_pos = fail_check[w_pos - 1];
        }
        if(s[s_pos] == w[w_pos]){
            w_pos++;
        }
        if(w_pos == w.length()){
            found_idx.emplace_back(s_pos - w_pos + 2);
            w_pos = fail_check[w_pos - 1];
        }
    }

    cout << found_idx.size() << "\n";
    for(auto a : found_idx){
        cout << a << " ";
    }
    cout << "\n";
}

