#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double total_cost = 0;
    for (int i = 1; i <= N; ++i) {
        int x1 = i == 1 ? 0 : points[i - 2].first;
        int y1 = i == 1 ? 0 : points[i - 2].second;
        int x2 = points[i - 1].first;
        int y2 = points[i - 1].second;

        long double dx = x2 - x1;
        long double dy = y2 - y1;
        total_cost += sqrt(dx * dx + dy * dy);
    }

    cout << fixed << setprecision(12) << total_cost << endl;

    return 0;
}