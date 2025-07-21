#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) {
        cin >> a;
        K -= a;
    }

    // Create index array sorted by A[i]
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return A[i] < A[j]; });

    // Create sorted version of A
    vector<ll> B = A;
    sort(all(B));

    // Binary search for each candidate
    vector<ll> res(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0, high = K + 1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = A[i] + mid;

            // We want to find the M candidates that would have more votes than i
            // if we don't give it mid. Then calculate how many votes needed to beat them.
            // Use binary search to find the right position in sorted array
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (B[m] >= target)
                    right = m;
                else
                    left = m + 1;
            }
            int pos = left;

            // Need to make sure at least (N-M) candidates have <= our value
            // So we need to raise the worst (M) candidates below us
            int need_to_raise = max(0, N - (pos + 1) - M + 1);

            ll total_needed = 0;
            for (int j = pos - 1; j >= max(0, pos - need_to_raise); --j) {
                total_needed += (target - B[j]);
                if (total_needed > K) break;
            }

            if (total_needed <= K && mid <= K) {
                res[i] = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    for (ll x : res) cout << (x <= K ? x : -1) << " ";
    cout << "\n";
}