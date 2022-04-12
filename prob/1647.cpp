#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<bool> connected (n, false);
    priority_queue<tuple<int, int, int>> pq;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.emplace(-c, a, b);
    }
    int added = 0;
    while(!pq.empty()){
        auto [w, a, b] = pq.top();
        pq.pop();
        w = -w;

        if(!(connected[a] && connected[b])){
            if(!connected[a]){
                connected[a] = true;
                added++;
            }
            if(!connected[b]){
                connected[b] = true;
                added++;
            }
            cout << "ADD " << a << ", " << b << ": " << w << "\n";
        }
        else{
            cout << a << ", " << b << ": Already added\n";
        }
    }
}
