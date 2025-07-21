#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

double dist(long long x1, long long y1, long long x2, long long y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // Current position (origin)
    double total = 0;              // Total cost

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double d = dist(curX, curY, x, y);
        total += d;

        curX = x; curY = y;
    }

    // Return to origin
    double d = dist(curX, curY, 0, 0);
    total += d;

    cout << fixed << setprecision(10) << total << '\n';

    return 0;
}