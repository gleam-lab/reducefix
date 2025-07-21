#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points;
    long long startX = 0, startY = 0; // Starting at the origin

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    long long totalCost = 0;
    // Calculate the cost between current point and the next point
    for (int i = 0; i < N; ++i) {
        totalCost += sqrt(pow(points[i].first - points[(i + 1) % N].first, 2) +
                           pow(points[i].second - points[(i + 1) % N].second, 2));
    }

    // Set precision and output the result
    cout << fixed << setprecision(9) << totalCost << '\n';

    return 0;
}