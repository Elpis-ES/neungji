#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        unordered_map<char, int> m;
        string s;
        cin >> s;
        for(auto c: s){
            auto t = m.find(c);
            if(t == m.end()){
                m[c] = 1;
            }
            else{
                t->second++;
            }
        }
        vector<int> v(10, 0);
        // ZERO
        if(m.find('Z') != m.end()){
            v[0] = m['Z'];
            m['E'] -= m['Z'];
            m['R'] -= m['Z'];
            m['O'] -= m['Z'];
            m['Z'] -= m['Z'];
        }
        // TWO
        if(m.find('W') != m.end()){
            v[2] = m['W'];
            m['T'] -= m['W'];
            m['O'] -= m['W'];
            m['W'] -= m['W'];
        }
        // FOUR
        if(m.find('U') != m.end()){
            v[4] = m['U'];
            m['F'] -= m['U'];
            m['O'] -= m['U'];
            m['R'] -= m['U'];
            m['U'] -= m['U'];
        }
        // SIX
        if(m.find('X') != m.end()){
            v[6] = m['X'];
            m['S'] -= m['X'];
            m['I'] -= m['X'];
            m['X'] -= m['X'];
        }
        // EIGHT
        if(m.find('G') != m.end()){
            v[8] = m['G'];
            m['E'] -= m['G'];
            m['I'] -= m['G'];
            m['H'] -= m['G'];
            m['T'] -= m['G'];
            m['G'] -= m['G'];
        }
        // ONE -> Filtered out ZERO, TWO, FOUR
        if(m.find('O') != m.end() && m['O'] != 0){
            v[1] = m['O'];
            m['N'] -= m['O'];
            m['E'] -= m['O'];
            m['O'] -= m['O'];
        }
        // THREE -> Filtered out ZERO, FOUR
        if(m.find('R') != m.end() && m['R'] != 0){
            v[3] = m['R'];
            m['T'] -= m['R'];
            m['H'] -= m['R'];
            m['E'] -= (m['R'] * 2);
            m['R'] -= m['R'];
        }
        // FIVE -> Filtered out FOUR
        if(m.find('F') != m.end() && m['F'] != 0){
            v[5] = m['F'];
            m['I'] -= m['F'];
            m['V'] -= m['F'];
            m['E'] -= m['F'];
            m['F'] -= m['F'];
        }
        // SEVEN -> Filtered out SIX
        if(m.find('S') != m.end() && m['S'] != 0){
            v[7] = m['S'];
            m['E'] -= (2 * m['S']);
            m['V'] -= m['S'];
            m['N'] -= m['S'];
            m['S'] -= m['S'];
        }
        // NINE -> Use left over
        if(m.find('I') != m.end() && m['I'] != 0){
            v[9] = m['I'];
        }
        cout << "Case #" << i << ": ";
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k < v[j]; k++){
                cout << j;
            }
        }
        cout << "\n";
    }

}
