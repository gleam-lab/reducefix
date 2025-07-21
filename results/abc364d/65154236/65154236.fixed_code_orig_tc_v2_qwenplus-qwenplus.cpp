#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 1e8;
const int MAX_COORD = 2 * (int)1e8 + 1;

int freq[MAX_COORD + 5]; // Frequency array for counting sort

// Binary search to find the k-th smallest distance
int findKthDistance(int target, int k, const vector<int>& prefixSum) {
    int left = 0;
    int right = MAX_COORD;
    while (left < right) {
        int mid = (left + right) / 2;
        int total = 0;
        int low = max(0, target - mid);
        int high = min(MAX_COORD, target + mid);
        if (low > 0)
            total = prefixSum[high] - prefixSum[low - 1];
        else
            total = prefixSum[high];

        if (total >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize frequency array
    fill(freq, freq + MAX_COORD + 1, 0);

    // Read A coordinates and update frequency
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        freq[a + OFFSET]++;
    }

    // Build prefix sum array
    vector<int> prefixSum(MAX_COORD + 1);
    prefixSum[0] = freq[0];
    for (int i = 1; i <= MAX_COORD; ++i) {
        prefixSum[i] = prefixSum[i - 1] + freq[i];
    }

    // Process each query
    for (int i = 0; i < Q; ++i) {
        int b, k;
        cin >> b >> k;
        int pos = b + OFFSET;
        int result = findKthDistance(pos, k, prefixSum);
        cout << result << "\n";
    }

    return 0;
}