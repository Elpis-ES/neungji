#include <bits/stdc++.h>

using namespace std;

int n, a, b;
vector<int> pos;

vector<int> dp_arr;

inline int weight(int from, int to){
    int r = (pos[to] - pos[from]);
    return 2 * a + b * r;
}

int dp(int from){
    if(dp_arr[from] != -1){
        return dp_arr[from];
    }
    int ret = weight(from, n - 1);
    for(int i = from; i < n; i++){
        ret = min(ret, weight(from, i) + dp(i + 1));
    }
    dp_arr[from] = ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> b;

    pos = vector<int> (n);
    dp_arr = vector<int> (n, -1);

    for(auto &it : pos){
        cin >> it;
    }

    sort(pos.begin(), pos.end());
    int res = dp(0);
    cout << (res >> 1);
    if(res % 2 == 1){
        cout << ".5\n";
    }
    else{
        cout << "\n";
    }
}
