#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, x;
    cin >> a >> b >> c >> x;
    double res;
    if(x <= a){
        res = (double)1;
    }
    else if(x <= b){
        res = (double)c / (double)(b - a);
    }
    else{
        res = (double)0;
    }
    cout << setprecision(12) << res << "\n";
}
