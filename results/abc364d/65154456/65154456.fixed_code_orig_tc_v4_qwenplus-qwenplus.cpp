#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int OFFSET = 100000000;  // To handle negative indices
const int MAX_COORD = 200000000 + 5;  // Since range is [-1e8, 1e8]

int freq[MAX_COORD * 2 + 5];  // Frequency array for counting sort

// Binary search to find the k-th smallest distance from b
ll findKthDistance(int b_offset, int k) {
    int l = 0, r = MAX_COORD;
    while (l < r) {
        int mid = (l + r) / 2;
        // Count how many points are within distance <= mid from b_offset
        int left_idx = max(0, b_offset - mid + OFFSET);
        int right_idx = min(MAX_COORD * 2, b_offset + mid + OFFSET);
        int count = freq[right_idx] - freq[left_idx - 1];
        if (count >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize frequency array
    fill(freq, freq + MAX_COORD * 2 + 2, 0);

    // Read A coordinates and build frequency array
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        freq[a + OFFSET]++;
    }

    // Build prefix sum
    for (int i = 1; i <= MAX_COORD * 2; ++i) {
        freq[i] += freq[i - 1];
    }

    // Process queries
    for (int i = 0; i < Q; ++i) {
        int b;
        int k;
        cin >> b >> k;
        int b_offset = b + OFFSET;
        cout << findKthDistance(b_offset, k) << "\n";
    }

    return 0;
}