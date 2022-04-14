#include <bits/stdc++.h>

using namespace std;

int calc(int cur, int val, char op){
    int ret;
    switch(op){
        case '+':
            ret = cur + val;
            break;
        case '-':
            ret = cur - val;
            break;
        case '/':
            ret = cur / val;
            break;
        case '*':
            ret = cur * val;
            break;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int max_arr[2];
    max_arr[0] = 1;
    max_arr[1] = 1;

    for(int i = 0; i < n; i++){
        string s, t;
        cin >> s >> t;

        if(i != 0){
            if(max_arr[0] <= 0){
                max_arr[1] = max(calc(max_arr[1], (int)(s[1] - '0'), s[0]), calc(max_arr[1], (int)(t[1] - '0'), t[0]));
                if(max_arr[1] <= 0){
                    max_arr[1] = -1;
                    break;
                }
            }
            else{
                int noskip_max = max(calc(max_arr[0], (int)(s[1] - '0'), s[0]), calc(max_arr[0], (int)(t[1] - '0'), t[0]));
                int skip_max = max(calc(max_arr[1], (int)(s[1] - '0'), s[0]), calc(max_arr[1], (int)(t[1] - '0'), t[0]));
                if(skip_max < max_arr[0]){
                    skip_max = max_arr[0];
                }
                if(noskip_max <= 0){
                    noskip_max = -1;
                }
                if(skip_max <= 0){
                    skip_max = -1;
                }
                max_arr[0] = noskip_max;
                max_arr[1] = skip_max;
            }
        }
        else{
            max_arr[0] = max(calc(max_arr[0], (int)(s[1] - '0'), s[0]), calc(max_arr[0], (int)(t[1] - '0'), t[0]));
            if(max_arr[0] <= 0){
                max_arr[0] = -1;
            }
        }
    }

    int ret = max(max_arr[0], max_arr[1]);
    if (ret <= 0){
        cout << "ddong game\n";
    }
    else{
        cout << ret << "\n";
    }

}
