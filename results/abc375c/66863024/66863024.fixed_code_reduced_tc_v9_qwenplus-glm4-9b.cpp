#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long double cost = 0.0;
    long long ox = 0, oy = 0; // Initial position at the origin

    // Calculate the total cost for visiting all points and returning to the origin
    for (int i = 0; i < N; ++i) {
        long long x = points[i].first, y = points[i].second;
        cost += sqrt((x - ox) * (x - ox) + (y - oy) * (y - oy));
        ox = x, oy = y;
    }
    cost += sqrt(ox * ox + oy * oy); // Return to the origin

    // Set precision for output
    cout << fixed << setprecision(12);
    cout << cost << endl;

    return 0;
}