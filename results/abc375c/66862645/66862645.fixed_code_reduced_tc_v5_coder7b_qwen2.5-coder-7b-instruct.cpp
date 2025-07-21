#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int N;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nextX >> nextY;

        // Calculate the Euclidean distance squared to avoid computing square roots multiple times
        long double dx = nowX - nextX;
        long double dy = nowY - nextY;
        cost = dx * dx + dy * dy;

        ans += sqrtl(cost);  // Take the square root of the squared distance

        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    cost = nowX * nowX + nowY * nowY;
    ans += sqrtl(cost);

    cout << fixed << setprecision(10) << ans << endl;  // Print with high precision

    return 0;
}