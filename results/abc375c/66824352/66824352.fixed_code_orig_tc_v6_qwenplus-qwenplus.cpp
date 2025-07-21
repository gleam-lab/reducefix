#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    double total = 0.0;
    int prev_x = 0, prev_y = 0;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int dx = prev_x - x;
        int dy = prev_y - y;
        total += sqrt(static_cast<double>(dx) * dx + static_cast<double>(dy) * dy);
        prev_x = x;
        prev_y = y;
    }

    // Return to origin
    total += sqrt(static_cast<double>(prev_x) * prev_x + static_cast<double>(prev_y) * prev_y);

    cout << fixed << setprecision(15) << total << endl;
    return 0;
}