#include <bits/stdc++.h>

using namespace std;
string a, b;
int a_len, b_len;
vector<vector<int>> dp_arr;
vector<vector<string>> dp_str;

string get_str(int p, int q){
    if(p < 0 || q < 0){
        return "";
    }
    else{
        return dp_str[p][q];
    }
}

int dp(int p, int q){
    if(p < 0 || q < 0){
        return 0;
    }
    if(dp_arr[p][q] != -1){
        return dp_arr[p][q];
    }
    int cur;
    if(a[p] == b[q]){
        cur = dp(p - 1, q - 1) + 1;
        dp_str[p][q] = get_str(p - 1, q - 1) + a[p];
    }
    else{
        int l = dp(p - 1, q);
        int m = dp(p, q - 1);
        if(l > m){
            cur = l;
            dp_str[p][q] = get_str(p - 1, q);
        }
        else{
            cur = m;
            dp_str[p][q] = get_str(p, q - 1);
        }
    }
    dp_arr[p][q] = cur;
    return cur;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a;
    cin >> b;
    a_len = a.length();
    b_len = b.length();

    dp_arr = vector<vector<int>> (a_len, vector<int> (b_len, -1));
    dp_str = vector<vector<string>> (a_len, vector<string> (b_len, ""));

    cout << dp(a_len - 1, b_len - 1) << "\n";
    cout << get_str(a_len - 1, b_len - 1) << "\n";
}
