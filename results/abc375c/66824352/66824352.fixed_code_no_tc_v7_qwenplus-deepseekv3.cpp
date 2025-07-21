#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x = 0, y = 0; // Start at origin (0, 0)
    double total_cost = 0.0;
    
    for (int i = 0; i < n; ++i) {
        long long xi, yi;
        cin >> xi >> yi;
        long long dx = x - xi;
        long long dy = y - yi;
        total_cost += sqrt(dx * dx + dy * dy);
        x = xi;
        y = yi;
    }
    // Add the distance from the last point back to the origin
    total_cost += sqrt(x * x + y * y);
    
    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}