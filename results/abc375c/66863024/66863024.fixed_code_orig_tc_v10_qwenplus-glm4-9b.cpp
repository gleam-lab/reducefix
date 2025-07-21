#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N == 0) {
        // If there are no points, the cost is 0.
        cout << 0 << endl;
        return 0;
    }

    long long x, y;
    long long originX = 0, originY = 0;
    long long totalCost = 0;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        totalCost += sqrt((x - originX) * (x - originX) + (y - originY) * (y - originY));
        originX = x;
        originY = y;
    }

    // Add the distance from the last point back to the origin.
    totalCost += sqrt((x - originX) * (x - originX) + (y - originY) * (y - originY));

    cout << totalCost << endl;
    return 0;
}