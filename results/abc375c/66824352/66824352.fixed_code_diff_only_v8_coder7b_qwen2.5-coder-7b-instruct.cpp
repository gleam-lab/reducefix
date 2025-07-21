#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    double c = 0;
    cin >> n;
    vector<pair<int, int>> points(n);
    
    // Read all points into a vector for easier management
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the cost of moving from one point to another
    for (size_t i = 0; i < n - 1; ++i) {
        c += sqrt(pow(points[i].first - points[i + 1].first, 2) + pow(points[i].second - points[i + 1].second, 2));
    }

    // Add the cost of returning to the origin
    c += sqrt(pow(points[n - 1].first, 2) + pow(points[n - 1].second, 2));

    cout << setprecision(10) << c << endl;
    return 0;
}