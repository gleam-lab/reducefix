#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x = 0, y = 0; // Using long long to prevent overflow during squaring
    double total_distance = 0.0;
    
    for (int i = 0; i < n; ++i) {
        long long xi, yi;
        cin >> xi >> yi;
        long long dx = x - xi;
        long long dy = y - yi;
        total_distance += sqrt(dx * dx + dy * dy);
        x = xi;
        y = yi;
    }
    // Add the distance from the last point back to the origin
    total_distance += sqrt(x * x + y * y);
    
    // Set precision to 10 decimal places to meet the problem's requirements
    cout << fixed << setprecision(10) << total_distance << endl;
    
    return 0;
}