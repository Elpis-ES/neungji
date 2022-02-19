#include <bits/stdc++.h>

using namespace std;

int chess_board[14][14][14];

int n_queen(int row, int col, int n){
    if(row == 0){
        memset(chess_board[0], 0, sizeof(int)*14*14);
    }
    else{
        memcpy(chess_board[row], chess_board[row - 1], sizeof(int)*14*14);
    }
    int ret = 0;
    if(row + 1 == n){
        for(int i = 0; i < n; i++){
            if (chess_board[row][row][i] == 0){
                ret++;
            }
        }
        return ret;
    }
    else{
        int diag_up, diag_down;
        for(int i = 0; i < n; i++){
            chess_board[row][row][i] = 1;
            chess_board[row][i][col] = 1;
            diag_up = i - col + row;
            diag_down = col - i + row;
            if(diag_up >=0 && diag_up < n){
                chess_board[row][diag_up][i] = 1;
            }
            if(diag_down >=0 && diag_down < n){
                chess_board[row][diag_down][i] = 1;
            }

        }

        for(int i = 0; i < n; i++){
            if(chess_board[row][row+1][i]==0){
                ret += n_queen(row+1, i, n);
            }
        }
        return ret;
    }
}

int main(void){
    int n;
    int ret;
    for(n = 1; n <=14; n++){
        ret = 0;
        for(int col = 0; col < n; col++){
            ret += n_queen(0, col, n);

        }
        printf("%d, ", ret);
    }
    printf("\n");
}

