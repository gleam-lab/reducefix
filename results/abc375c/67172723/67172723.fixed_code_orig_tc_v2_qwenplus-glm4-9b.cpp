#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int px = 0, py = 0;
    double ans = 0.0;
    int x, y;

    // Calculate the distance from the origin to the first point
    cin >> x >> y;
    ans = hypot(x, y);
    
    // Calculate the distance between each consecutive pair of points
    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;
        py = y;
    }
    
    // Add the distance from the last point to the origin
    cin >> x >> y;
    ans += hypot(px, py);
    
    // Print the result with the required precision
    printf("%.10f\n", ans);
    return 0;
}