#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long x = 0, y = 0;
    double cost = 0.0;
    
    for (int i = 0; i < n; ++i) {
        long long newX, newY;
        cin >> newX >> newY;
        long long dx = x - newX;
        long long dy = y - newY;
        cost += sqrt(static_cast<double>(dx * dx + dy * dy));
        x = newX;
        y = newY;
    }
    
    // Return to origin
    cost += sqrt(static_cast<double>(x * x + y * y));
    
    cout << fixed << setprecision(15) << cost << endl;
    return 0;
}