#include <iostream>
#include <cmath>

int main() {
    // Declare variables with appropriate types
    double a = 0.0, b = 0.0, c, d, cou = 0.0;
    int N;

    // Read number of points
    std::cin >> N;

    // Loop through each point and calculate distance
    for(int i = 0; i < N; i++) {
        std::cin >> c >> d;
        cou += std::sqrt(std::pow(a - c, 2) + std::pow(b - d, 2));
        a = c;
        b = d;
    }

    // Add distance back to origin
    cou += std::sqrt(a * a + b * b);

    // Print the result
    std::cout << cou << std::endl;

    return 0;
}