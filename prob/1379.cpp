#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> room (n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cur_class;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> lecture;

    for(int i = 0; i < n; i++){
        int r, f, t;
        cin >> r >> f >> t;
        lecture.emplace(f, t, r - 1);
    }

    int max_room = 1;
    auto [s, e, nn] = lecture.top();
    lecture.pop();
    cur_class.emplace(e, max_room);
    room[nn] = max_room;

    while(!lecture.empty()){
        auto [start, end, i] = lecture.top();
        lecture.pop();

        auto[vacant_time, t] = cur_class.top();
        if(start >= vacant_time){
            cur_class.pop();
            room[i] = t;
            cur_class.emplace(end, t);
        }
        else{
            max_room++;
            room[i] = max_room;
            cur_class.emplace(end, max_room);
        }
    }
    cout << max_room << "\n";
    for(auto i : room){
        cout << i << "\n";
    }

}
