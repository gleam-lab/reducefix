#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long px = 0, py = 0; // Changed to long long to handle larger coordinates
    double ans = 0;
    long long x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += sqrt((x - px) * (x - px) + (y - py) * (y - py)); // Directly calculate Euclidean distance using integer arithmetic
        px = x; // Update previous position
        py = y; // Update previous position
    }
    
    ans += sqrt(px * px + py * py); // Add distance back to origin
    printf("%.10f\n", ans);
    return 0;
}