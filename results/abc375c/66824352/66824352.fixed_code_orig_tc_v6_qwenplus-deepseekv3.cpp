#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double total_cost = 0.0;
    double prev_x = 0.0, prev_y = 0.0;

    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        double dx = x - prev_x;
        double dy = y - prev_y;
        total_cost += sqrt(dx * dx + dy * dy);
        prev_x = x;
        prev_y = y;
    }

    // Return to origin
    double dx = 0.0 - prev_x;
    double dy = 0.0 - prev_y;
    total_cost += sqrt(dx * dx + dy * dy);

    cout << fixed << setprecision(15) << total_cost << endl;
    return 0;
}