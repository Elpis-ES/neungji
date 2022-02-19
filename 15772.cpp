#include <bits/stdc++.h>

using namespace std;

vector<int> r;
vector<int> f;
unordered_map<string, pair<int, int> > m;

void get_status(int cur_r, int cur_f){
    if(cur_r <= r[0]){
        if(cur_f <= f[0]){
            cout << "New Customer\n";
        }
        else if(cur_f <= f[2]){
            cout << "Potential Loyalist\n";
        }
        else if(cur_f <= f[3]){
            cout << "Loyal Customer\n";
        }
        else{
            cout << "Champion\n";
        }
    }
    else if(cur_r <= r[1]){
        if(cur_f <= f[0]){
            cout << "Promising\n";
        }
        else if(cur_f <= f[2]){
            cout << "Potential Loyalist\n";
        }
        else{
            cout << "Loyal Customer\n";
        }
    }
    else if(cur_r <= r[2]){
        if(cur_f <= f[1]){
            cout << "About to Sleep\n";
        }
        else if(cur_f <= f[2]){
            cout << "Need Attention\n";
        }
        else{
            cout << "Loyal Customer\n";
        }
    }
    else if(cur_r <= r[3]){
        if(cur_f <= f[0]){
            cout << "Lost\n";
        }
        else if(cur_f <= f[1]){
            cout << "Hibernating\n";
        }
        else{
            cout << "About to Leave\n";
        }
    }
    else{
        if(cur_f <= f[1]){
            cout << "Lost\n";
        }
        else if(cur_f <= f[3]){
            cout << "About to Leave\n";
        }
        else{
            cout << "Can't Lose Them\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tmp, n, num;
    string s;

    for(int i = 0; i < 4; i++){
        cin >> tmp;
        r.push_back(tmp);
    }

    for(int i = 0; i < 4; i++){
        cin >> tmp;
        f.push_back(tmp);
    }

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num >> s;
        if(num == 1){
            if(m.count(s)){
                m[s].second++;
                m[s].first = i;
            }
            else{
                m[s] = make_pair(i, 1);
            }
        }
        else{
            if(m.count(s)){
                get_status(i - m[s].first, m[s].second);
            }
            else{
                cout << "None\n";
            }
        }

    }

}

