#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double euclidean_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int N;
    cin >> N;
    
    vector<double> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }
    
    double total_cost = 0.0;
    // Add the distance from the origin to the first point
    total_cost += euclidean_distance(0, 0, X[0], Y[0]);
    
    // Add the distances between consecutive points
    for (int i = 0; i < N - 1; ++i) {
        total_cost += euclidean_distance(X[i], Y[i], X[i + 1], Y[i + 1]);
    }
    
    // Add the distance from the last point back to the origin
    total_cost += euclidean_distance(X[N - 1], Y[N - 1], 0, 0);
    
    // Print the total cost with fixed decimal precision
    cout << fixed << setprecision(12) << total_cost << endl;
    
    return 0;
}