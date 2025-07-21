#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    cin >> N;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    for (int i = 0; i < N; ++i) {
        cin >> nextX >> nextY;
        long double dx = nowX - nextX;
        long double dy = nowY - nextY;
        long double distance = sqrt(dx * dx + dy * dy);
        total_cost += distance;
        nowX = nextX;
        nowY = nextY;
    }

    long double dx = nowX - 0;
    long double dy = nowY - 0;
    long double distance = sqrt(dx * dx + dy * dy);
    total_cost += distance;

    cout << fixed << setprecision(20) << total_cost << endl;

    return 0;
}