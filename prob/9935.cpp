#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    string target;

    cin >> s >> target;
    stack<char> str_stack;
    stack<int> idx_stack;

    int cmp_idx = 0;

    for(char c : s){
        str_stack.push(c);
        if(c == target[cmp_idx]){
            cmp_idx++;
        }
        else{
            if(c == target[0]){
                if(cmp_idx != 0){
                    idx_stack.push(cmp_idx);
                }
                cmp_idx = 1;
            }
            else{
                cmp_idx = 0;
                while(!idx_stack.empty()){
                    idx_stack.pop();
                }
            }
        }
        if(cmp_idx == target.length()){
            for(int i = 0; i < target.length(); i++){
                str_stack.pop();
            }
            if(!idx_stack.empty()){
                cmp_idx = idx_stack.top();
                idx_stack.pop();
            }
            else{
                cmp_idx = 0;
            }
        }
    }

    if(str_stack.empty()){
        cout << "FRULA\n";
    }
    else{
        string tmp = "";
        while(!str_stack.empty()){
            tmp += str_stack.top();
            str_stack.pop();
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << "\n";
    }
}
