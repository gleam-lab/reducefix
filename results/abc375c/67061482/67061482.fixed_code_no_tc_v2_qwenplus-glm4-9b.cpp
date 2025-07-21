#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double a = 0.0, b = 0.0, x, y, cost = 0.0;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        cost += sqrt((a - x) * (a - x) + (b - y) * (b - y));
        a = x;
        b = y;
    }

    // Add the cost from the last point to the origin
    cost += sqrt(a * a + b * b);

    cout << fixed << setprecision(10) << cost << endl;

    return 0;
}