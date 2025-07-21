#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total cost of visiting all points in order and returning to the origin
    double total_cost = 0;
    for (size_t i = 1; i <= n; ++i) {
        total_cost += sqrt(pow(points[(i-1) % n].first - points[i % n].first, 2) +
                           pow(points[(i-1) % n].second - points[i % n].second, 2));
    }

    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}