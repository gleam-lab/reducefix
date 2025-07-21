#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long px = 0, py = 0;
    double ans = 0;
    long long x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += sqrt((double)(x - px) * (x - px) + (double)(y - py) * (y - py));
        px = x;
        py = y;
    }
    
    ans += sqrt((double)(x - 0) * (x - 0) + (double)(y - 0) * (y - 0));
    printf("%.10f\n", ans);
    return 0;
}