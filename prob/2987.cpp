#include <bits/stdc++.h>

using namespace std;

#define X(i) (i*2)
#define Y(i) (i*2+1)

double triangle[6];

double ccw(double x1, double y1, double x2, double y2, double x3, double y3){
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}
int main(){
    double x, y;
    for(int i = 0; i < 3; i++){
        scanf(" %lf %lf", &x, &y);
        triangle[X(i)] = x;
        triangle[Y(i)] = y;
    }
    printf("%.1lf\n", fabs(triangle[X(0)]*(triangle[Y(1)] - triangle[Y(2)]) + triangle[X(1)]*(triangle[Y(2)] - triangle[Y(0)]) + triangle[X(2)] * (triangle[Y(0)] - triangle[Y(1)])) / 2);
    int n;
    int cnt = 0;
    double sum_angle;
    scanf(" %d", &n);
    double a, b, c;
    for(int i = 0; i < n; i++){
        scanf(" %lf %lf", &x, &y);
        a = ccw(triangle[X(0)], triangle[Y(0)], triangle[X(1)], triangle[Y(1)], x, y);
        b = ccw(triangle[X(1)], triangle[Y(1)], triangle[X(2)], triangle[Y(2)], x, y);
        c = ccw(triangle[X(2)], triangle[Y(2)], triangle[X(0)], triangle[Y(0)], x, y);
        if((a>=0 && b>=0 && c>=0) || (a <= 0 && b <=0 && c<=0)){
            cnt++;
        }

    }
    printf("%d\n", cnt);

}
