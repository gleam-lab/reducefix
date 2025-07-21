#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Initialize the current position at the origin
    long long x = 0, y = 0;
    long long total_distance = 0;
    
    for (int i = 0; i < n; ++i) {
        int x1, y1;
        cin >> x1 >> y1;
        
        // Calculate the distance from the current position to the new point
        long long current_distance = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
        
        // Update total distance with the new segment
        total_distance += sqrt(current_distance);
        
        // Update current position to the new point
        x = x1;
        y = y1;
    }
    
    // Add the distance back to the origin
    long long final_distance = sqrt((x * x) + (y * y));
    total_distance += sqrt(final_distance);
    
    // Print the total distance
    cout << fixed << setprecision(10) << total_distance << endl;
    
    return 0;
}