#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> pts;
vector<vector<int> > r;
int mafia;

int day(int t);
int night(int t);

int day(int t){
    int ret, tmp;
    int target = max_element(pts.begin(), pts.end()) - pts.begin();
    if(target == mafia){
        return t;
    }
    else{
        tmp = pts[target];
        pts[target] = 0;
        ret = night(t);
        pts[target] = tmp;
    }
    return ret;
}

int night(int t){
    int tmp, tmp_ret;
    int ret = -1;
    bool target_found = false;
    for(int target = 0; target < n; target++){
        if(target == mafia){
            continue;
        }
        else if(pts[target] != 0){
            if(!target_found){
                target_found = true;
            }
            tmp = pts[target];
            pts[target] = 0;
            for(int i = 0; i < n; i++){
                if(pts[i] != 0){
                    pts[i] += r[target][i];
                }
            }
            tmp_ret = day(t+1);
            ret = max(ret, tmp_ret);
            for(int i = 0; i < n; i++){
                if(pts[i] != 0){
                    pts[i] -= r[target][i];
                }
            }
            pts[target] = tmp;
        }
    }
    if(!target_found){
        return t;
    }
    return ret;
}

int main(){
    scanf(" %d", &n);
    int tmp;
    for(int i = 0; i < n; i++){
        scanf(" %d", &tmp);
        pts.push_back(tmp);
    }
    vector<int> v;
    for(int i = 0; i < n; i++){
        v = vector<int> ();
        for(int j = 0; j < n; j++){
            scanf(" %d", &tmp);
            v.push_back(tmp);
        }
        r.push_back(v);
    }
    scanf(" %d", &mafia);
    if(n%2 == 0){
        printf("%d\n", night(0));
    }
    else{
        printf("%d\n", day(0));
    }

}
