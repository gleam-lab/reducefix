#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double total_distance = 0.0;
    long long prev_x = 0, prev_y = 0;
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        long long dx = x - prev_x;
        long long dy = y - prev_y;
        total_distance += sqrt(dx * dx + dy * dy);
        prev_x = x;
        prev_y = y;
    }
    total_distance += sqrt(prev_x * prev_x + prev_y * prev_y);
    cout << fixed << setprecision(15) << total_distance << endl;
    return 0;
}