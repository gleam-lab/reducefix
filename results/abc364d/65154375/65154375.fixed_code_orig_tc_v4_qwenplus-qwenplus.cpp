#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the list of A's coordinates for binary search operations
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search to find the position in A where b would be inserted
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] < b)
                left = mid + 1;
            else
                right = mid - 1;
        }
        // Now `left` is the first index where A[left] >= b

        int l = left - 1, r = left;
        int count = 0;
        ll result = 0;

        // Use two pointers to find the k-th closest distance
        while (count < k) {
            if (l < 0) {
                r++;
                count++;
            } else if (r >= N) {
                l--;
                count++;
            } else if (abs(A[l] - b) <= abs(A[r] - b)) {
                l--;
                count++;
                if (count == k)
                    result = abs(A[l + 1] - b);
            } else {
                r++;
                count++;
                if (count == k)
                    result = abs(A[r - 1] - b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}