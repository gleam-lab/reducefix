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
        double dx = x - prev_x;
        double dy = y - prev_y;
        total_distance += sqrt(dx * dx + dy * dy);
        prev_x = x;
        prev_y = y;
    }
    
    // Add the distance from the last point back to the origin
    double dx = -prev_x;
    double dy = -prev_y;
    total_distance += sqrt(dx * dx + dy * dy);
    
    printf("%.15f\n", total_distance);
    return 0;
}