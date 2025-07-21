#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0.0, curY = 0.0;
    double total = 0.0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);

        curX = x; curY = y;
    }
    total += sqrt(curX * curX + curY * curY); // Return to the origin

    // Set precision for output
    cout << fixed << setprecision(7) << total << '\n';

    return 0;
}