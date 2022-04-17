#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(20002);

    int s = sqrt(20002) + 1;
    vector<int> sqrtv(s);

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;

        v[tmp + 10000]++;
        sqrtv[(tmp + 10000) / s]++;
        int m = (i >> 1) + 1;
        int cnt = 0;
        int target = 0;
        for(; target < s && sqrtv[target] + cnt < m; target ++){
            cnt += sqrtv[target];
        }

        target = target * s;

        while(cnt + v[target] < m){
            cnt += v[target];
            target++;
        }

        cout << target - 10000 << "\n";
    }

}
