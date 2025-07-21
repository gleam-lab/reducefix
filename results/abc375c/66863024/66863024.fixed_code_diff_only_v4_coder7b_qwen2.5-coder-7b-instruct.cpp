#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    double total_cost = 0;
    double current_x = 0, current_y = 0;

    for(int i = 0; i < N; ++i) {
        double next_x, next_y;
        std::cin >> next_x >> next_y;

        // Calculate the Euclidean distance to the next point
        double distance = std::sqrt(std::pow(current_x - next_x, 2) + std::pow(current_y - next_y, 2));
        total_cost += distance;

        // Update the current position
        current_x = next_x;
        current_y = next_y;
    }

    // Return to the origin
    double final_distance = std::sqrt(std::pow(current_x, 2) + std::pow(current_y, 2));
    total_cost += final_distance;

    std::cout << total_cost << std::endl;

    return 0;
}