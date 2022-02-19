#include <bits/stdc++.h>

using namespace std;

char arr[1001][1001];

bool is_unique(int start, int end, int c){
    unordered_set <string> s;
    string tmp;
    for(int i = 0; i < c; i++){
        tmp = arr[i];
        tmp = tmp.substr(start, end);
        s.insert(tmp);
    }
    return s.size() == c;
}

int main(){
    int r, c;
    scanf(" %d %d", &r, &c);
    string tmp;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf(" %c", &arr[j][i]);
        }
    }

    int start = 0;
    int end = r;
    int target = (start + end) / 2;
    bool res;
    while(start != end){
        printf("Check %d, start: %d, end: %d\n", target, start, end);
        res = is_unique(target, end, c);
        printf("%s\n", res? "UNIQUE": "NOT UNIQUE");
        if(res){
            end = target - 1;
        }
        else{
            start = target + 1;
        }
        target = (start + end) / 2;
        printf("NEXT: start: %d end: %d target: %d\n", start, end, target);
    }
}
