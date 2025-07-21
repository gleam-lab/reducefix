#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 100000000; // Offset to handle negative coordinates
const int MAX_COORD = 200000001; // Range from -1e8 to 1e8

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> count(MAX_COORD, 0);

    // Read A points and update frequency count
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        count[a + OFFSET]++;
    }

    // Build prefix sum of counts
    vector<long long> prefix(MAX_COORD + 1, 0);
    for (int i = 0; i < MAX_COORD; ++i) {
        prefix[i + 1] = prefix[i] + count[i];
    }

    // Process each query using binary search
    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;

        // Binary search on distance d
        int left = 0, right = 200000000; // Max possible distance is 2e8
        int answer = right;

        while (left <= right) {
            int mid = (left + right) / 2;

            // Count number of points within distance mid of b
            int low = max(-100000000, b - mid);
            int high = min(100000000, b + mid);

            int cnt = prefix[high + OFFSET + 1] - prefix[low + OFFSET];

            if (cnt >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}