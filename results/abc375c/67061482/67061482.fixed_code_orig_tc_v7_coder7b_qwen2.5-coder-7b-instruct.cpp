#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    // Initialize variables to store the current position and the total distance
    double x = 0, y = 0;
    double total_distance = 0;

    // Read each point and calculate the distance from the previous point
    for (int i = 0; i < N; ++i) {
        double cx, cy;
        std::cin >> cx >> cy;
        
        // Calculate the distance from the current point to the previous one
        double dx = cx - x;
        double dy = cy - y;
        total_distance += std::sqrt(dx * dx + dy * dy);

        // Update the current position
        x = cx;
        y = cy;
    }

    // Add the distance from the last point back to the origin
    total_distance += std::sqrt(x * x + y * y);

    // Output the total distance with high precision
    std::cout << std::fixed << std::setprecision(15) << total_distance << std::endl;

    return 0;
}