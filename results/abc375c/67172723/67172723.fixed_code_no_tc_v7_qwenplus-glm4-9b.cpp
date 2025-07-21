#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    double px = 0.0, py = 0.0, total_cost = 0.0;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        total_cost += hypot(x - px, y - py);
        px = x;
        py = y;
    }

    // Add the cost to return to origin
    total_cost += hypot(px, py);

    cout.precision(10);
    cout << fixed << total_cost << endl;

    return 0;
}