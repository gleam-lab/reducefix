#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> points;
    double x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        double px, py;
        cin >> px >> py;
        points.emplace_back(px, py);
        x += px;
        y += py;
    }

    // Calculate total distance by considering the convex hull
    // of all points including the origin
    vector<pair<double, double>> hull;
    auto cross_product = [](const pair<double, double>& O, const pair<double, double>& A, const pair<double, double>& B) {
        return (A.first - O.first) * (B.second - O.second) - (B.first - O.first) * (A.second - O.second);
    };

    // Sort points based on x and y coordinates
    sort(points.begin(), points.end());

    // Lower hull
    for (auto p : points) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull[hull.size() - 1], p) <= 0) {
            hull.pop_back();
        }
        hull.emplace_back(p);
    }

    // Upper hull
    for (auto it = points.rbegin(); it != points.rend(); it++) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull[hull.size() - 1], *it) <= 0) {
            hull.pop_back();
        }
        hull.emplace_back(*it);
    }

    // Remove duplicates
    hull.pop_back();

    // Calculate the total distance
    double total_distance = 0;
    for (int i = 1; i < hull.size(); i++) {
        total_distance += sqrt(pow(hull[i].first - hull[i - 1].first, 2) + pow(hull[i].second - hull[i - 1].second, 2));
    }
    total_distance += sqrt(pow(hull[0].first - hull[hull.size() - 1].first, 2) + pow(hull[0].second - hull[hull.size() - 1].second, 2));

    cout << fixed << setprecision(10) << total_distance << endl;

    return 0;
}