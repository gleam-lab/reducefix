#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        // If there are no points, the total cost is 0
        cout << 0 << endl;
        return 0;
    }

    double x = 0, y = 0, total_cost = 0.0;

    for (int i = 0; i < n; ++i) {
        int X, Y;
        cin >> X >> Y;
        total_cost += sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
        x = X;
        y = Y;
    }

    // Add the distance from the last point back to the origin
    total_cost += sqrt((x - 0) * (x - 0) + (y - 0) * (y - 0));

    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}