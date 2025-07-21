#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long px = 0, py = 0;
    double ans = 0;
    int x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += hypotl(x - px, y - py);
        px = x, py = y;
    }
    
    ans += hypotl(px, py); // Add the distance back to the origin after all points are visited
    printf("%.10f\n", ans);
    return 0;
}