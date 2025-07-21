#include <bits/stdc++.h>
using namespace std;

int main() {
    double x, y, nx, ny, dist;
    int N;
    cin >> N;
    x = 0;
    y = 0;
    dist = 0;
    for(int i = 0; i < N; i++) {
        cin >> nx >> ny;
        dist += sqrt((x-nx)*(x-nx) + (y-ny)*(y-ny));
        x = nx;
        y = ny;
    }
    dist += sqrt(x*x + y*y);
    cout << fixed << setprecision(10) << dist << endl;
}