#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<pair<long long, long long>> points(n);
    for (long long i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double total_cost = 0;
    for (long long i = 1; i < n; ++i) {
        long long dx = points[i].first - points[i - 1].first;
        long long dy = points[i].second - points[i - 1].second;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    // Return to the origin
    long long dx = points[0].first - points[n - 1].first;
    long long dy = points[0].second - points[n - 1].second;
    total_cost += sqrt(dx * dx + dy * dy);

    cout << total_cost << endl;

    return 0;
}