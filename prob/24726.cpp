#include <bits/stdc++.h>

using namespace std;

double calc(vector<int> v_x, vector<int> v_y){
    int max_y_idx = max_element(v_y.begin(), v_y.end()) - v_y.begin();
    int x_1 = (max_y_idx + 1) % 3;
    int x_2 = (max_y_idx + 2) % 3;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v_x;
    vector<int> v_y;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v_x.emplace_back(x);
        v_y.emplace_back(y);
    }

    calc(v_x, v_y);
    calc(v_y, v_x);
}
