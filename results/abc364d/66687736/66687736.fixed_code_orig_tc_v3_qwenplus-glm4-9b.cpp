#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<pair<int, int>> points(n + q); // Pair of coordinate and original index
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first;
        points[i].second = i; // Original index of point A_i
    }
    for (int i = 0; i < q; ++i) {
        cin >> points[n + i].first >> points[n + i].second;
        points[n + i].second = n + i; // Original index of point B_i
    }

    // Sort points by coordinate
    sort(points.begin(), points.end());

    for (int i = 0; i < q; ++i) {
        int k = points[n + i].second - n + 1; // Convert query index to 1-based
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (points[mid].second < n) {
                left = mid + 1;
            } else {
                if (mid == 0 || points[mid - 1].second >= n) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
        }
        int dist = points[left].first - points[n + i].first;
        cout << dist << endl;
    }

    return 0;
}