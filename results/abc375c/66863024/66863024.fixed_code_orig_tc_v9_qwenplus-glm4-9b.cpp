#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N + 1); // +1 for the origin point

    // Reading the points
    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total distance
    double total_distance = 0.0;
    for (int i = 1; i <= N; ++i) {
        total_distance += sqrt(pow(points[i].first - points[i - 1].first, 2) + 
                               pow(points[i].second - points[i - 1].second, 2));
    }

    // Output the result
    cout.precision(10);
    cout << fixed << total_distance << endl;

    return 0;
}