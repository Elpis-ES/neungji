#include <bits/stdc++.h>

using namespace std;

int psum[367];

int main(){
    int s, e, n;
    scanf(" %d", &n);
    int sched_start = 367;
    int sched_end = -1;
    for(int i = 0; i < n; i++){
        scanf(" %d %d", &s, &e);
        if(s < sched_start){
            sched_start = s;
        }
        psum[s] += 1;
        if(e > sched_end){
            sched_end = e;
        }
        psum[e+1] -=1;
    }
    int sum = 0;
    int total = 0;
    int h = 0;
    int cur_start = sched_start;
    for(int i = sched_start; i <= sched_end + 1; i++){
        sum = sum +  psum[i];
        if(sum == 0){
            total += (i - cur_start) * h;
            h = 0;
            cur_start = -1;
        }
        else{
            if(cur_start == -1){
                cur_start = i;
            }
            if(sum > h){
                h = sum;
            }
        }
    }
    printf("%d\n", total);
}
