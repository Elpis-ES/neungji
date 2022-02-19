#include <bits/stdc++.h>

using namespace std;

int map_arr[1001][1001];
bool visited[1001][1001][2];
bool pushed[1001][1001][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void){
    int n, m;
    char c;
    scanf(" %d %d\n", &n, &m);
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= m; x++){
            scanf("%c", &c);
            map_arr[x][y] = c == '0' ? 0 : 1;
        }
        if(y != n){
            scanf("%c", &c);
        }
    }

    queue<pair<pair<int, int> , pair<int, int> > > q;

    q.push(make_pair(make_pair(1, 1), make_pair(0, 1)));
    int x, y, wall, len;
    int x2, y2;
    visited[1][1][0] = true;
    pushed[1][1][0] = true;
    pushed[1][1][1] = true;
    int len_min = -1;
    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        wall = q.front().second.first;
        len = q.front().second.second;
        visited[x][y][wall] = true;
        q.pop();
        if(x == m && y == n){
            if(len_min == -1){
                len_min = len;
            }
            else if(len <len_min){
                len_min = len;
            }
            continue;
        }
        for(int i = 0; i < 4; i++){
            x2 = x + dx[i];
            y2 = y + dy[i];
            if(x2 >= 1 && x2 <= m && y2 >=1 && y2 <= n && !visited[x2][y2][wall]){
                if(wall == 1){
                    if(map_arr[x2][y2] != 1 && !pushed[x2][y2][wall]){
                        q.push(make_pair(make_pair(x2, y2), make_pair(1, len + 1)));
                        pushed[x2][y2][wall] = true;
                    }
                }
                else{
                    if(!pushed[x2][y2][wall]){
                        q.push(make_pair(make_pair(x2, y2), make_pair(map_arr[x2][y2], len+1)));
                        pushed[x2][y2][wall] = true;
                    }
                }

            }
        }

    }
    printf("%d\n", len_min);
}

