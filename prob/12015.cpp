#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        auto t = upper_bound(v.begin(), v.end(), tmp);
        if(t == v.end()){
            v.emplace_back(tmp);
        }
        else{
            *t = tmp;
        }
    }
    cout << v.size() << "\n";

}
