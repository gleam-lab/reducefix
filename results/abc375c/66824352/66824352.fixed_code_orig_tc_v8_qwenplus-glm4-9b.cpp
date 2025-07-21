#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long total_distance_squared = 0;
    long long x = 0, y = 0;
    
    for (int i = 0; i < n; i++) {
        int x1, y1;
        cin >> x1 >> y1;
        total_distance_squared += (x1 * x1 - x * x) + (y1 * y1 - y * y);
        x = x1;
        y = y1;
    }
    
    // Calculate the final distance back to the origin
    total_distance_squared += (x * x - x * x) + (y * y - y * y);
    
    // Output the square root of the total distance squared
    cout << sqrt(total_distance_squared) << endl;
    
    return 0;
}