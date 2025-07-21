#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double total = 0.0;
    long long prev_x = 0, prev_y = 0;

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        long long dx = x - prev_x;
        long long dy = y - prev_y;
        total += sqrt(static_cast<double>(dx * dx + dy * dy));
        prev_x = x;
        prev_y = y;
    }

    // Return to origin
    total += sqrt(static_cast<double>(prev_x * prev_x + prev_y * prev_y));

    cout << fixed << setprecision(15) << total << endl;
    return 0;
}