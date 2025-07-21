#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N + 1);

    // Initialize first point as the origin
    points[0] = {0, 0};

    // Read the coordinates of the points
    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the cost for each move and accumulate the total cost
    long double total_cost = 0.0;
    for (int i = 0; i <= N; ++i) {
        int a = points[i].first;
        int b = points[i].second;
        int c = points[i + 1].first;
        int d = points[i + 1].second;
        total_cost += sqrt(pow(a - c, 2) + pow(b - d, 2));
    }

    // Output the total cost
    cout.precision(15);
    cout << fixed << total_cost << endl;

    return 0;
}