#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total distance
    double total_distance = 0;
    for (size_t i = 0; i < N - 1; ++i) {
        total_distance += hypot(points[i].first - points[i + 1].first, points[i].second - points[i + 1].second);
    }
    
    // Add the distance back to the origin
    total_distance += hypot(points[N - 1].first, points[N - 1].second);

    cout.precision(15);
    cout << total_distance << '\n';

    return 0;
}