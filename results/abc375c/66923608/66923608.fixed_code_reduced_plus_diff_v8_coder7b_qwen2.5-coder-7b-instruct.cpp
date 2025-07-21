#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double euclidean_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    // Calculate the total distance
    double total_distance = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_distance += euclidean_distance(x[i], y[i], x[i + 1], y[i + 1]);
    }
    // Return to the starting point
    total_distance += euclidean_distance(x[n - 1], y[n - 1], x[0], y[0]);

    // Output the result with high precision
    cout << fixed << setprecision(12) << total_distance << endl;

    return 0;
}