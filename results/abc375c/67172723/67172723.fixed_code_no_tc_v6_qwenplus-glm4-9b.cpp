#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    long double px = 0, py = 0;
    long double ans = 0;
    long long x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += sqrt((px - x) * (px - x) + (py - y) * (py - y));
        px = x;
        py = y;
    }
    
    ans += sqrt(px * px + py * py);
    printf("%.10Lf\n", ans);
    
    return 0;
}