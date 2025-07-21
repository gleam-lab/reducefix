#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long double total = 0.0;
    int currX = 0, currY = 0;
    int nextX, nextY;

    for (int i = 0; i < n; ++i) {
        cin >> nextX >> nextY;
        long long dx = static_cast<long long>(currX - nextX);
        long long dy = static_cast<long long>(currY - nextY);
        total += sqrtl(dx * dx + dy * dy);
        currX = nextX;
        currY = nextY;
    }

    // Return to origin
    long long dx = static_cast<long long>(currX);
    long long dy = static_cast<long long>(currY);
    total += sqrtl(dx * dx + dy * dy);

    cout << fixed << setprecision(10) << total << endl;

    return 0;
}