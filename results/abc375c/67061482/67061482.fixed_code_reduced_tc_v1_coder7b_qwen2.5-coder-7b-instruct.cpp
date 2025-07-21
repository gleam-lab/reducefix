#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total cost
    double total_cost = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        total_cost += sqrt(points[i].first * points[i].first + points[i].second * points[i].second);
        if (i > 0) {
            total_cost += sqrt(pow(points[i].first - points[i - 1].first, 2) +
                               pow(points[i].second - points[i - 1].second, 2));
        }
    }
    total_cost += sqrt(points[0].first * points[0].first + points[0].second * points[0].second);

    cout.precision(10);
    cout << total_cost << endl;

    return 0;
}