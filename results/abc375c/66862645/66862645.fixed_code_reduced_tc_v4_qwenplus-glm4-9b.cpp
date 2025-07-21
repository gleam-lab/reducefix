#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N + 1);

    points[0] = {0, 0};
    for (int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    long double total_cost = 0.0;
    for (int i = 1; i <= N; ++i) {
        total_cost += sqrt(pow(points[i].first - points[i - 1].first, 2) + pow(points[i].second - points[i - 1].second, 2));
    }
    total_cost += sqrt(pow(points[N].first - points[0].first, 2) + pow(points[N].second - points[0].second, 2));

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}