#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> psum_arr;
vector<vector<int>> dp_arr;
vector<int> dp_prev;
vector<int> dp_cur;

int cost(int i, int j){
    int ret = 0;
    for(int p = i; p < j; p++){
        ret += psum_arr[p][j];
    }
    return ret;
}

void compute(int l, int r, int optl, int optr){
    if(l > r)
        return;

    int mid = (l + r) >> 1;
    pair<int, int> best = {INT_MAX, -1};

    int cur_cost = INT_MIN;
    for(int i = min(mid, optr); i >= optl; i--){
        if(cur_cost == INT_MIN){
            cur_cost = cost(min(mid, optr), mid);
        }
        else{
            cur_cost += psum_arr[i][mid];
        }
        best = min(best, {(i ? dp_prev[i - 1] : 0) + cur_cost, i});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    psum_arr = vector<vector<int>> (N, vector<int> (N));
    dp_arr = vector<vector<int>> (N, vector<int> (N, INT_MIN));

    int tmp;
    for(int i = 0; i < N; i++){
        int psum = 0;
        for(int j = 0; j < N; j++){
            cin >> tmp;
            if(j > i){
                psum += tmp;
                psum_arr[i][j] = psum;
            }
            else if (j == i){
                dp_arr[i][j] = 0;
            }
        }
    }

    dp_prev = vector<int> (N);
    dp_cur = vector<int> (N);

    for(int i = 0; i < N; i++){
        dp_prev[i] = cost(0, i);
    }

    for(int i = 1; i < K; i++){
        compute(0, N - 1, 0, N - 1);
        dp_prev = dp_cur;
    }

    cout << dp_prev[N - 1] << "\n";
}
