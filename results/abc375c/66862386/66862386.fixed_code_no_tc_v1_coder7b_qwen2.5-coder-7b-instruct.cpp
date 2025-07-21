#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    // Initialize the starting position at the origin
    double startX = 0.0, startY = 0.0;
    double totalCost = 0.0;

    // Process each point
    for (int i = 0; i < N; ++i) {
        double nextX, nextY;
        std::cin >> nextX >> nextY;

        // Calculate the Euclidean distance to the next point
        double dx = nextX - startX;
        double dy = nextY - startY;
        double currentCost = std::sqrt(dx * dx + dy * dy);

        // Add the cost to the total
        totalCost += currentCost;

        // Update the current position
        startX = nextX;
        startY = nextY;
    }

    // Calculate the cost to return to the origin
    double finalCost = std::sqrt(startX * startX + startY * startY);
    totalCost += finalCost;

    // Output the total cost
    std::cout << totalCost << std::endl;

    return 0;
}