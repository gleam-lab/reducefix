#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nextX >> nextY;
        long double dx = nowX - nextX;
        long double dy = nowY - nextY;
        total_cost += sqrtl(dx * dx + dy * dy);
        nowX = nextX;
        nowY = nextY;
    }

    // Add distance back to origin
    long double dx = nowX;
    long double dy = nowY;
    total_cost += sqrtl(dx * dx + dy * dy);

    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}