#include <iostream>
#include <cmath> // Include cmath for sqrt function
using namespace std;

int main() {
    int N;
    cin >> N;
    
    long double cost = 0.0; // Use long double for higher precision
    long double currentX = 0.0, currentY = 0.0;
    
    for (int i = 0; i < N; i++) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        
        // Calculate the cost from current position to the next point
        long double dx = nextX - currentX;
        long double dy = nextY - currentY;
        cost += sqrt(dx * dx + dy * dy);
        
        // Update current position
        currentX = nextX;
        currentY = nextY;
    }
    
    // Calculate the cost from the last point back to the origin
    long double dx = 0 - currentX;
    long double dy = 0 - currentY;
    cost += sqrt(dx * dx + dy * dy);
    
    // Output the total cost
    cout << fixed << setprecision(10) << cost << endl;
    
    return 0;
}