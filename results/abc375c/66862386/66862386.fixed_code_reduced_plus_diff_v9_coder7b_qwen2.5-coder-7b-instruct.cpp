#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n);
    std::vector<int> y(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    long double total_cost = 0;

    // Calculate the distance between consecutive points and back to the origin
    for (int i = 0; i < n; ++i) {
        int dx = x[i] - (i == 0 ? 0 : x[i - 1]);
        int dy = y[i] - (i == 0 ? 0 : y[i - 1]);
        total_cost += sqrt(dx * dx + dy * dy);
    }

    // Add the distance from the last point back to the origin
    int dx_last = x[n - 1];
    int dy_last = y[n - 1];
    total_cost += sqrt(dx_last * dx_last + dy_last * dy_last);

    std::cout << total_cost << std::endl;

    return 0;
}