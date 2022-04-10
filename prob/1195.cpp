#include <bits/stdc++.h>
#define ul unsigned long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, l;
    cin >> s >> l;

    if(s.length() > l.length())
        swap(s, l);

    ul len = s.length() + l.length();

    for(int i = 0; i < l.length() - s.length(); i++){
        bool match = true;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '2' && l[i + j] == '2'){
                match = false;
                break;
            }
        }
        if(match){
            len = l.length();
        }
    }

    for(int i = 0; i < s.length(); i++){
        bool match = true;
        for(int j = 0; j <= i; j++){
            if(s[s.length() - 1 - i + j] == '2' && l[j] == '2'){
                match = false;
                break;
            }
        }
        if(match){
            len = min(len, s.length() + l.length() - 1 - i);
        }
    }

    for(int i = 0; i < s.length(); i++){
        bool match = true;
        for(int j = 0; j <= i; j++){
            if(s[j] == '2' && l[l.length () - 1 - i + j] == '2'){
                match = false;
                break;
            }
        }
        if(match){
            len = min(len, s.length() + l.length() - 1 - i);
        }
    }

    cout << len << "\n";

}
