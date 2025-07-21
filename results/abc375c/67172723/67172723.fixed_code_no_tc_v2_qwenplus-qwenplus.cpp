#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long px = 0, py = 0;
    double total = 0.0;

    vector<pair<long long, long long>> points(n);
    for (auto& [x, y] : points) {
        cin >> x >> y;
        total += hypot(x - px, y - py);
        px = x;
        py = y;
    }

    // Return to origin
    total += hypot(px, py);

    cout.precision(15);
    cout << fixed << total << '\n';

    return 0;
}