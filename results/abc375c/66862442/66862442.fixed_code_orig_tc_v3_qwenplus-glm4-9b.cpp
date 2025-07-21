#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N + 1); // +1 for the origin

    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0.0;
    long long x = 0, y = 0;

    for (int i = 0; i <= N; ++i) {
        long long px = points[i].first;
        long long py = points[i].second;

        total_distance += sqrt((px - x) * (px - x) + (py - y) * (py - y));
        x = px;
        y = py;
    }

    cout.precision(8); // Set precision for double output
    cout << fixed << total_distance << endl;

    return 0;
}