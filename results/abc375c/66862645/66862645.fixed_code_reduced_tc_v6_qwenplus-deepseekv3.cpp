#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long double total_cost = 0;
    int N;
    cin >> N;
    int prevX = 0, prevY = 0;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        long double dx = X - prevX;
        long double dy = Y - prevY;
        total_cost += sqrtl(dx * dx + dy * dy);
        prevX = X;
        prevY = Y;
    }

    // Add the distance from the last point back to the origin
    long double dx = 0 - prevX;
    long double dy = 0 - prevY;
    total_cost += sqrtl(dx * dx + dy * dy);

    cout << fixed << setprecision(15) << total_cost << endl;

    return 0;
}