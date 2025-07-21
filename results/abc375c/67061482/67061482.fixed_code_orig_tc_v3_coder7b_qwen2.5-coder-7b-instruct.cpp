#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    long long n;
    std::cin >> n;
    
    double x = 0, y = 0, total_cost = 0;

    for(long long i = 0; i < n; ++i) {
        long long xi, yi;
        std::cin >> xi >> yi;
        
        total_cost += std::hypot(xi - x, yi - y);
        x = xi;
        y = yi;
    }

    // Return to origin
    total_cost += std::hypot(x, y);

    // Set precision for large numbers
    std::cout << std::fixed << std::setprecision(15) << total_cost << std::endl;
    return 0;
}