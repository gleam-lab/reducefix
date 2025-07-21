#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double total_distance = 0.0;
    int prev_x = 0, prev_y = 0;
    
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        total_distance += hypot(x - prev_x, y - prev_y);
        prev_x = x;
        prev_y = y;
    }
    
    // Add the distance from the last point back to the origin
    total_distance += hypot(prev_x, prev_y);
    
    printf("%.10f\n", total_distance);
    return 0;
}