#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double cost = 0.0;
    for (int i = 1; i < N; ++i) {
        double dx = points[i].first - points[i - 1].first;
        double dy = points[i].second - points[i - 1].second;
        cost += sqrt(dx * dx + dy * dy);
    }

    // Calculate the distance from the last point to the origin
    double dx = 0 - points[N - 1].first;
    double dy = 0 - points[N - 1].second;
    cost += sqrt(dx * dx + dy * dy);

    // Output the total cost with precision up to 10^-9
    cout << fixed << setprecision(9) << cost << endl;

    return 0;
}