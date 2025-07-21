#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double distance(const pair<int, int>& p1, const pair<int, int>& p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0;
    // Start at origin (0, 0)
    pair<int, int> current_point = {0, 0};
    for (const auto& next_point : points) {
        total_distance += distance(current_point, next_point);
        current_point = next_point;
    }
    // Return to origin after visiting all points
    total_distance += distance(current_point, {0, 0});

    cout << total_distance << endl;
    return 0;
}