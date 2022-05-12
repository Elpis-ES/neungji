#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
int n;

inline bool check_pos(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n){
        return false;
    }
    return true;
}

int move(int x, int y){
    int ret = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v = vector<vector<int>> (n, vector<int>(n));
    for (auto &row: v){
        for(auto &i : row){
            cin >> i;
        }
    }
    int y = n >> 1;
    int x = n >> 1;
}
