#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    long double cost = 0;
    long double nowX = 0, nowY = 0;

    for (int i = 0; i < N; ++i) {
        long double nextX, nextY;
        cin >> nextX >> nextY;

        cost += sqrtl((nowX - nextX) * (nowX - nextX) + (nowY - nextY) * (nowY - nextY));

        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    cost += sqrtl(nowX * nowX + nowY * nowY);

    cout << fixed << setprecision(10) << cost << endl;

    return 0;
}