#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double ax, ay, bx, by, cx, cy, dx, dy;

    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    double ax_diff = bx - ax;
    double ay_diff = by - ay;

    double bx_diff = dx - cx;
    double by_diff = dy - cy;

    double l = 0;
    double r = 1;

    double dist_ll, dist_rr;

    for(int i = 0; i < 100; i++){
        double ll = l + (r - l) / 3.0;
        double rr = l + ((r - l) / 3.0 * 2.0);

        double cur_ax_ll = ax + ax_diff * ll;
        double cur_ay_ll = ay + ay_diff * ll;
        double cur_bx_ll = cx + bx_diff * ll;
        double cur_by_ll = cy + by_diff * ll;

        double cur_ax_rr = ax + ax_diff * rr;
        double cur_ay_rr = ay + ay_diff * rr;
        double cur_bx_rr = cx + bx_diff * rr;
        double cur_by_rr = cy + by_diff * rr;

        dist_ll = sqrt((cur_bx_ll - cur_ax_ll) * (cur_bx_ll - cur_ax_ll) + (cur_by_ll - cur_ay_ll) * (cur_by_ll - cur_ay_ll));
        dist_rr = sqrt((cur_bx_rr - cur_ax_rr) * (cur_bx_rr - cur_ax_rr) + (cur_by_rr - cur_ay_rr) * (cur_by_rr - cur_ay_rr));
        if(dist_ll < dist_rr){
            r = rr;
        }
        else{
            l = ll;
        }
    }
    cout.precision(9);
    cout << fixed << dist_ll << "\n";
}
