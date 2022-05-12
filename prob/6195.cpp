#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<ull, vector<ull>, greater<ull>> pq;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ull tmp;
        cin >> tmp;
        pq.emplace(tmp);
    }

    ull total = 0;
    while(true){
        ull i = pq.top();
        pq.pop();
        if(pq.empty()){
            break;
        }
        ull j = pq.top();
        pq.pop();
        total += i + j;
        pq.emplace(i + j);
    }

    cout << total << "\n";
}
