#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    int currentX = 0, currentY = 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        long double dx = static_cast<long double>(x - currentX);
        long double dy = static_cast<long double>(y - currentY);
        total += sqrt(dx * dx + dy * dy);

        currentX = x;
        currentY = y;
    }

    // Return to origin
    long double dx = static_cast<long double>(0 - currentX);
    long double dy = static_cast<long double>(0 - currentY);
    total += sqrt(dx * dx + dy * dy);

    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}