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

        long double dx = static_cast<long double>(nextX - currX);
        long double dy = static_cast<long double>(nextY - currY);
        total += sqrt(dx * dx + dy * dy);

        currX = nextX;
        currY = nextY;
    }

    // Return to origin
    long double dx = static_cast<long double>(0 - currX);
    long double dy = static_cast<long double>(0 - currY);
    total += sqrt(dx * dx + dy * dy);

    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}