#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    // Variables to store the current position
    double x = 0, y = 0;
    double total_cost = 0;
    
    // Read the coordinates of each point and calculate the cost to move to the next point
    for (int i = 0; i < N; ++i) {
        int next_x, next_y;
        cin >> next_x >> next_y;
        
        // Calculate the Euclidean distance to the next point
        double dx = next_x - x;
        double dy = next_y - y;
        double distance = sqrt(dx * dx + dy * dy);
        
        // Add the distance to the total cost
        total_cost += distance;
        
        // Update the current position
        x = next_x;
        y = next_y;
    }
    
    // Calculate the distance back to the origin
    total_cost += sqrt(x * x + y * y);
    
    // Print the total cost
    printf("%.10f\n", total_cost);
    
    return 0;
}