#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
    int b, k;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        // For each element, store its position in sorted order
        pos[i].push_back(a[i]);
        pos[i].push_back(i);
    }
    sort(pos.begin(), pos.end());

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].b >> queries[i].k;
    }

    // Precompute the prefix sums of positions for binary search
    vector<vector<int>> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i].push_back(pos[i - 1][1]);  // Position
        prefix[i].push_back(i);              // Count of elements up to this position
        if (i > 1) {
            prefix[i].push_back(prefix[i - 1].back());  // Total elements from beginning to this position
        }
    }

    for (const auto& query : queries) {
        int b = query.b, k = query.k;
        // Binary search for the k-th closest point
        int l = 0, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            // Calculate the position of the k-th closest point to b
            int count = (prefix[m + 1][1] - prefix[m][1]);
            if (count >= k) {
                r = m;
            } else {
                l = m;
            }
        }

        int closest_index = r;
        // Calculate the distance to the k-th closest point
        int distance = abs(a[closest_index] - b);
        cout << distance << endl;
    }

    return 0;
}