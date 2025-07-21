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
        long double cost = sqrt(powl(nowX - nextX, 2.0) + powl(nowY - nextY, 2.0));
        total_cost += cost;
        nowX = nextX;
        nowY = nextY;
    }

    // Add the cost to return to the origin
    long double return_cost = sqrt(powl(nowX - 0, 2.0) + powl(nowY - 0, 2.0));
    total_cost += return_cost;

    cout << fixed << setprecision(15) << total_cost << endl;

    return 0;
}