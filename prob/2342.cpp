#include <bits/stdc++.h>
#define INF 100000000

using namespace std;

vector<int> v;
vector<vector<vector<int>>> dp_arr;

int move(int f, int t){
    if (f == t){
        return 1;
    }
    else if(f == 0){
        return 2;
    }
    else if(abs(f - t) == 2){
        return 4;
    }
    else{
        return 3;
    }
}

int dp(int i, int l, int r){
    if(l == r){
        return INF;
    }
    if(i == v.size()){
        return 0;
    }
    if(dp_arr[i][l][r] != -1){
        return dp_arr[i][l][r];
    }
    int lf_move = move(l, v[i]) + dp(i + 1, v[i], r);
    int rf_move = move(r, v[i]) + dp(i + 1, l, v[i]);
    dp_arr[i][l][r] = min(lf_move, rf_move);
    return dp_arr[i][l][r];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tmp;
    while (true){
        cin >> tmp;
        if(tmp == 0){
            break;
        }
        v.emplace_back(tmp);
    };

    dp_arr = vector<vector<vector<int>>> (v.size(), vector<vector<int>> (5, vector<int> (5, -1)));

    int lf_move = dp(1, v[0], 0) + move(0, v[0]);
    int rf_move = dp(1, 0, v[0]) + move(0, v[0]);
    cout << min(lf_move, rf_move) << "\n";
}
