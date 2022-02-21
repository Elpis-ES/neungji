#include <bits/stdc++.h>

using namespace std;

bool cached[101][101];
bool dp[101][101];

bool match(const char *s, int s_len, const char *regex, int r_len){
    if(regex[0] == '*' && r_len == 1){
        return true;
    }
    if((r_len == 0 && s_len != 0) || (s_len == 0 && r_len != 0)){
        return false;
    }
    if(r_len == 0 && s_len == 0){
        return true;
    }
    if(cached[s_len][r_len]){
        return dp[s_len][r_len];
    }
    bool res;
    if(regex[0] != '*'){
        if(s[0] != regex[0]){
            res = false;
        }
        else{
            res =  match(&s[1], s_len - 1, &regex[1], r_len - 1);
        }
    }
    else{
        res = match(&s[1], s_len - 1, &regex[1], r_len - 1) || match(s, s_len, &regex[1], r_len - 1) || match(&s[1], s_len - 1, regex, r_len);
    }
    cached[s_len][r_len] = true;
    dp[s_len][r_len] = res;
    return res;
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    string target;
    for(int i = 0; i < n; i++){
        cin >> target;
        memset(cached, 0, sizeof(bool) * 101 * 101);
        memset(dp, 0, sizeof(bool) * 101 * 101);
        if(match(target.c_str(), target.length(), s.c_str(), s.length())){
            cout << target << "\n";
        }
    }
}
