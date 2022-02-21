#include <bits/stdc++.h>

using namespace std;
bool chosen[3];
vector<pair<int, int> > w, c, b, j;
pair<int, int> h;
pair<int, int> e;
int min_len = INT_MAX;
char min_job;


void get_min(int i, char topping, int prev, int cur, int len){
    vector<pair<int, int> > target;
    switch(topping){
        case 'W':
            target = w;
            break;
        case 'C':
            target = c;
            break;
        case 'B':
            target = b;
            break;
        case 'J':
            target = j;
            break;
    }
    int cur_len;
    chosen[cur] = true;
    if(i == 2){
         cur_len = len + abs(target[cur].first - e.first) + abs(target[cur].second - e.second);
         cur_len += abs(target[cur].first - target[prev].first) + abs(target[cur].second - target[prev].second);
         if(cur_len < min_len){
             min_job = topping;
             min_len = cur_len;
         }
         chosen[cur] = false;
         return;
    }
    else if(i == 0){
        cur_len = abs(target[cur].first - h.first) + abs(target[cur].second - h.second);
    }
    else{
        cur_len = abs(target[cur].first - target[prev].first) + abs(target[cur].second - target[prev].second);
    }

    for(int n = 0; n < 3; n++){
        if(!chosen[n]){
            get_min(i+1, topping, cur, n, cur_len + len);
        }
    }
    chosen[cur] = false;
}


int main(){
    int n;
    char tmp;
    scanf(" %d", &n);
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            scanf(" %c" , &tmp);
            switch(tmp){
                case 'H':
                    h.first = x;
                    h.second = y;
                    break;
                case 'W':
                    w.push_back(make_pair(x, y));
                    break;
                case 'C':
                    c.push_back(make_pair(x, y));
                    break;
                case 'B':
                    b.push_back(make_pair(x, y));
                    break;
                case 'J':
                    j.push_back(make_pair(x, y));
                    break;
                case '#':
                    e.first = x;
                    e.second = y;
                    break;
                default:
                    break;
            }
        }
    }
    int min_len = INT_MAX;
    int cur;
    for(int i = 0; i < 3; i++){
        get_min(0, 'J', -1, i, 0);
        get_min(0, 'C', -1, i, 0);
        get_min(0, 'B', -1, i, 0);
        get_min(0, 'W', -1, i, 0);
    }
    switch(min_job){
        case 'J':
            printf("Assassin\n");
            break;
        case 'W':
            printf("Tanker\n");
            break;
        case 'C':
            printf("Healer\n");
            break;
        case 'B':
            printf("Mage\n");
            break;
    }
}
