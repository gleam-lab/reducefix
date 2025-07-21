#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    int currX = 0, currY = 0;

    for (int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        int dx = currX - nextX;
        int dy = currY - nextY;
        total += sqrtl(static_cast<long double>(dx * dx + dy * dy));
        currX = nextX;
        currY = nextY;
    }

    // Return to origin
    int dx = currX;
    int dy = currY;
    total += sqrtl(static_cast<long double>(dx * dx + dy * dy));

    cout.precision(15);
    cout << fixed << total << '\n';

    return 0;
}