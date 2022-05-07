#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, k, c;

    cin >> n >> d >> k >> c;

    vector<int> sushi;
    vector<int> tbl(d + 1, 0);
    int start = 0;
    int ret = 0;

    int kind = 1;
    tbl[c]++;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        sushi.emplace_back(tmp);
        if(i < k){
            if(tbl[tmp] == 0){
                kind++;
            }
            tbl[tmp]++;
        }
    }
    for(start = 0; start < n; start++){
        ret = max(kind, ret);
        tbl[sushi[start]]--;
        if(tbl[sushi[start]] == 0){
            kind--;
        }
        int sushi_add = (start + k) % n;
        if(tbl[sushi[sushi_add]] == 0){
            kind++;
        }
        tbl[sushi[sushi_add]]++;
    }
    cout << ret << "\n";

}
