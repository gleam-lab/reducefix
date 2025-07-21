#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    int prevX = 0, prevY = 0;
    int currX, currY;

    for (int i = 0; i < N; ++i) {
        cin >> currX >> currY;
        long double dx = static_cast<long double>(prevX - currX);
        long double dy = static_cast<long double>(prevY - currY);
        total += sqrt(dx * dx + dy * dy);
        prevX = currX;
        prevY = currY;
    }

    // Return to origin
    long double dx = static_cast<long double>(prevX);
    long double dy = static_cast<long double>(prevY);
    total += sqrt(dx * dx + dy * dy);

    // Print with sufficient precision
    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}