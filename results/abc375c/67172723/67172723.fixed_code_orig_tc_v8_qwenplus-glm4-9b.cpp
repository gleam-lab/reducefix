#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int px = 0, py = 0;  // Starting point (origin)
    double ans = 0;
    
    // Loop through all points except the last one
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        ans += hypot(x - px, y - py);
        px = x;  // Update last x coordinate
        py = y;  // Update last y coordinate
    }
    
    // Add the distance from the last point back to the origin
    int x, y;
    cin >> x >> y;
    ans += hypot(x - px, y - py);
    
    // Output the total distance
    printf("%.10f\n", ans);
    return 0;
}