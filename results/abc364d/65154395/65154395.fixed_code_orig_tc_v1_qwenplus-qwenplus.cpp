#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 1e8; // Offset to handle negative indices in the frequency array

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Coordinate compression is not needed since we can use a frequency array directly
    const int MAX_COORD = 2 * 1e8 + 5; // From -1e8 to 1e8 => total size ~2e8
    long long freq[2 * 1e8 + 10] = {0}; // Use large enough static array

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        freq[x + OFFSET]++;
    }

    // Prefix sum to allow range count queries
    long long prefix[2 * 1e8 + 10];
    prefix[0] = freq[0];
    for (long long i = 1; i <= 2 * 1e8; ++i) {
        prefix[i] = prefix[i - 1] + freq[i];
    }

    while (Q--) {
        int b, k;
        cin >> b >> k;

        // Binary search on distance d
        int left = 0, right = 2 * 1e8;
        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            int low = max(0, b + OFFSET - mid);
            int high = min((int)(2 * 1e8), b + OFFSET + mid);

            long long cnt = prefix[high] - (low > 0 ? prefix[low - 1] : 0);

            if (cnt >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}