#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N + 1);
    points[0] = {0, 0};
    long long total_cost = 0;

    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 1; i <= N; ++i) {
        total_cost += sqrt(pow(points[i].first - points[i - 1].first, 2) +
                           pow(points[i].second - points[i - 1].second, 2));
    }

    // The last segment is from the last point back to the origin
    total_cost += sqrt(pow(points[N].first - 0, 2) +
                       pow(points[N].second - 0, 2));

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}