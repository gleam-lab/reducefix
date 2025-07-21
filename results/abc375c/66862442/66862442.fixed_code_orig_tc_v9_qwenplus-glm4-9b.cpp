#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;

    std::vector<double> x(N), y(N);
    double curX = 0.0, curY = 0.0;
    double total = 0.0;

    for (int i = 0; i < N; ++i) {
        std::cin >> x[i] >> y[i];
        double dist = std::sqrt((x[i] - curX) * (x[i] - curX) + (y[i] - curY) * (y[i] - curY));
        total += dist;

        curX = x[i];
        curY = y[i];
    }
    total += std::sqrt(curX * curX + curY * curY); // Go back to origin

    // Print with precision to meet requirements
    std::cout << std::fixed << std::setprecision(6) << total << std::endl;

    return 0;
}