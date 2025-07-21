#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_OFFSET = 2e8;
const int MAX_A = 2 * MAX_OFFSET + 10; // To safely index a_i in range [-1e8, 1e8]

int countLeft[MAX_A];   // Count of points to the left (including current)
int countRight[MAX_A];  // Count of points to the right (including current)

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // Precompute prefix counts for binary search
    vector<int> prefix(MAX_A, 0);
    for (ll a : A) {
        int idx = a + MAX_OFFSET;
        prefix[idx]++;
    }

    // Build prefix sum
    for (int i = 1; i < MAX_A; ++i) {
        prefix[i] += prefix[i - 1];
    }

    // Process queries
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search on answer: distance d such that there are at least k points within distance d
        int low = 0;
        int high = 2e8;
        int answer = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            ll leftPos = b - mid;
            ll rightPos = b + mid;

            // Find how many A[i] are in [leftPos, rightPos]
            int l = lower_bound(A.begin(), A.end(), leftPos) - A.begin();
            int r = upper_bound(A.begin(), A.end(), rightPos) - A.begin();

            int cnt = r - l;

            if (cnt >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << "\n";
    }
}

int main() {
    solve();
    return 0;
}