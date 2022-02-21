#include <bits/stdc++.h>

using namespace std;

int box[1001][1001];

int main(void){
    scanf(" %d %d", &m, &n);
    vector< pair <int, int> > v;
    int zero_cnt = 0;
    int day = 0;
    for(int y = 0; y<n; y++){
        for(int x = 0; x<m; x++){
            scanf(" %d", &box[x][y]);
            if(box[x][y] == 1){
                v.push_back(make_pair(x, y));
            }
            else if(box[x][y] == 0){
                zero_count++;
            }
        }
    }
    v.push_back(make_pair(-1, -1));
    int x, y;
    while(!v.empty()){
        x = v[0].first;
        y = v[0].second;
        v.erase(v.front());
        if(x == -1 && y == -1){
            if(v.empty()){
                if(zero_cnt == 0){
                    break;
                }
                else{
                    day = -1;
                    break;
                }
            }
            else{
                day++;
                v.push_back(make_pair(-1, -1));
            }
        }
    }
    printf("%d\n", day);
}
