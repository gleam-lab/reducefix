#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> points(N + 1); // +1 for the return to the origin
    int curX = 0, curY = 0;

    for (int i = 0; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total = 0.0; // Use double for precision

    for (int i = 1; i <= N; ++i) {
        double dx = points[i].first - curX;
        double dy = points[i].second - curY;
        total += sqrt(dx * dx + dy * dy); // Calculate the distance and add to the total cost

        curX = points[i].first;
        curY = points[i].second;
    }

    cout.precision(10); // Set precision for output
    cout << fixed << total << endl; // Output the total cost with fixed precision

    return 0;
}