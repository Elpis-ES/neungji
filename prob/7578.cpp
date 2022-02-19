#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];

int main(){
    int m, n;
    int unripe = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<pair<int, int> > q;
    scanf(" %d %d", &m, &n);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            scanf(" %d", &arr[i][j]);
            if (arr[i][j] == 1){
                q.push(make_pair(i, j));
            }
            else if(arr[i][j] == 0){
                unripe++;
            }
        }
    }
    int t = 0;
    int x, y;
    bool new_add;
    q.push(make_pair(-1, -1));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        if(x == -1 & y == -1){
            if(new_add == false)
                break;
            t++;
            new_add = false;
            q.push(make_pair(-1, -1));
        }
        else{
            for(int i = 0; i < 4; i++){
                if(x+dx[i] >= 0 && x+dx[i] < m && y+dy[i] >= 0 && y+dy[i] < n){
                    if(arr[x+dx[i]][y+dy[i]] == 0){
                        unripe--;
                        arr[x+dx[i]][y+dy[i]] = 1;
                        q.push(make_pair(x+dx[i], y+dy[i]));
                        new_add = true;
                    }
                }

            }
        }
        if(unripe == 0){
            break;
        }
    }
    if(unripe != 0){
        printf("-1\n");
    }
    else{
        printf("%d\n", t);
    }
}
