#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long double total_distance = 0.0;
    int prevX = 0, prevY = 0;

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        long double dx = X - prevX;
        long double dy = Y - prevY;
        total_distance += sqrtl(dx * dx + dy * dy);
        prevX = X;
        prevY = Y;
    }

    // Add the distance from the last point back to the origin
    long double dx = 0 - prevX;
    long double dy = 0 - prevY;
    total_distance += sqrtl(dx * dx + dy * dy);

    // Set precision to handle the output correctly
    cout << fixed << setprecision(15) << total_distance << endl;

    return 0;
}