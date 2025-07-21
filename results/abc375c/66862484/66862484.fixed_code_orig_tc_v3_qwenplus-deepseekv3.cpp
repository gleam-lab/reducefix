#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double total = 0.0;
    long long curX = 0, curY = 0;

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = x - curX;
        long long dy = y - curY;
        total += sqrt(dx * dx + dy * dy);

        curX = x;
        curY = y;
    }

    // Add the distance from the last point back to the origin
    total += sqrt(curX * curX + curY * curY);

    cout << fixed << setprecision(15) << total << '\n';
    return 0;
}