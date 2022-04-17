#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ordered_set o_set;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        o_set.insert(tmp);
        cout << *(o_set.find_by_order(n >> 1) << "\n";
    }
}
