#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    int N;
    long double nowX = 0, nowY = 0;
    long double nextX, nextY;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nextX >> nextY;
        long double dx = nowX - nextX;
        long double dy = nowY - nextY;
        cost += sqrtl(dx * dx + dy * dy);
        nowX = nextX;
        nowY = nextY;
    }

    // Return to origin from the last point
    cost += sqrtl(nowX * nowX + nowY * nowY);

    cout << fixed << setprecision(10) << cost << endl;

    return 0;
}