#include <bits/stdc++.h>
using namespace std;

map <int, int> m;
int sum = 0;

int drill_hole_in_cow(int g, int d){
    int j;
    int push;
    int ret;
    for(j = d-1; j >=0; j--){
        if(m[j]==0){
            m[j] = g;
            return g;
        }
        else if(m[j] < g){
            push = m[j];
            m[j] = g;
            ret = (g - push) + drill_hole_in_cow(push, j);
            return ret;
        }
    }
    return 0;
}

int main(void){
    int i, N, g, d, j;

    scanf(" %d", &N);
    int sum = 0;
    for(i = 0; i < N; i++){
        scanf(" %d %d", &g, &d);
        sum += drill_hole_in_cow(g, d);
    }

    printf("%d", sum);


}
