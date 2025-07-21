#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points;
    long long originX = 0, originY = 0;

    // Read all points including the origin
    points.push_back({originX, originY});
    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    points.push_back({originX, originY}); // Add origin at the end

    long long totalCost = 0;

    // Calculate the total cost between consecutive points
    for (int i = 1; i < points.size(); ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        totalCost += dx * dx + dy * dy;
    }

    // Output the total cost
    cout << totalCost << endl;

    return 0;
}