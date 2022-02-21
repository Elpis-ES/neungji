#include <bits/stdc++.h>

using namespace std;

pair<int, char> arr[10][4][4];
pair<int, char> tree[273][5][5];
pair<int, char> tmp[4][4];

void rotate(int n){
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            tmp[x][y] = arr[n][y][3-x];
        }
    }
}

void fill(pair<int, char>[5][5]* a, int x, int y){
    int tmp_coordinate;
    tmp_coordinate = (x == 0 ? 4 : 0);
    for(int q = 0; q < 5; q++){
        *(a[tmp_coordinate][q]).first = 0;
        *(a[tmp_coordinate][q]).second = 'W';
    }

    tmp_coordinate = (y == 0 ? 4 : 0);
    for(int p = 0; p < 5; p++){
        *(a[p][tmp_coordinate]).first = 0;
        *(a[p][tmp_coordinate]).second = 'W';
    }

    for(int q = y; q < y + 4; q++){
        for(int p = x; p < x + 4; p++){
            *(a[p][q]).first = tmp[p][q].first;
            *(a[p][q]).second = tmp[p][q].second;
        }
    }

}

int main(){
    int n;
    int max = -1;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            scanf(" %d %d %d %d", &(arr[i][j][0].first), &(arr[i][j][1].first), &(arr[i][j][2].first), &(arr[i][j][3].first));
        };
        for(int j = 0; j < 4; j++){
            scanf(" %c %c %c %c", &(arr[i][j][0].second), &(arr[i][j][1].second), &(arr[i][j][2].second), &(arr[i][j][3].second));
        };

    }
    return 0;
}
