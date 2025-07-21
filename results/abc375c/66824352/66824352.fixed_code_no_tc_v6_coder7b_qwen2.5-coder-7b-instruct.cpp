#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    double c = 0.0;
    cin >> n;
    vector<pair<int, int>> points(n);
    
    // Read all points
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total distance
    for (int i = 0; i < n; ++i) {
        c += sqrt(pow(points[i].first, 2) + pow(points[i].second, 2));
        if (i > 0) {
            c += sqrt(pow(points[i].first - points[i-1].first, 2) + pow(points[i].second - points[i-1].second, 2));
        }
    }
    c += sqrt(pow(points[0].first, 2) + pow(points[0].second, 2));

    // Output the result with precision up to 10 decimal places
    cout << fixed << setprecision(10) << c << endl;

    return 0;
}