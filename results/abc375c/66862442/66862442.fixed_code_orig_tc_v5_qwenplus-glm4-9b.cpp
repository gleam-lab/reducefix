#include <iostream>
#include <cmath> // For sqrt and pow
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;
    double total = 0; // Use double precision for the final result

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        // Calculate the Euclidean distance from the current position to the next point
        total += sqrt(pow(curX - x, 2) + pow(curY - y, 2));

        // Update the current position
        curX = x;
        curY = y;
    }

    // Add the distance from the last point to the origin to the total
    total += sqrt(pow(curX, 2) + pow(curY, 2));

    // Print the total distance with a precision of at least 10^-6
    cout.precision(10);
    cout << fixed << total << endl;

    return 0;
}