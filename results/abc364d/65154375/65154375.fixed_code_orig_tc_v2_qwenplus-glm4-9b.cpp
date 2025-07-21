#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;

// Point structure to store coordinates
struct Point {
    int a, k;
};

// Sort function for points
bool comp(const Point &p1, const Point &p2) {
    return p1.a < p2.a;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<Point> points_a(n);
    vector<int> distances;

    // Read points A and sort them
    for (int i = 0; i < n; ++i) {
        cin >> points_a[i].a;
        points_a[i].k = i + 1; // Store k_j for each point
    }
    sort(points_a.begin(), points_a.end(), comp);

    // Process each query
    for (int j = 0; j < q; ++j) {
        int b, k_j;
        cin >> b >> k_j;
        k_j--; // Convert to 0-based index

        // Binary search to find the k_j-th closest point
        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (points_a[mid].k >= k_j) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // Calculate distance between the k_j-th closest point and B
        int distance = abs(points_a[ans].a - b);
        cout << distance << endl;
    }

    return 0;
}