#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> points(N + 1);
    points[0] = {0, 0}; // Starting from the origin

    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0.0;

    for (int i = 1; i <= N; ++i) {
        int x1 = points[i - 1].first;
        int y1 = points[i - 1].second;
        int x2 = points[i].first;
        int y2 = points[i].second;

        total_cost += sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}