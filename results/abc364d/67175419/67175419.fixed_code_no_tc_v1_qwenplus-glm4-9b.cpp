#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q;
int a[N], b[N], k[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < q; ++j) {
        cin >> b[j] >> k[j];
    }

    // Pair each b[j] with its corresponding k[j] and sort by b[j]
    pair<int, int> pairs[N];
    for (int i = 0; i < q; ++i) {
        pairs[i] = {b[i] - a[0], k[i] - 1}; // subtract a[0] to make k-th closest calculation easier
    }
    sort(pairs, pairs + q);

    // Calculate distances for each b[j] after sorting by b[j]
    for (int j = 0; j < q; ++j) {
        int l = 0, r = n - 1;
        // Binary search to find the k-th closest
        while (l <= r) {
            int mid = (l + r) / 2;
            if (abs(a[mid] - b[j]) <= pairs[j].first) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // Calculate the distance to the k-th closest point
        int closest_index = r;
        int distance = abs(a[closest_index] - b[j]);
        cout << distance << '\n';
    }

    return 0;
}