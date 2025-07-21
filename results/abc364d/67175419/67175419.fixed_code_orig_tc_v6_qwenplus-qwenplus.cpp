#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];

// Binary search to find the k-th smallest distance
int64_t findKthDistance(int N, int Q, int64_t b, int k) {
    // Create a copy of the sorted array and shift by b
    int64_t* diffs = new int64_t[N];
    for (int i = 0; i < N; ++i) {
        diffs[i] = abs(a[i] - b);
    }
    sort(diffs, diffs + N);
    int64_t result = diffs[k - 1];
    delete[] diffs;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a, a + N);

    for (int query = 0; query < Q; ++query) {
        int64_t b;
        int k;
        cin >> b >> k;

        // Binary search on the sorted A array to find nearby elements efficiently
        int idx = lower_bound(a, a + N, b) - a;

        // Use two pointers around the closest elements
        int left = max(0, idx - k);
        int right = min(N - 1, idx + k);

        // Extract subarray and compute distances
        vector<int64_t> distances;
        for (int i = left; i <= right; ++i) {
            distances.push_back(abs(a[i] - b));
        }

        // Sort distances and get the k-th smallest
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << "\n";
    }

    return 0;
}