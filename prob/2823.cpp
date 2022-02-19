#include <bits/stdc++.h>

using namespace std;

char arr[10][10];

int main(){
    int r, c;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    scanf(" %d %d", &r, &c);
    for(int j = 0; j < r; j++){
        for(int i = 0; i < c; i++){
            scanf(" %c", &arr[i][j]);
        }
    }

    int cnt = 0;
    for(int j = 0; j < r; j++){
        for(int i = 0; i < c; i++){
            if(arr[i][j] == '.'){
                cnt = 0;
                for(int k = 0; k < 4; k++){
                    if(i + dx[k] >= 0 && i + dx[k] < c && j + dy[k] >= 0 && j + dy[k] < r){
                        if(arr[i][j] == '.' && arr[i+dx[k]][j+dy[k]] == '.'){
                            cnt++;
                        }
                    }
                }
                if(cnt == 0 || cnt == 1){
                    printf("1\n");
                    return 0;
                }

            }
        }
    }
    printf("0\n");
    return 0;
}
