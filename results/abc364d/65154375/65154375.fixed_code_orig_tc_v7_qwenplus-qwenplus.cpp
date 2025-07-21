#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_OFFSET = 200000000;
const int TOTAL_SIZE = 2 * MAX_OFFSET + 10; // Sufficient for the problem

int freq[TOTAL_SIZE];

// Coordinate compression utility
int getIdx(ll val) {
    return (int)(val + MAX_OFFSET);
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    // Initialize frequency array to zero
    memset(freq, 0, sizeof(freq));
    
    // Read A points and update frequency
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        int idx = getIdx(a);
        freq[idx]++;
    }
    
    // Build prefix sum of frequencies
    int prefix[N + 2]; // Since we can't have more than N unique distances
    int sorted_a[N];
    int pos = 0;
    for (int i = 0; i < TOTAL_SIZE; ++i) {
        if (freq[i] > 0) {
            sorted_a[pos++] = i - MAX_OFFSET;
        }
    }

    // Process each query
    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;

        // Binary search on the distance d
        int left = 0;
        int right = MAX_OFFSET + MAX_OFFSET;

        while (left < right) {
            int mid = (left + right) / 2;
            int total = 0;
            // Find all points in [b - mid, b + mid]
            int l = lower_bound(sorted_a, sorted_a + pos, b - mid) - sorted_a;
            int r = upper_bound(sorted_a, sorted_a + pos, b + mid) - sorted_a;
            total = r - l;

            if (total >= k)
                right = mid;
            else
                left = mid + 1;
        }

        cout << left << '\n';
    }
}