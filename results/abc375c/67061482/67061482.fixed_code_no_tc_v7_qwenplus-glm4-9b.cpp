#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    // Initialize starting point
    double ax = 0, ay = 0;
    
    // Accumulate the total cost
    double totalCost = 0.0;
    
    for (int i = 0; i < N; ++i) {
        int cx, cy;
        cin >> cx >> cy;
        
        // Calculate the distance from the current point to the new point
        totalCost += sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
        
        // Update the current position
        ax = cx;
        ay = cy;
    }
    
    // Add the distance from the last point to the origin
    totalCost += sqrt(pow(ax, 2) + pow(ay, 2));
    
    // Output the total cost
    cout << totalCost << endl;
    
    return 0;
}