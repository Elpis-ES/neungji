#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int psum = v[0];
    if(psum != 1){
        cout << "1\n";
        return 0;
    }
    for(int i = 1; i < v.size(); i++){
        if(psum + 1 >= v[i]){
            psum += v[i];
        }
        else{
            break;
        }
    }
    cout << psum + 1 <<"\n";
}
