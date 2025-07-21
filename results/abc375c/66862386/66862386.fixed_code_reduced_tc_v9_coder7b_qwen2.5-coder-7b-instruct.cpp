#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long N;
    cin >> N;

    long long x = 0, y = 0;
    long long total_cost = 0;

    for(long long i = 0; i < N; ++i) {
        long long next_x, next_y;
        cin >> next_x >> next_y;

        // Calculate Euclidean distance from current position to the next point
        long long dx = next_x - x;
        long long dy = next_y - y;
        total_cost += sqrt(dx * dx + dy * dy);

        // Update current position
        x = next_x;
        y = next_y;
    }

    // Return to the origin
    total_cost += sqrt(x * x + y * y);

    cout << total_cost << endl;

    return 0;
}