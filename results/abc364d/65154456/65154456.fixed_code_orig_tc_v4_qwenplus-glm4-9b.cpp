#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(q), k(q);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> b[i] >> k[i];
    }

    // Sort points A and B together with their indices
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        points.emplace_back(a[i], i);
    }
    for (int i = 0; i < q; i++) {
        points.emplace_back(b[i], n + i);
    }
    sort(points.begin(), points.end());

    // Map original indices to their new positions
    vector<int> idx(n + q);
    for (int i = 0, j = 0; i < n + q; i++) {
        idx[i] = j++;
    }
    sort(idx.begin(), idx.begin() + n);

    // Find the k-th closest points
    for (int i = 0; i < q; i++) {
        // Get the original index of the k-th closest point
        int ai = points[idx[n + i] - 1].second;
        // Calculate the distance
        int distance = abs(a[ai] - b[i]);
        cout << distance << endl;
    }

    return 0;
}