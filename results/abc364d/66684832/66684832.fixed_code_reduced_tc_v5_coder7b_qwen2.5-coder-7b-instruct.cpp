#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

struct Point {
    ll coord;
    int index;
};

// Comparator function to sort points based on their coordinates
bool compare(const Point &p1, const Point &p2) {
    return p1.coord < p2.coord;
}

// Function to find the k-th closest point
ll findKthClosest(vector<Point> &points, int k, ll target) {
    // Separate points into left and right of the target
    vector<Point> left, right;
    for (auto &point : points) {
        if (point.coord < target) left.push_back(point);
        else right.push_back(point);
    }

    // Calculate distances to the target
    vector<ll> distances(left.size());
    for (size_t i = 0; i < left.size(); ++i) {
        distances[i] = abs(left[i].coord - target);
    }

    // Sort distances to find the k-th smallest
    sort(distances.begin(), distances.end());

    // Return the k-th smallest distance
    return distances[k - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> coords(n);
    for (int i = 0; i < n; ++i) {
        cin >> coords[i];
    }

    vector<Point> points;
    for (int i = 0; i < n; ++i) {
        points.push_back({coords[i], i});
    }

    sort(points.begin(), points.end(), compare);

    while (q--) {
        ll target;
        int k;
        cin >> target >> k;

        // Find the k-th closest point using binary search
        ll left = -1e9, right = 1e9;
        while (left < right) {
            ll mid = (left + right) / 2;
            if (findKthClosest(points, k, target + mid) <= mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << endl;
    }

    return 0;
}