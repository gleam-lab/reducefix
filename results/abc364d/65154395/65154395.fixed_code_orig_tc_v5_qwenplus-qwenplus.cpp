#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 1e8;
const int MAXN = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Coordinate compression for A values
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort A for binary search later
    sort(A.begin(), A.end());

    for (int i = 0; i < Q; ++i) {
        int b;
        int k;
        cin >> b >> k;

        // Binary search on distance
        int low = 0;
        int high = 2 * 1e8 + 5;
        int answer = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            // Count how many elements in A are within [b - mid, b + mid]
            int left = lower_bound(A.begin(), A.end(), b - mid) - A.begin();
            int right = upper_bound(A.begin(), A.end(), b + mid) - A.begin();
            if (right - left >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}