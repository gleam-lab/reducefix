#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long sumX = 0, sumY = 0; // cumulative sum of coordinates
    long long totalDistance = 0;  // total distance traveled

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        // Calculate the distance from the previous point (sumX, sumY) to the current point (x, y)
        totalDistance += (x * x - sumX * x + (y * y - sumY * y));
        
        // Update the cumulative sums of coordinates
        sumX += x;
        sumY += y;
    }

    // Output the total distance as a string to handle large numbers
    cout << totalDistance << endl;

    return 0;
}