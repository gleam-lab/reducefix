#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double distance(const pair<int, int>& p1, const pair<int, int>& p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_distance = 0;
    for(int i = 0; i < n - 1; ++i) {
        total_distance += distance(points[i], points[i+1]);
    }

    // Return to origin
    total_distance += distance(points[n-1], {0, 0});

    cout << fixed << setprecision(10) << total_distance << endl;
    return 0;
}