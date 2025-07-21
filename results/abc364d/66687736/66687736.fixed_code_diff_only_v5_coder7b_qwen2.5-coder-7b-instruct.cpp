#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    vector<pair<ll, int>> queries(q);

    // Read coordinates of points A_i
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Read coordinates of points B_j and corresponding k_j
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].second--; // Adjusting to zero-based index
    }

    // Sort points A_i
    sort(a.begin(), a.end());

    // Answer each query
    for (auto& query : queries) {
        ll b = query.first;
        int k = query.second;

        // Binary search to find the k-th smallest distance
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (abs(a[mid] - b) >= abs(a[left] - b)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Check the distances around the found position
        int dist = abs(a[left] - b);
        if (left > 0 && abs(a[left - 1] - b) < dist) {
            dist = abs(a[left - 1] - b);
        }
        if (left < n - 1 && abs(a[left + 1] - b) < dist) {
            dist = abs(a[left + 1] - b);
        }

        cout << dist << '\n';
    }

    return 0;
}