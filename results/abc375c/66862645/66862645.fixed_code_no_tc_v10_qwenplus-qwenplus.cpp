#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    long double total = 0.0;
    int currX = 0, currY = 0;

    for (int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;

        int dx = nextX - currX;
        int dy = nextY - currY;
        total += sqrtl(static_cast<long double>(dx * dx + dy * dy));

        currX = nextX;
        currY = nextY;
    }

    // Return to origin
    int dx = 0 - currX;
    int dy = 0 - currY;
    total += sqrtl(static_cast<long double>(dx * dx + dy * dy));

    cout << fixed << setprecision(10) << total << endl;

    return 0;
}