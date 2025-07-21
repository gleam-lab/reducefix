#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long x = 0, y = 0, total_cost = 0;

    for (int i = 0; i < N; ++i) {
        int cx, cy;
        cin >> cx >> cy;
        // Use Manhattan distance for the cost calculation
        total_cost += abs(x - cx) + abs(y - cy);
        x = cx;
        y = cy;
    }

    // If the last point is not the origin, calculate the distance to the origin
    if (N > 0) {
        int cx, cy;
        cin >> cx >> cy;
        total_cost += abs(x - cx) + abs(y - cy);
    }

    cout << total_cost << endl;
    return 0;
}