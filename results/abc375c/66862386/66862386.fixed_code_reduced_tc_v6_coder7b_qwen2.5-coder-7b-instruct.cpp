#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long double x = 0, y = 0, total_cost = 0;
    
    for(long long i = 0; i < n; ++i) {
        long long next_x, next_y;
        cin >> next_x >> next_y;
        
        // Calculate Euclidean distance and add it to the total cost
        total_cost += sqrt(pow(next_x - x, 2) + pow(next_y - y, 2));
        
        // Update current position
        x = next_x;
        y = next_y;
    }
    
    // Return to origin
    total_cost += sqrt(x * x + y * y);
    
    cout << total_cost << endl;
    
    return 0;
}