#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> points(N + 1);

    // Read points and include the origin (0, 0) at the end
    for (int i = 0; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;
    // Calculate the total cost of moving from the origin to each point and then returning to the origin
    for (int i = 0; i <= N; ++i) {
        double dx = points[i].first - points[(i + 1) % (N + 1)].first;
        double dy = points[i].second - points[(i + 1) % (N + 1)].second;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    // Set precision to 10 decimal places and print the result
    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}