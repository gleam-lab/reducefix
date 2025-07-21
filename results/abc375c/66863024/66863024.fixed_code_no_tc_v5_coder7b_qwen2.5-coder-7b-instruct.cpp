#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long double cost = 0;
    int N;
    cin >> N;

    vector<pair<long double, long double>> points(N + 1);
    points[0] = {0, 0}; // Starting point at the origin

    for(int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for(int i = 1; i <= N; ++i) {
        cost += sqrtl(pow(points[i].first - points[i - 1].first, 2) + pow(points[i].second - points[i - 1].second, 2));
    }

    cost += sqrtl(pow(points[N].first, 2) + pow(points[N].second, 2)); // Return to the origin

    cout.precision(10);
    cout << fixed << cost << '\n';

    return 0;
}