#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    s.push_back(' ');
    unordered_set <int> sss;
    string separate = " ";
    size_t pos = 0;
    while((pos = s.find(separate)) != string::npos){
        sss.insert( atoi(s.substr(0, pos).c_str()));
        s.erase(0, pos+separate.length());
    }
    for(auto it = sss.begin(); it!=sss.end(); it++){
        printf("%d ", *it);
    }
    printf("\n");
}
