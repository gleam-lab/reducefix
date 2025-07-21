#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 100000000;  // To shift negative coordinates to positive indices
const int MAX_COORD = 200000001;  // Since range is [-1e8, 1e8] inclusive

// Coordinate compression helper
vector<long long> compressCoordinates(const vector<long long>& raw) {
    set<long long> uniqueCoords(raw.begin(), raw.end());
    vector<long long> sorted(uniqueCoords.begin(), uniqueCoords.end());
    return sorted;
}

// Binary search to find index in compressed array
int findIndex(const vector<long long>& arr, long long value) {
    return lower_bound(arr.begin(), arr.end(), value) - arr.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort A for binary search
    sort(A.begin(), A.end());

    // Process queries
    for (int q = 0; q < Q; ++q) {
        long long b;
        int k;
        cin >> b >> k;

        // Use binary search to find the closest point
        int left = 0, right = N - 1;
        int best_idx = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] <= b) {
                best_idx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Sliding window of size N with distances
        multiset<pair<long long, int>> kClosest;
        deque<long long> distances;

        // Initialize a sliding window
        for (int i = 0; i < N; ++i) {
            long long dist = abs(A[i] - b);
            distances.push_back(dist);
        }

        // Sort distances and pick k-th smallest
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}