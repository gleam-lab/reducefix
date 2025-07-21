#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    double total = 0.0;

    cin >> n;

    // Starting point is (0, 0)
    long long curr_x = 0, curr_y = 0;

    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < n; ++i) {
        long long next_x = points[i].first;
        long long next_y = points[i].second;
        double dx = static_cast<double>(next_x - curr_x);
        double dy = static_cast<double>(next_y - curr_y);
        total += sqrt(dx * dx + dy * dy);
        curr_x = next_x;
        curr_y = next_y;
    }

    // Return to origin
    double dx = static_cast<double>(0 - curr_x);
    double dy = static_cast<double>(0 - curr_y);
    total += sqrt(dx * dx + dy * dy);

    cout << fixed << setprecision(15) << total << endl;

    return 0;
}