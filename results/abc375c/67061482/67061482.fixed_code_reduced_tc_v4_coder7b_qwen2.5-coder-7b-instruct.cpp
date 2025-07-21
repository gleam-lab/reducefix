#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;
    
    // Set precision for output to handle large numbers accurately
    std::cout << std::fixed << std::setprecision(10);

    long long x = 0, y = 0;
    long long total_distance = 0;

    for (int i = 0; i < N; ++i) {
        long long new_x, new_y;
        std::cin >> new_x >> new_y;
        
        // Calculate Euclidean distance using integer arithmetic to avoid floating-point inaccuracies
        total_distance += static_cast<long long>(std::hypot(x - new_x, y - new_y));

        x = new_x;
        y = new_y;
    }

    // Add the distance back to the origin
    total_distance += static_cast<long long>(std::hypot(x, y));

    std::cout << total_distance << std::endl;

    return 0;
}