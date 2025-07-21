#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Sort the points a
    sort(a.begin(), a.end());

    // Sort queries by b_j
    sort(queries.begin(), queries.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    });

    // Process each query
    for (const auto &q : queries) {
        int b = q.first;
        int k = q.second;

        // Binary search to find the k-th closest point to b
        int l = 0, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            float leftDist = mid == 0 ? numeric_limits<float>::max() : abs(a[mid - 1] - b);
            float rightDist = mid == n ? numeric_limits<float>::max() : abs(a[mid] - b);

            if (leftDist <= rightDist) {
                if (k <= n - mid) {
                    ans = mid - 1;
                    r = mid - 1;
                } else {
                    r = mid - 1;
                }
            } else {
                l = mid + 1;
                if (k <= mid) {
                    ans = mid;
                    l = mid;
                } else {
                    k -= mid;
                }
            }
        }

        // Output the distance between the k-th closest point and b
        cout << abs(a[ans] - b) << endl;
    }

    return 0;
}