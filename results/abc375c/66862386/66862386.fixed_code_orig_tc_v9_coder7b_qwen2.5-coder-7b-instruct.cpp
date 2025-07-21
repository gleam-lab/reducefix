#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long x = 0, y = 0;
    double totalCost = 0.0;
    
    while(n--) {
        long long nx, ny;
        cin >> nx >> ny;
        
        // Calculate Euclidean distance between current point and next point
        double dx = static_cast<double>(nx - x);
        double dy = static_cast<double>(ny - y);
        double dist = sqrt(dx * dx + dy * dy);
        
        totalCost += dist;
        
        // Update current position
        x = nx;
        y = ny;
    }
    
    // Add the distance back to the origin
    double distToOrigin = sqrt(x * x + y * y);
    totalCost += distToOrigin;
    
    cout.precision(15);
    cout << totalCost << endl;
    
    return 0;
}