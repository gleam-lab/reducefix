#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_OFFSET = 200000000; // Offset to handle negative coordinates
const int MAX_COORD = 400000001; // Total range from -1e8 to 1e8 inclusive

int freq[MAX_COORD]; // frequency array for each coordinate after offsetting

// Binary search for the smallest distance that has at least k elements within it
ll find_kth_smallest_distance(int b, int k) {
    int left = 0;
    int right = MAX_OFFSET; // max possible distance is 2e8
    while (left < right) {
        int mid = (left + right) / 2;
        int total = 0;
        // Count how many points are within distance mid from b
        int low = max(0, b - mid + MAX_OFFSET);
        int high = min(MAX_COORD - 1, b + mid + MAX_OFFSET);
        if (low == 0) {
            total = freq[high];
        } else {
            total = freq[high] - freq[low - 1];
        }
        if (total >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize frequency array
    fill(freq, freq + MAX_COORD, 0);

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        freq[a + MAX_OFFSET]++;
    }

    // Build prefix sum of frequencies
    for (int i = 1; i < MAX_COORD; ++i) {
        freq[i] += freq[i - 1];
    }

    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_smallest_distance(b, k) << "\n";
    }
}

int main() {
    solve();
    return 0;
}