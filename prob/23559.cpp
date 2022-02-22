#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, a, b;

    cin >> n >> x;

    int max_expensive_menu = (x - (n * 1000)) / 4000;

    vector<bool> checked (n, false);
    vector<int> v;

    int total_w = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        total_w += b;
        if( a - b > 0){
            v.emplace_back(a - b);
        }
    }
    sort(v.begin(), v.end(), greater<int>());

    for(auto it = v.begin(); it != v.end(); it++){
        if(max_expensive_menu == 0){
            break;
        }
        total_w += *it;
        max_expensive_menu--;
    }

    cout << total_w << "\n";
}
