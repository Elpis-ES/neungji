#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int,  vector<int>, greater<int>> room;
    for(int i = 0; i < n; i++){
        int p, q;
        cin >> p >> q;
        pq.emplace(p, q);
    }
    int cnt = 1;
    auto [_, q] = pq.top();
    room.emplace(q);
    pq.pop();


    while(!pq.empty()){
        auto [p, q] = pq.top();
        pq.pop();
        if(!room.empty()){
            int cur = room.top();
            if(cur <= p){
                room.pop();
            }
            else{
                cnt++;
            }
            room.emplace(q);
        }
        else{
            room.emplace(q);
        }
    }
    cout << cnt << "\n";
}
