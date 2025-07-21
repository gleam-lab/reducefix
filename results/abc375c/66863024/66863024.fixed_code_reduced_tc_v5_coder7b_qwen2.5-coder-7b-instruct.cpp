#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> points(n + 1);
    points[0] = {0, 0};

    for (int i = 1; i <= n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double total_cost = 0;

    for (int i = 0; i <= n; ++i) {
        total_cost += sqrtl((points[i].first - points[(i + 1) % (n + 1)].first) * 
                            (points[i].first - points[(i + 1) % (n + 1)].first) +
                             (points[i].second - points[(i + 1) % (n + 1)].second) * 
                             (points[i].second - points[(i + 1) % (n + 1)].second));
    }

    cout.precision(10);
    cout << fixed << total_cost << '\n';

    return 0;
}