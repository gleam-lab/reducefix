#include <bits/stdc++.h>
using namespace std;

int main() {
    long double ans = 0;
    int n;
    cin >> n;
    
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        
        // Add the distance from the origin to the current point and back to the origin.
        ans += sqrt(x * x + y * y);
        
        // If there are still more points to process, add the distance to the next point.
        if (i + 1 < n) {
            int nx, ny;
            cin >> nx >> ny;
            ans += sqrt((nx - x) * (nx - x) + (ny - y) * (ny - y));
        }
    }
    
    cout << fixed << setprecision(10) << ans << endl; // Print the answer with precision
    return 0;
}