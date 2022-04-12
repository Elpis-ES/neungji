#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> seq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    v = vector<int> (n + 1);
    seq = vector<int> (n + 1);

    v[1] = 0;
    seq[1] = 0;

    for(int i = 2; i <= n; i++){
        int nxt_seq = i - 1;
        int nxt_val = v[i - 1];

        if(i % 2 == 0){
            if(nxt_val > v[i / 2]){
                nxt_val = v[i / 2];
                nxt_seq = i / 2;
            }
        }
        if(i % 3 == 0){
            if(nxt_val > v[i / 3]){
                nxt_val = v[i / 3];
                nxt_seq = i / 3;
            }
        }
        seq[i] = nxt_seq;
        v[i] = nxt_val + 1;
    }

    cout << v[n] << "\n";

    while(n != 0){
        cout << n << " ";
        n = seq[n];
    }
    cout << "\n";
}
