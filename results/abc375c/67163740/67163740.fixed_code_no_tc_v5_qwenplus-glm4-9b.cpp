#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

pair<ll, ll> read_point() {
    ll x, y;
    cin >> x >> y;
    return {x, y};
}

double calculate_distance(const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

void solve() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> points(N + 1);

    // Read all points including the origin point
    for (int i = 0; i <= N; ++i) {
        if (i == 0) {
            points[i] = {0, 0};
        } else {
            points[i] = read_point();
        }
    }

    double total_distance = 0.0;
    for (int i = 1; i <= N; ++i) {
        total_distance += calculate_distance(points[i - 1], points[i]);
    }

    cout << fixed << setprecision(6) << total_distance << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}