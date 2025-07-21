#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    
    // To store the current position
    double x = 0, y = 0;
    
    // Initialize the total distance with the distance from origin to the first point
    double total_distance = 0;
    std::cin >> x >> y;
    total_distance += std::sqrt(x*x + y*y);
    
    // Process each subsequent point
    for(int i = 1; i < n; ++i) {
        double next_x, next_y;
        std::cin >> next_x >> next_y;
        
        // Calculate the Euclidean distance to the next point
        double dx = next_x - x;
        double dy = next_y - y;
        total_distance += std::sqrt(dx*dx + dy*dy);
        
        // Update the current position
        x = next_x;
        y = next_y;
    }
    
    // Add the distance from the last point back to the origin
    total_distance += std::sqrt(x*x + y*y);
    
    // Output the total distance with high precision
    std::cout << std::fixed << std::setprecision(10) << total_distance << std::endl;
    
    return 0;
}