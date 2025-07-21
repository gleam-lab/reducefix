#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long x = 0, y = 0;
    double total_cost = 0.0;
    
    for (int i = 0; i < n; ++i) {
        long long x2, y2;
        cin >> x2 >> y2;
        long long dx = x - x2;
        long long dy = y - y2;
        total_cost += sqrt(static_cast<double>(dx * dx + dy * dy));
        x = x2;
        y = y2;
    }
    
    // Return to origin
    total_cost += sqrt(static_cast<double>(x * x + y * y));
    
    cout << fixed << setprecision(15) << total_cost << endl;
    return 0;
}