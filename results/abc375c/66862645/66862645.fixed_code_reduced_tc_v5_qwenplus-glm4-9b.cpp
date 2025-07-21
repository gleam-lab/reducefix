#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // For std::setprecision

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);

    // Read the points from the input
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Starting at the origin (0, 0)
    long long currentX = 0, currentY = 0;
    double totalCost = 0.0;

    // Calculate the total cost from the origin to each point and back to the origin
    for (const auto &point : points) {
        totalCost += sqrt(pow(currentX - point.first, 2) + pow(currentY - point.second, 2));
        totalCost += sqrt(pow(point.first - 0, 2) + pow(point.second - 0, 2));
        // Update the current position to the point we just visited
        currentX = point.first;
        currentY = point.second;
    }

    // Print the total cost with a precision of 10 decimal places
    cout << fixed << setprecision(10) << totalCost << endl;

    return 0;
}