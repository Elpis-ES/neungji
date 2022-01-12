#include <bits/stdc++.h>

using namespace std;

char map_arr[1001][1001];
bool pushed[1001][1001];
pair<int, int> boss;
int player[26];

int main(){
    int m, n, p, health;
    char tmp;
    scanf(" %d %d %d\n", &m, &n, &p);
    for(int y = 1; y <=m; y++){
        for(int x = 1; x <=n; x++){
            scanf("%c", &map_arr[x][y]);
            if(map_arr[x][y] == 'B'){
                boss.first = x;
                boss.second = y;
                pushed[x][y] = 0;
                map_arr[x][y] = 0;
            }
        }
        scanf("%c", &tmp);
    }
    char c;
    for(int i = 0; i < p; i++){
        scanf("%c", &c);
        scanf(" %d\n", &player[c-'a']);
    }
    scanf(" %d", &health);

    queue<pair<int, int>  > v;
    if(boss.first > 1 && map_arr[boss.first -1][boss.second] != 'X'){
        v.push(make_pair(boss.first - 1, boss.second));
        pushed[boss.first - 1][boss.second]=true;
    }
    if(boss.first < n && map_arr[boss.first + 1][boss.second] != 'X'){
        v.push(make_pair(boss.first + 1, boss.second));
        pushed[boss.first + 1][boss.second] = true;
    }
    if(boss.second > 1 && map_arr[boss.first][boss.second -1] != 'X'){
        v.push(make_pair(boss.first, boss.second - 1));
        pushed[boss.first][boss.second - 1] = true;
    }
    if(boss.second < m && map_arr[boss.first][boss.second +1] != 'X'){
        v.push(make_pair(boss.first, boss.second + 1));
        pushed[boss.first][boss.second + 1] = true;

    }
    v.push(make_pair(-1, -1));

    int range = 1;

    int player_found = 0;
    int dps = 0;
    int x, y, dir;

    while(true){
        x = v.front().first;
        y = v.front().second;
        v.pop();
        if(x == -1 && y == -1){
            if(v.empty()){
                break;
            }
            health -= dps;
            if(health <= 0){
                break;
            }
            range++;
            v.push(make_pair(-1, -1));
        }
        else{
            if(x > 1 && map_arr[x-1][y] && map_arr[x-1][y] != 'X' && !pushed[x-1][y]){
                v.push(make_pair(x-1, y));
                pushed[x-1][y] = true;
            }
            if(x < n && map_arr[x+1][y] && map_arr[x+1][y] != 'X' && !pushed[x+1][y]){
                v.push(make_pair(x+1, y));
                pushed[x+1][y] = true;
            }
            if(y > 1 && map_arr[x][y-1] && map_arr[x][y-1] != 'X' && !pushed[x][y-1]){
                v.push(make_pair(x, y-1));
                pushed[x][y-1] = true;
            }
            if(y < m && map_arr[x][y+1] && map_arr[x][y+1] != 'X' && !pushed[x][y+1]){
                v.push(make_pair(x, y+1));
                pushed[x][y+1] = true;
            }
            if(map_arr[x][y] != '.' && map_arr[x][y]){
                player_found++;
                dps += player[map_arr[x][y]-'a'];
            }
            map_arr[x][y] = 0;
        }
        if(player_found == p){
            break;
        }
    }
    printf("%d\n", player_found);

    return 0;
}
