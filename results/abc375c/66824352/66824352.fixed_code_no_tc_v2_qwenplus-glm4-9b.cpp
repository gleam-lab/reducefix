#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    double x = 0.0, y = 0.0, total_cost = 0.0;

    for (int i = 0; i < n; ++i) {
        int X, Y;
        cin >> X >> Y;
        total_cost += sqrt((X - x) * (X - x) + (Y - y));
        x = X;
        y = Y;
    }

    total_cost += sqrt(x * x + y * y);
    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}