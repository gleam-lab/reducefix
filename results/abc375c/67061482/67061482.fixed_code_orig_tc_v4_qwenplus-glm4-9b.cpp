#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N+2); // +2 for starting and ending at the origin

    // Precompute the squared distances between consecutive points
    vector<long long> distances(N+1, 0); // +1 because we need the distance between the last point and origin as well

    // Read points and calculate distances
    points[0] = {0, 0}; // Starting at the origin
    for (int i = 1; i <= N; ++i) {
        cin >> points[i].first >> points[i].second;
        distances[i] = (long long)(pow(points[i].first - points[i-1].first, 2) + 
                                   pow(points[i].second - points[i-1].second, 2));
    }
    distances[N+1] = (long long)(pow(points[N].first - 0, 2) + 
                                  pow(points[N].second - 0, 2)); // Distance from the last point back to the origin

    // Sum up all distances and take the square root of the sum
    long long total_squared_distance = 0;
    for (int i = 1; i <= N+1; ++i) {
        total_squared_distance += distances[i];
    }
    double total_distance = sqrt(total_squared_distance);

    cout.precision(10);
    cout << fixed << total_distance << endl;

    return 0;
}