#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int operation;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> operation;

    for (int i = 0; i < operation; i++) {
        cin >> nextX >> nextY;

        // Calculate Euclidean distance correctly
        cost = sqrt(pow(nextX - nowX, 2.0) + pow(nextY - nowY, 2.0));

        nowX = nextX;
        nowY = nextY;

        ans += cost;
    }

    // Return to the origin
    cost = sqrt(pow(nowX, 2.0) + pow(nowY, 2.0));
    ans += cost;

    cout << ans << endl;

    return 0;
}