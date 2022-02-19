#include <bits/stdc++.h>

using namespace std;

pair<char, int> map_arr[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, m;
    int cnt = 0;
    scanf(" %d %d", &n, &m);
    queue<pair<int, int> > q;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            scanf(" %c", &(map_arr[x][y].first));
            if(y == 0 && map_arr[x][y].first == 'U'){
                map_arr[x][y].second = true;
                q.push(make_pair(x, y));
                cnt++;
            }
            else if(y == n-1 && map_arr[x][y].first == 'D'){
                map_arr[x][y].second = true;
                q.push(make_pair(x, y));
                cnt++;
            }
            else if(x == 0 && map_arr[x][y].first == 'L'){
                map_arr[x][y].second = true;
                q.push(make_pair(x, y));
                cnt++;
            }
            else if(x == m-1 &&map_arr[x][y].first == 'R'){
                map_arr[x][y].second = true;
                q.push(make_pair(x, y));
                cnt++;
            }
        }
    }
    int cur_x, cur_y;
    int target_x, target_y;
    char dir;
    while(!q.empty()){
        cur_x = q.front().first;
        cur_y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            target_x = cur_x + dx[i];
            target_y = cur_y + dy[i];
            if(target_x >= 0 && target_x < m && target_y >= 0 && target_y < n){
                if(!map_arr[target_x][target_y].second){
                    switch(i){
                        case 0:
                            dir = 'L';
                            break;
                        case 1:
                            dir = 'R';
                            break;
                        case 2:
                            dir = 'U';
                            break;
                        case 3:
                            dir = 'D';
                            break;
                        default:
                            break;
                    }
                    if(map_arr[target_x][target_y].first == dir){
                        cnt++;
                        q.push(make_pair(target_x, target_y));
                        map_arr[target_x][target_y].second = true;
                    }
                }
            }
        }

    }
    printf("%d\n", cnt);
}
