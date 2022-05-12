#include <bits/stdc++.h>

using namespace std;
string a, b;
int a_len, b_len;
vector<vector<int>> dp_arr;
vector<vector<pair<int, int>>> prev_vec;

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
        if(p - 1 >= 0 && q - 1 >= 0){
            prev_vec[p][q].first = p - 1;
            prev_vec[p][q].second = q - 1;
        }
    }
    else{
        int l = dp(p - 1, q);
        int m = dp(p, q - 1);
        if(l > m){
            cur = l;
            if(p - 1 >= 0){
                prev_vec[p][q].first = p - 1;
                prev_vec[p][q].second = q;
            }
        }
        else{
            cur = m;
            if(q - 1 >= 0){
                prev_vec[p][q].first = p;
                prev_vec[p][q].second = q - 1;
            }
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
    prev_vec = vector<vector<pair<int, int>>> (a_len, vector<pair<int, int>> (b_len, make_pair(-1, -1)));

    cout << dp(a_len - 1, b_len - 1) << "\n";

    vector<char> c;

    int x = a_len - 1;
    int y = b_len - 1;
    while(!(x == -1 && y == -1)){
        if(a[x] == b[y]){
            c.emplace_back(a[x]);
        }
        int tmp_x = prev_vec[x][y].first;
        int tmp_y = prev_vec[x][y].second;
        x = tmp_x;
        y = tmp_y;
    }

    for(auto it = c.rbegin(); it != c.rend(); it++){
        cout << *it;
    }
    cout << "\n";

}
